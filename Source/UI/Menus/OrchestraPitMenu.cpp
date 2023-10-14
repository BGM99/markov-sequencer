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
#include "OrchestraPitMenu.h"
#include "OrchestraPitNode.h"
#include "CommandIDs.h"
#include "MainLayout.h"
#include "PluginScanner.h"
#include "Workspace.h"

OrchestraPitMenu::OrchestraPitMenu(OrchestraPitNode &parentOrchestra) :
    instrumentsRoot(parentOrchestra)
{
    MenuPanel::Menu menu;

    const bool pluginsAreCurrentlyScanning = App::Workspace().getPluginManager().isWorking();

    if (!pluginsAreCurrentlyScanning)
    {
        menu.add(MenuItem::item(Icons::reset,
            CommandIDs::ScanAllPlugins,
            TRANS(I18n::Menu::instrumentsReload))->closesMenu());
    }
    
#if PLATFORM_DESKTOP

    menu.add(MenuItem::item(Icons::browse,
        CommandIDs::ScanPluginsFolder,
        TRANS(I18n::Menu::instrumentsScanFolder))->closesMenu());

#endif

    this->updateContent(menu, MenuPanel::SlideRight);
}
