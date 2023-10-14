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

class VersionControl;
class VersionControlEditor;
class ProjectNode;

class VersionControlNode final : public TreeNode
{
public:

    VersionControlNode();
    ~VersionControlNode() override;

    String getName() const noexcept override;
    Image getIcon() const noexcept override;

    void showPage() override;
    void recreatePage() override;
    String getStatsString() const;
    
    void commitProjectInfo();
    void toggleQuickStash();

    //===------------------------------------------------------------------===//
    // Tree
    //===------------------------------------------------------------------===//

    void onNodeAddToTree(bool sendNotifications) override;
    void onNodeRemoveFromTree(bool sendNotifications) override;

#if !NO_NETWORK

    //===------------------------------------------------------------------===//
    // Network
    //===------------------------------------------------------------------===//

    void cloneProject();

#endif

    //===------------------------------------------------------------------===//
    // Menu
    //===------------------------------------------------------------------===//

    bool hasMenu() const noexcept override;
    UniquePointer<Component> createMenu() override;

    //===------------------------------------------------------------------===//
    // Serializable
    //===------------------------------------------------------------------===//

    SerializedData serialize() const override;
    void deserialize(const SerializedData &data) override;
    void reset() override;

protected:

    UniquePointer<VersionControl> vcs;
    UniquePointer<VersionControlEditor> editor;

private:
        
    void initVCS();
    void shutdownVCS();
    
    void initEditor();
    void shutdownEditor();

};
