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
#include "ConfigurationResourceCollection.h"
#include "JsonSerializer.h"
#include "BinarySerializer.h"
#include "DocumentHelpers.h"

// TODO: monitor user's file changes?

ConfigurationResourceCollection::ConfigurationResourceCollection(const Identifier &resourceType) :
    resourceType(resourceType) {}

ConfigurationResourceCollection::~ConfigurationResourceCollection()
{
    this->reset();
}

void ConfigurationResourceCollection::updateBaseResource(const SerializedData &resource)
{
    DBG("Updating downloaded resource file for " + this->resourceType.toString());

#if DEBUG
    JsonSerializer serializer(false);
#else
    BinarySerializer serializer;
#endif

    serializer.saveToFile(this->getDownloadedResourceFile(), resource);

    // do not reload anything here to avoid possible issues,
    // all updates will just appear at the next start:
    //this->reloadResources();
}

void ConfigurationResourceCollection::updateUserResource(const ConfigurationResource::Ptr resource)
{
    this->userResources[resource->getResourceId()] = resource;

    // TODO sync with server?
    DBG("Updating user's resource file for " + this->resourceType.toString());

    JsonSerializer serializer(false);
    serializer.setHeaderComments({ "Custom overrides for " + this->resourceType.toString(), "Can be edited manually" });
    serializer.saveToFile(this->getUsersResourceFile(), this->serializeResources(this->userResources));

    // Should we really send update message here?
    this->sendChangeMessage();
}

File ConfigurationResourceCollection::getDownloadedResourceFile() const
{
    const String assumedFileName = this->resourceType + ".helio";
    return DocumentHelpers::getConfigSlot(assumedFileName);
}

File ConfigurationResourceCollection::getUsersResourceFile() const
{
    const String assumedFileName = this->resourceType + ".json";
    return DocumentHelpers::getDocumentSlot(assumedFileName);
}

String ConfigurationResourceCollection::getBuiltInResourceString() const
{
    int dataSize;
    const String assumedResourceName = this->resourceType.toString() + "_json";
    if (const auto *data = BinaryData::getNamedResource(assumedResourceName.toUTF8(), dataSize))
    {
        return String::fromUTF8(data, dataSize);
    }

    return {};
}

const ConfigurationResource &ConfigurationResourceCollection::getResourceComparator() const
{
    return this->comparator;
}


SerializedData ConfigurationResourceCollection::serializeResources(const Resources &resources)
{
    SerializedData tree(this->resourceType);

    for (const auto &resource : resources)
    {
        tree.appendChild(resource.second->serialize());
    }

    return tree;
}

void ConfigurationResourceCollection::reset()
{
    this->baseResources.clear();
    this->userResources.clear();
}

void ConfigurationResourceCollection::reloadResources()
{
    bool shouldBroadcastChange = false;

    // Reset and store an empty tree to append user objects to
    this->baseResources.clear();
    this->userResources.clear();

    // load both built-in and downloaded resource:
    // downloaded extends and overrides built-in one,
    // user's config extends and overrides the previous step

#if DEBUG
    auto startTime = Time::getMillisecondCounter();
#endif

    const String builtInResource(this->getBuiltInResourceString());
    if (builtInResource.isNotEmpty())
    {
        const auto tree(DocumentHelpers::load(builtInResource));
        if (tree.isValid())
        {
            this->deserializeResources(tree, this->baseResources);
            shouldBroadcastChange = true;
        }

        DBG("Loaded built-in " + this->resourceType.toString() + " in " + String(Time::getMillisecondCounter() - startTime) + " ms");
    }

#if DEBUG
    startTime = Time::getMillisecondCounter();
#endif

    // Try to extend built-in config with downloaded one
    const File downloadedResource(this->getDownloadedResourceFile());
    if (downloadedResource.existsAsFile())
    {
        const auto tree(DocumentHelpers::load(downloadedResource));
        if (tree.isValid())
        {
            this->deserializeResources(tree, this->baseResources);
            shouldBroadcastChange = true;
        }

        DBG("Loaded extended " + this->resourceType.toString() + " in " + String(Time::getMillisecondCounter() - startTime) + " ms");
    }

#if DEBUG
    startTime = Time::getMillisecondCounter();
#endif

    // Try to extend base config with user's settings
    const File usersResource(this->getUsersResourceFile());

    if (usersResource.existsAsFile())
    {
        const auto tree(DocumentHelpers::load(usersResource));
        if (tree.isValid())
        {
            this->deserializeResources(tree, this->userResources);
            shouldBroadcastChange = true;
        }

        DBG("Loaded user's " + this->resourceType.toString() + " in " + String(Time::getMillisecondCounter() - startTime) + " ms");
    }

    if (shouldBroadcastChange)
    {
        this->sendChangeMessage();
    }
}
