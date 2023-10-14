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

//[Headers]
class NoteComponent;
class MidiSequence;
class PianoRoll;
class ScalesCommandPanel;
class FunctionsCommandPanel;

#include "Scale.h"
#include "PopupMenuComponent.h"
#include "PopupCustomButton.h"
//[/Headers]


class ScalePreviewTool final : public PopupMenuComponent,
                               public PopupButtonOwner
{
public:

    ScalePreviewTool(PianoRoll *caller, MidiSequence *layer);
    ~ScalePreviewTool();

    //[UserMethods]

    void onPopupsResetState(PopupButton *button) override;

    void onPopupButtonFirstAction(PopupButton *button) override;
    void onPopupButtonSecondAction(PopupButton *button) override;

    void onPopupButtonStartDragging(PopupButton *button) override;
    bool onPopupButtonDrag(PopupButton *button) override;
    void onPopupButtonEndDragging(PopupButton *button) override;

    void applyScale(const Scale::Ptr scale);
    void applyScaleDegree(Scale::Degree degree);

    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void parentHierarchyChanged() override;
    void handleCommandMessage (int commandId) override;
    bool keyPressed (const KeyPress& key) override;
    void inputAttemptWhenModal() override;


private:

    //[UserVariables]

    PianoRoll *roll;
    MidiSequence *sequence;

    const Array<Scale::Ptr> defaultScales;

    int targetKey;
    float targetBeat;

    Point<int> draggingStartPosition;
    Point<int> draggingEndPosition;
    bool detectKeyAndBeat(); // returns true if key changes

    Scale::Ptr scale;
    Scale::Degree degree;

    bool hasMadeChanges;
    void buildChord(Array<int> keys);
    void buildNewNote(bool shouldSendMidiMessage);
    void cancelChangesIfAny();

    void stopSound();

    //[/UserVariables]

    UniquePointer<ScalesCommandPanel> scalesList;
    UniquePointer<FunctionsCommandPanel> functionsList;
    UniquePointer<PopupCustomButton> newNote;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ScalePreviewTool)
};
