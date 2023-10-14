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
#include "ProjectDto.h"
#include "UserResourceDto.h"
#include "UserSessionDto.h"

class UserProfileDto final : public ApiModel
{
public:

    UserProfileDto(const SerializedData &tree, const MemoryBlock &image = {}) noexcept :
        ApiModel(tree), avatarData(image) {}
    
    String getName() const noexcept { return DTO_PROPERTY(Identity::name); }
    String getLogin() const noexcept { return DTO_PROPERTY(Identity::login); }
    String getAvatarUrl() const noexcept { return DTO_PROPERTY(Identity::avatarUrl); }
    String getProfileUrl() const noexcept { return DTO_PROPERTY(Identity::profileUrl); }

    MemoryBlock &getAvatarData() noexcept { return this->avatarData; }
    const MemoryBlock &getAvatarData() const noexcept { return this->avatarData; }
    bool hasAvatarData() const noexcept { return this->avatarData.getSize() > 0; }

    Array<ProjectDto> getProjects() const { return DTO_CHILDREN(ProjectDto, Projects::projects); }
    Array<UserSessionDto> getSessions() const { return DTO_CHILDREN(UserSessionDto, Sessions::sessions); }
    Array<UserResourceDto> getResources() const { return DTO_CHILDREN(UserResourceDto, Resources::resources); }

private:

    MemoryBlock avatarData;

    JUCE_LEAK_DETECTOR(UserProfileDto)
};

#endif
