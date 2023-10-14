/*
    This file is part of Helio music sequencer.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include "Common.h"

#if !NO_NETWORK

#include "RemoteCache.h"

namespace VCS
{

bool RemoteCache::hasRevisionTracked(const Revision::Ptr revision) const
{
    ScopedReadLock lock(this->cacheLock);
    return this->fetchCache.contains(revision->getUuid());
}

#if !NO_NETWORK

void RemoteCache::updateForRemoteRevisions(const Array<RevisionDto> &revisions)
{
    ScopedWriteLock lock(this->cacheLock);

    this->fetchCache.clear();
    for (const auto &child : revisions)
    {
        this->fetchCache[child.getId()] = child.getTimestamp();
    }

    this->lastSyncTime = Time::getCurrentTime();
}

#endif

void RemoteCache::updateForLocalRevision(const Revision::Ptr revision)
{
    ScopedWriteLock lock(this->cacheLock);
    this->fetchCache[revision->getUuid()] = revision->getTimeStamp();
    this->lastSyncTime = Time::getCurrentTime();
}

bool RemoteCache::isOutdated() const
{
    // if history has not been synced for at least a couple of days,
    // version control will fetch remote revisions in a background
    ScopedReadLock lock(this->cacheLock);
    return this->fetchCache.size() > 0 &&
        (Time::getCurrentTime() - this->lastSyncTime).inDays() > 1;
}

//===----------------------------------------------------------------------===//
// Serializable
//===----------------------------------------------------------------------===//

SerializedData RemoteCache::serialize() const
{
    SerializedData tree(Serialization::VCS::remoteCache);

    tree.setProperty(Serialization::VCS::remoteCacheSyncTime, this->lastSyncTime.toMilliseconds());

    for (const auto &child : this->fetchCache)
    {
        SerializedData revNode(Serialization::VCS::remoteRevision);
        revNode.setProperty(Serialization::VCS::remoteRevisionId, child.first);
        revNode.setProperty(Serialization::VCS::remoteRevisionTimeStamp, child.second);
        tree.appendChild(revNode);
    }

    return tree;
}

void RemoteCache::deserialize(const SerializedData &data)
{
    this->reset();

    const auto root = data.hasType(Serialization::VCS::remoteCache) ?
        data : data.getChildWithName(Serialization::VCS::remoteCache);

    if (!root.isValid()) { return; }

    this->lastSyncTime = Time(root.getProperty(Serialization::VCS::remoteCacheSyncTime));

    forEachChildWithType(root, e, Serialization::VCS::remoteRevision)
    {
        const String revisionId = e.getProperty(Serialization::VCS::remoteRevisionId);
        const int64 revisionTimestamp = e.getProperty(Serialization::VCS::remoteRevisionTimeStamp);
        this->fetchCache[revisionId] = revisionTimestamp;
    }
}

void RemoteCache::reset()
{
    this->fetchCache.clear();
}

}

#endif
