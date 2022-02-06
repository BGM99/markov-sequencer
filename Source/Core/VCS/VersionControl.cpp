/*
    This file is part of Helio Workstation.

    Helio is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Helio is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Helio. If not, see <http://www.gnu.org/licenses/>.
*/

#include "Common.h"
#include "VersionControl.h"
#include "VersionControlEditor.h"
#include "Network.h"
#include "ProjectSyncService.h"

VersionControl::VersionControl(VCS::TrackedItemsSource &parent) :
    parent(parent),
    head(parent),
    stashes(new VCS::StashesRepository()),
    rootRevision(new VCS::Revision(TRANS(I18n::Defaults::newProjectFirstCommit)))
{
    MessageManagerLock lock;
    this->addChangeListener(&this->head);
    this->head.moveTo(this->rootRevision);
}

VersionControl::~VersionControl()
{
    MessageManagerLock lock;
    this->removeChangeListener(&this->head);
}

VersionControlEditor *VersionControl::createEditor()
{
    return new VersionControlEditor(*this);
}

//===----------------------------------------------------------------------===//
// VCS
//===----------------------------------------------------------------------===//

void VersionControl::moveHead(const VCS::Revision::Ptr revision)
{
    if (! revision->isEmpty())
    {
        this->head.moveTo(revision);
        this->sendChangeMessage();
    }
}

void VersionControl::checkout(const VCS::Revision::Ptr revision)
{
    if (! revision->isEmpty())
    {
        this->head.moveTo(revision);
        this->head.checkout();
        this->sendChangeMessage();
    }
}

void VersionControl::cherryPick(const VCS::Revision::Ptr revision, const Array<Uuid> uuids)
{
    if (! revision->isEmpty())
    {
        auto headRevision(this->head.getHeadingRevision());
        this->head.moveTo(revision);
        this->head.cherryPick(uuids);
        this->head.moveTo(headRevision);
        this->sendChangeMessage();
    }
}

void VersionControl::replaceHistory(const VCS::Revision::Ptr root)
{
    // if parent revision id is empty, this is the root revision
    // which means we're cloning project and replacing stub root with valid one:
    DBG("Replacing history tree");
    this->rootRevision = root;
    // make sure head doesn't point to replaced revision:
    this->head.moveTo(this->rootRevision);
    this->sendChangeMessage();
}

void VersionControl::appendSubtree(const VCS::Revision::Ptr subtree, const String &appendRevisionId)
{
    jassert(appendRevisionId.isNotEmpty());
    if (auto targetRevision = this->getRevisionById(this->rootRevision, appendRevisionId))
    {
        targetRevision->addChild(subtree);
        this->sendChangeMessage();
    }
}

VCS::Revision::Ptr VersionControl::updateShallowRevisionData(const String &id, const SerializedData &data)
{
    if (auto revision = this->getRevisionById(this->rootRevision, id))
    {
        if (revision->isShallowCopy())
        {
            revision->deserializeDeltas(data);
            this->sendChangeMessage();
        }

        return revision;
    }

    return nullptr;
}

void VersionControl::quickAmendItem(VCS::TrackedItem *targetItem)
{
    // warning: this is not a fully-functional amend,
    // it is only used when a new tracked item is added to revision;
    // changes and deletions to committed items will not work:
    VCS::RevisionItem::Ptr revisionRecord(new VCS::RevisionItem(VCS::RevisionItem::Type::Added, targetItem));
    this->head.getHeadingRevision()->addItem(revisionRecord);
    this->head.moveTo(this->head.getHeadingRevision());
    this->sendChangeMessage();
}

bool VersionControl::resetChanges(SparseSet<int> selectedItems)
{
    if (selectedItems.size() == 0) { return false; }

    VCS::Revision::Ptr allChanges(this->head.getDiff());
    Array<VCS::RevisionItem::Ptr> changesToReset;

    for (int i = 0; i < selectedItems.size(); ++i)
    {
        const int index = selectedItems[i];
        if (index >= allChanges->getItems().size()) { return false; }
        if (auto *item = allChanges->getItems()[index].get())
        {
            changesToReset.add(item);
        }
    }

    return this->head.resetChanges(changesToReset);
}

bool VersionControl::resetAllChanges()
{
    VCS::Revision::Ptr allChanges(this->head.getDiff());
    Array<VCS::RevisionItem::Ptr> changesToReset;

    for (auto *item : allChanges->getItems())
    {
        changesToReset.add(item);
    }
    
    this->head.resetChanges(changesToReset);
    return true;
}

