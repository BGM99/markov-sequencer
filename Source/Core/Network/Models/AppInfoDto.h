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

#pragma once

#if !NO_NETWORK

#include "ApiModel.h"
#include "AppResourceDto.h"
#include "AppVersionDto.h"

class AppInfoDto final : public ApiModel
{
public:

    AppInfoDto() noexcept : ApiModel({}) {}
    AppInfoDto(const SerializedData &tree) noexcept : ApiModel(tree) {}

    Array<AppVersionDto> getVersions() const { return DTO_CHILDREN(AppVersionDto, Versions::versions); }
    Array<AppResourceDto> getResources() const { return DTO_CHILDREN(AppResourceDto, Resources::resources); }

    // True if caches differ for the same resource,
    // or if new resource is not even listed here
    bool resourceSeemsOutdated(const AppResourceDto &newResource) const
    {
        bool hasInfoForNewResource = false;
        forEachChildWithType(this->data, resourceData, Serialization::Api::V1::Resources::resources)
        {
            const AppResourceDto oldResource(resourceData);
            if (oldResource.getType() == newResource.getType())
            {
                hasInfoForNewResource = true;
                if (oldResource.getHash() != newResource.getHash())
                {
                    return true;
                }
            }
        }

        return !hasInfoForNewResource;
    }

    JUCE_LEAK_DETECTOR(AppInfoDto)
};

#endif
