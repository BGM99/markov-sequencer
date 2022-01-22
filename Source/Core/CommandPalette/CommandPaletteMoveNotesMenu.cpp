/*
    This file is part of Helio Workstation.

    Helio is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Helio is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Helio. If not, see <http://www.gnu.org/licenses/>.
*/

#include "Common.h"
#include "CommandPaletteMoveNotesMenu.h"

#include "Pattern.h"
#include "PianoRoll.h"
#include "ProjectNode.h"
#include "PianoTrackNode.h"
#include "SequencerOperations.h"
#include "MainLayout.h"

CommandPaletteMoveNotesMenu::CommandPaletteMoveNotesMenu(PianoRoll &roll, ProjectNode &project) :
    CommandPaletteActionsProvider(TRANS(I18n::CommandPalette::moveNotes), ':', -2.f),
    roll(roll),
    project(project)
{
    this->project.addListener(this);
}

CommandPaletteMoveNotesMenu::~CommandPaletteMoveNotesMenu()
{
    this->project.removeListener(this);
}

const CommandPaletteActionsProvider::Actions &CommandPaletteMoveNotesMenu::getActions() const
{
    if (!this->actionsCacheOutdated)
    {
        return this->actionsCache;
    }

    this->actionsCache.clearQuick();

    if (this->roll.getLassoSelection().getNumSelected() == 0)
    {
        jassertfalse;
        return this->actionsCache;
    }

    for (auto *targetTrack : this->project.findChildrenOfType<PianoTrackNode>())
    {
        if (targetTrack == this->roll.getActiveTrack())
        {
            continue;
        }

        // this will sort tracks by "distance" from the selection to the closest clip
        // of the target track, so that "closest" targets will be listed first,
        // and it's more convenient to move notes - pressing ':' and 'down' one or two times 

        float closestClipDistance = 0.f;
        auto &closestClip = SequencerOperations::findClosestClip(this->roll.getLassoSelection(),
            targetTrack, closestClipDistance);

        static const float orderOffset = 10.f; // after the 'extract as new track' action
        this->actionsCache.add(CommandPaletteAction::action(targetTrack->getTrackName(),
            this->getName(), orderOffset + closestClipDistance)->
            withColour(targetTrack->getTrackColour())->
            withCallback([this, targetTrack, &closestClip](TextEditor &)
        {
            SequencerOperations::moveSelection(this->roll.getLassoSelection(), closestClip, true);
            this->project.setEditableScope(closestClip, false);
            return true;
        }));
    }

    this->actionsCacheOutdated = false;
    return this->actionsCache;
}

void CommandPaletteMoveNotesMenu::onAddClip(const Clip &clip)
{
    this->actionsCacheOutdated = true;
}

void CommandPaletteMoveNotesMenu::onChangeClip(const Clip &oldClip, const Clip &newClip)
{
    this->actionsCacheOutdated = true;
}

void CommandPaletteMoveNotesMenu::onRemoveClip(const Clip &clip)
{
    this->actionsCacheOutdated = true;
}

void CommandPaletteMoveNotesMenu::onAddTrack(MidiTrack *const track)
{
    this->actionsCacheOutdated = true;
}

void CommandPaletteMoveNotesMenu::onRemoveTrack(MidiTrack *const track)
{
    this->actionsCacheOutdated = true;
}

void CommandPaletteMoveNotesMenu::onChangeTrackProperties(MidiTrack *const track)
{
    this->actionsCacheOutdated = true; // the name might have changed
}

void CommandPaletteMoveNotesMenu::onChangeTrackBeatRange(MidiTrack *const track)
{
    this->actionsCacheOutdated = true;
}

void CommandPaletteMoveNotesMenu::onReloadProjectContent(const Array<MidiTrack *> &tracks,
    const ProjectMetadata *meta)
{
    this->actionsCacheOutdated = true;
}

void CommandPaletteMoveNotesMenu::onChangeProjectBeatRange(float firstBeat, float lastBeat)
{
    this->actionsCacheOutdated = true;
}

void CommandPaletteMoveNotesMenu::onChangeViewEditableScope(MidiTrack *const track, const Clip &clip, bool shouldFocus)
{
    this->actionsCacheOutdated = true;
}