bool VersionControl::commit(SparseSet<int> selectedItems, const String &message)
{
    if (selectedItems.size() == 0) { return false; }

    VCS::Revision::Ptr newRevision(new VCS::Revision(message));
    VCS::Revision::Ptr allChanges(this->head.getDiff());

    for (int i = 0; i < selectedItems.size(); ++i)
    {
        const int index = selectedItems[i];
        if (index >= allChanges->getItems().size()) { return false; }
        if (auto *item = allChanges->getItems()[index].get())
        {
            newRevision->addItem(item);
        }
    }

    VCS::Revision::Ptr headingRevision(this->head.getHeadingRevision());
    if (headingRevision == nullptr) { return false; }

    headingRevision->addChild(newRevision);
    this->head.moveTo(newRevision);

    this->sendChangeMessage();
    return true;
}


//===----------------------------------------------------------------------===//
// Stashes
//===----------------------------------------------------------------------===//

bool VersionControl::stash(SparseSet<int> selectedItems,
    const String &message, bool shouldKeepChanges)
{
    if (selectedItems.size() == 0) { return false; }
    
    VCS::Revision::Ptr newRevision(new VCS::Revision(message));
    VCS::Revision::Ptr allChanges(this->head.getDiff());
    
    for (int i = 0; i < selectedItems.size(); ++i)
    {
        const int index = selectedItems[i];
        if (index >= allChanges->getItems().size()) { return false; }
        newRevision->addItem(allChanges->getItems()[index]);
    }
    
    this->stashes->addStash(newRevision);

    if (! shouldKeepChanges)
    {
        this->resetChanges(selectedItems);
    }
    
    this->sendChangeMessage();
    return true;
}

bool VersionControl::applyStash(const VCS::Revision::Ptr stash, bool shouldKeepStash)
{
    if (! stash->isEmpty())
    {
        VCS::Revision::Ptr headRevision(this->head.getHeadingRevision());
        this->head.moveTo(stash);
        this->head.cherryPickAll();
        this->head.moveTo(headRevision);
        
        if (! shouldKeepStash)
        {
            this->stashes->removeStash(stash);
        }
        
        this->sendChangeMessage();
        return true;
    }
    
    return false;
}

bool VersionControl::applyStash(const String &stashId, bool shouldKeepStash)
{
    return this->applyStash(this->stashes->getUserStashWithName(stashId), shouldKeepStash);
}

bool VersionControl::hasQuickStash() const
{
    return (! this->stashes->hasQuickStash());
}

bool VersionControl::quickStashAll()
{
    if (this->hasQuickStash())
    { return false; }

    VCS::Revision::Ptr allChanges(this->head.getDiff());
    this->stashes->storeQuickStash(allChanges);
    this->resetAllChanges();

    this->sendChangeMessage();
    return true;
}

bool VersionControl::restoreQuickStash()
{
    if (! this->hasQuickStash())
    { return false; }
    
    VCS::Head tempHead(this->head);
    tempHead.mergeStateWith(this->stashes->getQuickStash());
    tempHead.cherryPickAll();
    this->stashes->resetQuickStash();
    
    this->sendChangeMessage();
    return true;
}

//===----------------------------------------------------------------------===//
// ChangeListener
//===----------------------------------------------------------------------===//

void VersionControl::changeListenerCallback(ChangeBroadcaster* source)
{
    // Project changed
    this->getHead().setDiffOutdated(true);
}

#if !NO_NETWORK

//===----------------------------------------------------------------------===//
// Network
//===----------------------------------------------------------------------===//

void VersionControl::syncAllRevisions()
{
    App::Network().getProjectSyncService()->syncRevisions(this,
        this->parent.getVCSId(), this->parent.getVCSName(), {}, {});
}

void VersionControl::fetchRevisionsIfNeeded()
{
    if (this->remoteCache.isOutdated())
    {
        DBG("Remote revisions cache is outdated, fetching the latest project info");
        App::Network().getProjectSyncService()->fetchRevisionsInfo(this,
            this->parent.getVCSId(), this->parent.getVCSName());
    }
}

void VersionControl::pushBranch(const VCS::Revision::Ptr leaf)
{
    // we need to sync the whole branch, i.e. all parents of that revision:
    Array<String> subtreeToPush = { leaf->getUuid() };

    WeakReference<VCS::Revision> it = leaf.get();
    while (it->getParent() != nullptr)
    {
        it = it->getParent();
        subtreeToPush.add(it->getUuid());
    }

    App::Network().getProjectSyncService()->syncRevisions(this,
        this->parent.getVCSId(), this->parent.getVCSName(),
        {}, subtreeToPush);
}

