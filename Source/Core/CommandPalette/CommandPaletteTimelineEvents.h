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

#include "ProjectNode.h"
#include "CommandPaletteActionsProvider.h"

class CommandPaletteTimelineEvents final :
    public CommandPaletteActionsProvider,
    public ProjectListener
{
public:

    explicit CommandPaletteTimelineEvents(ProjectNode &project);
    ~CommandPaletteTimelineEvents() override;

    //===------------------------------------------------------------------===//
    // ProjectListener
    //===------------------------------------------------------------------===//

    void onChangeMidiEvent(const MidiEvent &oldEvent, const MidiEvent &newEvent) override;
    void onAddMidiEvent(const MidiEvent &event) override;
    void onRemoveMidiEvent(const MidiEvent &event) override;

    void onAddClip(const Clip &clip) override;
    void onChangeClip(const Clip &oldClip, const Clip &newClip) override;
    void onRemoveClip(const Clip &clip) override;

    void onAddTrack(MidiTrack *const track) override;
    void onRemoveTrack(MidiTrack *const track) override;
    void onChangeTrackProperties(MidiTrack *const track) override;
    void onChangeTrackBeatRange(MidiTrack *const track) override;

    void onChangeProjectBeatRange(float firstBeat, float lastBeat) override;
    void onChangeViewBeatRange(float firstBeat, float lastBeat) override {}
    void onReloadProjectContent(const Array<MidiTrack *> &tracks,
        const ProjectMetadata *meta) override;

protected:

    const Actions &getActions() const override;

    mutable Actions keySignatureActionsCache;
    mutable Actions timeSignatureActionsCache;
    mutable Actions annotationActionsCache;
    mutable Actions clipActionsCache;
    mutable Actions allActions;

    mutable bool keySignatureActionsOutdated = true;
    mutable bool timeSignatureActionsOutdated = true;
    mutable bool annotationActionsOutdated = true;
    mutable bool clipActionsOutdated = true;

private:
    
    ProjectNode &project;

};
