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
#include "ResourceSyncService.h"
#include "Workspace.h"

#if !NO_NETWORK

// Try to update resources and versions info after:
#if DEBUG
#   define UPDATE_INFO_TIMEOUT_MS (1000 * 100)
#else
#   define UPDATE_INFO_TIMEOUT_MS (1000 * 10)
#endif

ResourceSyncService::ResourceSyncService() :
    synchronizer(this->prepareSyncThread())
{
    this->prepareUpdatesCheckThread()->checkForUpdates(UPDATE_INFO_TIMEOUT_MS);
    this->synchronizer->startThread(6);

    // todo subscribe on user profile changes
    // detect resources missing locally
    // and put them to download queue
}

void ResourceSyncService::queueSync(const ConfigurationResource::Ptr resource)
{
    jassert(this->synchronizer != nullptr);
    this->synchronizer->queuePutConfiguration(resource);
    DBG("Queued uploading configuration resource: " +
        resource->getResourceType() + "/" + resource->getResourceId());
}

void ResourceSyncService::queueDelete(const ConfigurationResource::Ptr resource)
{
    jassert(this->synchronizer != nullptr);
    this->synchronizer->queueDeleteConfiguration(resource);
    DBG("Queued deleting configuration resource: " +
        resource->getResourceType() + "/" + resource->getResourceId());
}

void ResourceSyncService::queueFetch(const SyncedConfigurationInfo::Ptr resource)
{
    jassert(this->synchronizer != nullptr);
    this->synchronizer->queueGetConfiguration(resource);
    DBG("Queued fetching configuration resource: " +
        resource->getType() + "/" + resource->getName());
}

UserConfigSyncThread *ResourceSyncService::prepareSyncThread()
{
    auto *thread = this->getNewThreadFor<UserConfigSyncThread>();

    // each callback is supposed to process the result and then resume
    // queue processing by calling WaitableEvent::signal()

    thread->onQueueEmptied = [this]()
    {
        DBG("Sync queue empty");
    };

    thread->onSyncError = [this](const Array<String> &errors)
    {
        this->synchronizer->signal();
    };

    thread->onResourceFetched = [this](const UserResourceDto dto)
    {
        auto &configs = App::Config().getAllResources();
        if (configs.contains(dto.getType()))
        {
            auto config = configs.at(dto.getType());
            // create a specific object based on resource->getType()
            ConfigurationResource::Ptr resource(config->createResource());
            // then deserialize using this->response.getBody()
            resource->deserialize(dto.getData());
            config->updateUserResource(resource);
        }

        this->synchronizer->signal();
    };

    thread->onResourceUpdated = [this](const UserResourceDto resource)
    {
        auto &profile = App::Workspace().getUserProfile();
        profile.onConfigurationInfoUpdated(resource);
        this->synchronizer->signal();
    };

    thread->onResourceDeleted = [this](const Identifier &type, const String &name)
    {
        auto &profile = App::Workspace().getUserProfile();
        profile.onConfigurationInfoReset(type, name);
        this->synchronizer->signal();
    };

    return thread;
}

BaseConfigSyncThread *ResourceSyncService::prepareResourceRequestThread()
{
    auto *thread = this->getNewThreadFor<BaseConfigSyncThread>();

    thread->onRequestResourceOk = [this](const Identifier &resourceType, const SerializedData &resource)
    {
        if (App::Config().getAllResources().contains(resourceType))
        {
            App::Config().getAllResources().at(resourceType)->updateBaseResource(resource);
        }
    };

    return thread;
}

UpdatesCheckThread *ResourceSyncService::prepareUpdatesCheckThread()
{
    auto *thread = this->getNewThreadFor<UpdatesCheckThread>();

    thread->onUpdatesCheckOk = [this](const AppInfoDto info)
    {
        // check if any available resource has a hash different from stored one
        // then start threads to fetch those resources (with somewhat random delays)
        Random r;
        AppInfoDto lastUpdatesInfo;
        App::Config().load(&lastUpdatesInfo, Serialization::Config::lastUpdatesInfo);
        bool everythingIsUpToDate = true;
        for (const auto &newResource : info.getResources())
        {
            if (lastUpdatesInfo.resourceSeemsOutdated(newResource))
            {
                // I just don't want to fire all requests at once:
                const auto delay = r.nextInt(5) * 1000;
                this->prepareResourceRequestThread()->requestResource(newResource.getType(), delay);
                everythingIsUpToDate = false;
            }
        }

        if (everythingIsUpToDate)
        {
            DBG("All resources are up to date");
        }

        // save all anyway, as versions info might have changed;
        // also don't care if the resource update thread will succeed or not,
        // those updates are very optional (maybe todo fix it someday)
        App::Config().save(&info, Serialization::Config::lastUpdatesInfo);
    };

    thread->onUpdatesCheckFailed = [](const Array<String> &errors)
    {
        DBG("onUpdatesCheckFailed: " + errors.getFirst());
    };

    return thread;
}

#endif