void VersionControl::pullBranch(const VCS::Revision::Ptr leaf)
{
    // we need to sync the whole branch, i.e. all parents of that revision:
    Array<String> subtreeToPull = { leaf->getUuid() };

    WeakReference<VCS::Revision> it = leaf.get();
    while (it->getParent() != nullptr)
    {
        it = it->getParent();
        if (it->isShallowCopy())
        {
            subtreeToPull.add(it->getUuid());
        }
    }

    App::Network().getProjectSyncService()->syncRevisions(this,
        this->parent.getVCSId(), this->parent.getVCSName(),
        subtreeToPull, {});
}

void VersionControl::updateLocalSyncCache(const VCS::Revision::Ptr revision)
{
    this->remoteCache.updateForLocalRevision(revision);
    this->sendChangeMessage();
}

void VersionControl::updateRemoteSyncCache(const Array<RevisionDto> &revisions)
{
    this->remoteCache.updateForRemoteRevisions(revisions);
    this->sendChangeMessage();
}

VCS::Revision::SyncState VersionControl::getRevisionSyncState(const VCS::Revision::Ptr revision) const
{
    if (!revision->isShallowCopy() && this->remoteCache.hasRevisionTracked(revision))
    {
        return VCS::Revision::FullSync;
    }
    else if (revision->isShallowCopy())
    {
        return VCS::Revision::ShallowCopy;
    }

    return VCS::Revision::NoSync;
}

#endif

//===----------------------------------------------------------------------===//
// Serializable
//===----------------------------------------------------------------------===//

SerializedData VersionControl::serialize() const
{
    SerializedData tree(Serialization::Core::versionControl);

    tree.setProperty(Serialization::VCS::headRevisionId, this->head.getHeadingRevision()->getUuid());
    tree.setProperty(Serialization::VCS::diffFormatVersion, VersionControl::diffFormatVersion);

    tree.appendChild(this->rootRevision->serialize());
    tree.appendChild(this->stashes->serialize());
    tree.appendChild(this->head.serialize());

#if !NO_NETWORK
    tree.appendChild(this->remoteCache.serialize());
#endif

    return tree;
}

void VersionControl::deserialize(const SerializedData &data)
{
    this->reset();

    const auto root = data.hasType(Serialization::Core::versionControl) ?
        data : data.getChildWithName(Serialization::Core::versionControl);

    if (!root.isValid()) { return; }

    const String headId = root.getProperty(Serialization::VCS::headRevisionId);

    this->rootRevision->deserialize(root);
    this->stashes->deserialize(root);

#if !NO_NETWORK
    this->remoteCache.deserialize(root);
#endif

    {
#if DEBUG
        const double headLoadStart = Time::getMillisecondCounterHiRes();
#endif
        this->head.deserialize(root);
        DBG("Loading VCS snapshot done in " + String(Time::getMillisecondCounterHiRes() - headLoadStart) + "ms");
    }
    
    if (auto headRevision = this->getRevisionById(this->rootRevision, headId))
    {
        // head keeps a snapshot node, which is the result of applying all deltas
        // from the start (moveTo() does this), in other words, the "project state" of
        // current head position, and it will be used as a baseline when making a diff;
        // we persist it for performance: rebuilding it from scratch is super slow;
        // as the app development moves forward, the snapshot, being a kind of a cache,
        // can get outdated, i.e. not containing all supported delta types, and needs
        // to be rebuilt to make correct diffs.

        const int snapshotDiffFormatVersion =
            root.getProperty(Serialization::VCS::diffFormatVersion, 0);

        const bool needToRebuildSnapshot =
            snapshotDiffFormatVersion != VersionControl::diffFormatVersion;

        if (needToRebuildSnapshot)
        {
            DBG("Found outdated diff format, rebuilding VCS snapshot");
            this->head.moveTo(headRevision);
        }
        else
        {
            this->head.pointTo(headRevision);
        }
    }
}

void VersionControl::reset()
{
    this->rootRevision->reset();
    this->head.reset();
    this->stashes->reset();
#if !NO_NETWORK
    this->remoteCache.reset();
#endif
}

//===----------------------------------------------------------------------===//
// Private
//===----------------------------------------------------------------------===//

VCS::Revision::Ptr VersionControl::getRevisionById(const VCS::Revision::Ptr startFrom, const String &id) const
{
    if (startFrom->getUuid() == id)
    {
        return startFrom;
    }

    for (auto *child : startFrom->getChildren())
    {
        if (auto search = this->getRevisionById(child, id))
        {
            return search;
        }
    }

    return nullptr;
}
