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
#include "UserProfile.h"
#include "App.h"
#include "Config.h"
#include "SerializationKeys.h"

static RecentProjectInfo kProjectsSort;
static SyncedConfigurationInfo kResourcesSort;

#if !NO_NETWORK

#include "SessionService.h"
#include "ProjectSyncService.h"
#include "ResourceSyncService.h"

static UserSessionInfo kSessionsSort;

void UserProfile::updateProfile(const UserProfileDto &dto)
{
    // Resize avatar thumbnail and cache it as png-encoded base64 string:
    const int size = 16;
    this->avatar = { Image::RGB, size, size, true };

    if (dto.hasAvatarData())
    {
        MemoryInputStream inputStream(dto.getAvatarData(), false);
        const Image remoteAvatar = ImageFileFormat::loadFrom(inputStream)
            .rescaled(size, size, Graphics::highResamplingQuality);

        Graphics g(this->avatar);
        g.setTiledImageFill(remoteAvatar, 0, 0, 1.f);
        g.fillAll();

        MemoryBlock block;
        {
            MemoryOutputStream outStream(block, false);
            this->imageFormat.writeImageToStream(this->avatar, outStream);
        }

        this->avatarThumbnail = Base64::toBase64(block.getData(), block.getSize());
    }

    for (const auto &p : dto.getProjects())
    {
        this->onProjectRemoteInfoUpdated(p);
    }

    this->sessions.clearQuick();
    for (const auto &s : dto.getSessions())
    {
        this->sessions.addSorted(kSessionsSort, new UserSessionInfo(s));
    }

    const auto &localConfig = App::Config().getAllResources();
    this->resources.clearQuick();
    for (const auto &r : dto.getResources())
    {
        bool isPresentLocally = false;
        // to detect which resources are missing locally, and schedule fetching them:
        const auto foundType = localConfig.find(r.getType());
        if (foundType != localConfig.end())
        {
            isPresentLocally = foundType->second->containsUserResourceWithId(r.getName());
        }

        const int i = this->resources.addSorted(kResourcesSort, new SyncedConfigurationInfo(r));

        if (!isPresentLocally)
        {
            DBG("Found new user configuration to be synced: " + r.getType() + "/" + r.getName());
            const auto configToFetch = this->resources[i];
            // should there be a more elegant way to do that?
            App::Network().getResourceSyncService()->queueFetch(configToFetch);
        }
    }

    this->name = dto.getName();
    this->login = dto.getLogin();
    this->profileUrl = dto.getProfileUrl();

    this->sendChangeMessage();
}

void UserProfile::onConfigurationInfoUpdated(const UserResourceDto &dto)
{
    for (const auto resource : this->resources)
    {
        if (resource->getName() == dto.getName() &&
            resource->getType().toString() == dto.getType())
        {
            // already has that info, no need to send change message;
            return;
        }
    }

    this->resources.addSorted(kResourcesSort, new SyncedConfigurationInfo(dto));
    this->sendChangeMessage();
}

void UserProfile::onProjectRemoteInfoUpdated(const ProjectDto &info)
{
    if (auto *project = this->findProject(info.getId()))
    {
        project->updateRemoteInfo(info);
        this->projects.sort(kProjectsSort);
    }
    else
    {
        this->projects.addSorted(kProjectsSort, new RecentProjectInfo(info));
    }

    this->sendChangeMessage();
}

bool UserProfile::hasSyncedConfiguration(const Identifier &type, const String &name) const
{
    // this check will be called each time user profile sends change message
    // for each found resource, to check if it is synced;
    // but as synced resource list is sorted, we can use binary search:

    int start = 0;
    int end = this->resources.size();
    while (start < end)
    {
        if (kResourcesSort.compareElements(type, name,
            this->resources.getObjectPointerUnchecked(start)) == 0)
        {
            return true;
        }

        const auto halfway = (start + end) / 2;
        if (halfway == start)
        {
            return false;
        }

        if (kResourcesSort.compareElements(type, name,
            this->resources.getObjectPointerUnchecked(halfway)) >= 0)
        {
            start = halfway;
        }
        else
        {
            end = halfway;
        }
    }

    return false;
}

#endif

void UserProfile::onConfigurationInfoReset(const Identifier &type, const String &name)
{
    for (int i = 0; i < this->resources.size(); ++i)
    {
        const auto resource = this->resources.getUnchecked(i);
        if (resource->getType() == type && resource->getName() == name)
        {
            this->resources.remove(i);
            this->sendChangeMessage();
            return;
        }
    }
}

void UserProfile::onProjectLocalInfoUpdated(const String &id, const String &title, const String &path)
{
    if (auto *project = this->findProject(id))
    {
        project->updateLocalInfo(id, title, path);
        this->projects.sort(kProjectsSort);
    }
    else
    {
        this->projects.addSorted(kProjectsSort, new RecentProjectInfo(id, title, path));
    }

    this->sendChangeMessage();
}

void UserProfile::onProjectLocalInfoReset(const String &id)
{
    if (auto *project = this->findProject(id))
    {
        project->resetLocalInfo();
        if (!project->isValid()) // i.e. doesn't have a remote copy
        {
            this->projects.removeObject(project);
        }
        this->sendChangeMessage();
    }
}

void UserProfile::onProjectRemoteInfoReset(const String &id)
{
    if (auto *project = this->findProject(id))
    {
        project->resetRemoteInfo();
        if (!project->isValid()) // i.e. doesn't have a local copy
        {
            this->projects.removeObject(project);
        }
        this->sendChangeMessage();
    }
}

void UserProfile::onProjectUnloaded(const String &id)
{
    if (auto *project = this->findProject(id))
    {
        project->updateLocalTimestampAsNow();
        this->projects.sort(kProjectsSort);
    }

    this->sendChangeMessage();
}

