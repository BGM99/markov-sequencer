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

class Workspace;
#include "UserProfile.h"

class DashboardMenu final : public Component, public ListBoxModel
{
public:

    explicit DashboardMenu(Workspace &parentWorkspace);

    void updateListContent();
    void loadFile(RecentProjectInfo::Ptr fileDescription);
    void unloadFile(RecentProjectInfo::Ptr fileDescription);

    //===------------------------------------------------------------------===//
    // ListBoxModel
    //===------------------------------------------------------------------===//

    int getNumRows() override;
    Component *refreshComponentForRow(int, bool, Component *) override;
    void listBoxItemClicked(int row, const MouseEvent &e) override {}
    void paintListBoxItem(int, Graphics &, int, int, bool) override {}

    void resized() override;

private:

    Workspace &workspace;
    FlatHashSet<String, StringHash> loadedProjectIds;

    UniquePointer<ListBox> listBox;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DashboardMenu)
};
