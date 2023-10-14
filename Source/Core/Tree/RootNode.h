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

#include "TreeNode.h"
#include "Dashboard.h"

class ProjectNode;
class VersionControlNode;
class TrackGroupNode;
class MidiTrackNode;

class RootNode final : public TreeNode
{
public:

    explicit RootNode(const String &name);

    String getName() const noexcept override;
    Image getIcon() const noexcept override;

    void showPage() override;
    void recreatePage() override;

    //===------------------------------------------------------------------===//
    // Children
    //===------------------------------------------------------------------===//

    ProjectNode *importMidi(const File &file);
    ProjectNode *openProject(const File &file);

#if !NO_NETWORK
    ProjectNode *checkoutProject(const String &id, const String &name);
#endif

    ProjectNode *addExampleProject();
    ProjectNode *addEmptyProject(const File &projectLocation, const String &templateName);
    ProjectNode *addEmptyProject(const String &projectName, const String &templateName);
    
    //===------------------------------------------------------------------===//
    // Menu
    //===------------------------------------------------------------------===//

    bool hasMenu() const noexcept override;
    UniquePointer<Component> createMenu() override;

    //===------------------------------------------------------------------===//
    // Serializable
    //===------------------------------------------------------------------===//

    void deserialize(const SerializedData &data) override;

private:

    UniquePointer<Dashboard> dashboard;

};
