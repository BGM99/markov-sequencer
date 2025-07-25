/*
  ==============================================================================

    MarkovEditorComponent.h
    Created: 1 Feb 2025 11:23:43pm
    Author:  bg

  ==============================================================================
*/

#pragma once

#include <Common.h>
#include <JuceHeader.h>
#include "Midi/Models/MarkovModel.h"
#include "Note.h"
#include <stack>
#include <IconButton.h>
#include <RollBase.h>
#include <variant>

class ProjectNode;
//==============================================================================
/*
*/
class MarkovEditorPanel final : public Component,
                                public Value::Listener,
                                private TableListBoxModel
{
    using Sound = std::variant<Note, std::vector<Note>, float>;

public:

    MarkovEditorPanel(ProjectNode &project, PianoRoll *roll);
    ~MarkovEditorPanel() override;

    /* Value::Listener */
    void valueChanged (Value& value) override;

    /* Component */
    void paint(juce::Graphics &) override;
    void resized() override;
    void handleCommandMessage(int commandId) override;

    /* TableListBoxModel */
    void paintCell(Graphics &, int rowNumber, int columnId, int width, int height, bool rowIsSelected) override;
    void paintRowBackground(Graphics &, int rowNumber, int width, int height, bool rowIsSelected) override;
    int getNumRows() override { return 1; }

    void cellClicked(int rowNumber, int columnId, const MouseEvent &) override;
    void cellDoubleClicked(int rowNumber, int columnId, const MouseEvent &) override;
    // String getCellTooltip (int rowNumber, int columnId) override;

    bool canMovePreviousState() const;
    void movePreviousState();
    void moveNextState();

    void generateModel();
    void loadModelFromFile();
    void saveModelToFile();

    void setCurrentInsertBeat(float newValue);
    float getCurrentInsertBeat();

private:

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MarkovEditorPanel)

    void createColumns(int n);
    static String midiNoteToString(int midiKey);
    int findNearestAbove(const std::vector<float>& v, float target);

    // todo with new id
    // Adds or removes Notes from the Track to preview a sound object (returns the length)
    float modifyTrackSoundObject(bool insert, int objectIndex, float beat, bool checkpoint);
    void removeSelectedNotes();
    int getRandomSoundObject();

    ProjectNode &project;
    PianoRoll *roll;

    const Colour borderLineDark = findDefaultColour(ColourIDs::TrackScroller::borderLineDark);
    const Colour borderLineLight = findDefaultColour(ColourIDs::TrackScroller::borderLineLight);

    UniquePointer<TableListBox> listBox;
    std::vector<std::pair<float, int>> items;

    MarkovModel currentModel;
    // -1 for initial state
    int currentState = -1;

    // {state, insertedNotes, beat}
    std::stack<std::tuple<int, Array<Note>, float>> insertedSounds;

    std::unordered_map<int, std::vector<std::pair<float, int>>> rowVector;

    // -1 for no selection
    int selectedCell = -1;

    // the beat where the selected sound was inserted
    float lastInsertBeat = 0.f;

    void updateState();

    // Model Controls
    UniquePointer<Label> modelLabel;
    UniquePointer<TextButton> generateButton;
    UniquePointer<TextButton> loadModelButton;
    UniquePointer<TextButton> saveModelButton;

    // Editor Controls
    UniquePointer<IconButton> navigatePrevious;
    UniquePointer<IconButton> navigateNext;
};