void UserProfile::deleteProjectLocally(const String &id)
{
    if (auto *project = this->findProject(id))
    {
        if (project->hasLocalCopy())
        {
            project->getLocalFile().deleteFile();
            this->onProjectLocalInfoReset(id);
        }
    }
}

#if !NO_NETWORK

void UserProfile::deleteProjectRemotely(const String &id)
{
    if (auto *project = this->findProject(id))
    {
        if (project->hasRemoteCopy())
        {
            // sync service will call onProjectRemoteInfoReset(id) when done:
            App::Network().getProjectSyncService()->deleteProject(id);
        }
    }

    this->sendChangeMessage();
}

void UserProfile::clearProfileAndSession()
{
    this->setApiToken({});
    this->avatar = {};
    this->avatarThumbnail.clear();
    this->name.clear();
    this->login.clear();
    this->profileUrl.clear();
}

bool UserProfile::needsAvatarImage() const noexcept
{
    return this->avatarThumbnail.isEmpty();
}

Image UserProfile::getAvatar() const noexcept
{
    return this->avatar;
}

String UserProfile::getLogin() const noexcept
{
    return this->login;
}

String UserProfile::getProfileUrl() const noexcept
{
    return this->profileUrl;
}

String UserProfile::getApiToken() const
{
    // todo in future - move this to profile object?
    return App::Config().getProperty(Serialization::Api::sessionToken, {});
}

void UserProfile::setApiToken(const String &token)
{
    App::Config().setProperty(Serialization::Api::sessionToken, token);
    this->sendChangeMessage();
}

#endif

bool UserProfile::isLoggedIn() const
{
#if !NO_NETWORK
    return this->getApiToken().isNotEmpty();
#else
    return false;
#endif
}

const UserProfile::ProjectsList &UserProfile::getProjects() const noexcept
{
    return this->projects;
}

const UserProfile::ResourcesList &UserProfile::getResources() const noexcept
{
    return this->resources;
}

// there won't be too much projects, so linear search should be ok
// (might have to replace this with binary search someday though)
RecentProjectInfo *UserProfile::findProject(const String &id) const
{
    for (auto *project : this->projects)
    {
        if (project->getProjectId() == id)
        {
            return project;
        }
    }

    return nullptr;
}

#if !NO_NETWORK

const UserProfile::SessionsList &UserProfile::getSessions() const noexcept
{
    return this->sessions;
}

UserSessionInfo *UserProfile::findSession(const String &deviceId) const
{
    for (auto *session : this->sessions)
    {
        if (session->getDeviceId() == deviceId)
        {
            return session;
        }
    }

    return nullptr;
}

#endif

//===----------------------------------------------------------------------===//
// Serializable
//===----------------------------------------------------------------------===//

SerializedData UserProfile::serialize() const
{
    using namespace Serialization::User;

    SerializedData tree(Profile::userProfile);

    if (this->profileUrl.isNotEmpty())
    {
        tree.setProperty(Profile::url, this->profileUrl);
    }

    if (this->name.isNotEmpty())
    {
        tree.setProperty(Profile::name, this->name);
    }

    if (this->login.isNotEmpty())
    {
        tree.setProperty(Profile::login, this->login);
    }

    if (this->avatarThumbnail.isNotEmpty())
    {
        tree.setProperty(Profile::thumbnail, this->avatarThumbnail);
    }

    for (const auto *project : this->projects)
    {
        tree.appendChild(project->serialize());
    }

#if !NO_NETWORK
    for (const auto *session : this->sessions)
    {
        tree.appendChild(session->serialize());
    }
#endif

    for (const auto *resource : this->resources)
    {
        tree.appendChild(resource->serialize());
    }

    return tree;
}

void UserProfile::deserialize(const SerializedData &data)
{
    this->reset();
    using namespace Serialization::User;
    const auto root = data.hasType(Profile::userProfile) ?
        data : data.getChildWithName(Profile::userProfile);

    if (!root.isValid()) { return; }

    this->name = root.getProperty(Profile::name);
    this->login = root.getProperty(Profile::login);
    this->profileUrl = root.getProperty(Profile::url);
    this->avatarThumbnail = root.getProperty(Profile::thumbnail);

    if (this->avatarThumbnail.isNotEmpty())
    {
        MemoryBlock block;
        {
            MemoryOutputStream outStream(block, false);
            Base64::convertFromBase64(outStream, this->avatarThumbnail);
        }

        this->avatar = ImageFileFormat::loadFrom(block.getData(), block.getSize());
    }

    forEachChildWithType(root, child, RecentProjects::recentProject)
    {
        RecentProjectInfo::Ptr p(new RecentProjectInfo());
        p->deserialize(child);
        if (p->isValid())
        {
            this->projects.addSorted(kProjectsSort, p.get());
        }
    }
    
#if !NO_NETWORK
    forEachChildWithType(root, child, Sessions::session)
    {
        UserSessionInfo::Ptr s(new UserSessionInfo());
        s->deserialize(child);
        // TODO store JWT as well? remove current session if stale?
        this->sessions.addSorted(kSessionsSort, s.get());
    }
#endif

    forEachChildWithType(root, child, Configurations::resource)
    {
        SyncedConfigurationInfo::Ptr s(new SyncedConfigurationInfo());
        s->deserialize(child);
        this->resources.addSorted(kResourcesSort, s.get());
    }

    // TODO scan documents folder for existing projects not present in the list?
    // or only do it when the list is empty?

    // and get all workspace's projects

    this->sendChangeMessage();
}

void UserProfile::reset()
{
    this->projects.clearQuick();
#if !NO_NETWORK
    this->sessions.clearQuick();
#endif
    this->sendChangeMessage();
}
