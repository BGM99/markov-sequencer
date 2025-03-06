/*
  ==============================================================================

    MarkovEditorComponent.h
    Created: 1 Feb 2025 11:23:43pm
    Author:  bg

  ==============================================================================
*/

#pragma once

#include <ColourIDs.h>
#include <Common.h>
#include <JuceHeader.h>
#include "Midi/Models/MarkovModel.h"
#include "Note.h"

#include <PianoRoll.h>
#include <RollBase.h>
#include <variant>

class ProjectNode;
//==============================================================================
/*
*/
class MarkovEditorPanel final : public Component,
private TableListBoxModel
{
  using Sound = std::variant<Note, std::vector<Note>, float>;

public:
    MarkovEditorPanel(ProjectNode &project, PianoRoll* roll);
    ~MarkovEditorPanel() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    void paintCell(Graphics &, int rowNumber, int columnId, int width, int height, bool rowIsSelected) override;
    void paintRowBackground(Graphics &, int rowNumber, int width, int height, bool rowIsSelected) override;
    int getNumRows() override { return 1; }

    void cellClicked (int rowNumber, int columnId, const MouseEvent &) override;
    void cellDoubleClicked (int rowNumber, int columnId, const MouseEvent &) override;
    //String getCellTooltip (int rowNumber, int columnId) override;

    void generateModel();
    void loadModelFromFile();
    void saveModelToFile();

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MarkovEditorPanel)

    void createColumns(int n);
    static String midiNoteToString(int midiKey);

    // todo with new id
    void modifyTrackSoundObject(bool insert, int objectIndex, float beat, bool checkpoint);

    ProjectNode &project;
    PianoRoll* roll;

    const Colour borderLineDark = findDefaultColour(ColourIDs::TrackScroller::borderLineDark);
    const Colour borderLineLight = findDefaultColour(ColourIDs::TrackScroller::borderLineLight);

    UniquePointer<TableListBox> listBox;
    std::vector<std::pair<float, int>> items;

    MarkovModel currentModel;
    // -1 for initial state
    int currentState = -1;
    std::unordered_map<int, std::vector<std::pair<float, int>>> rowVector;

    // -1 for no selection
    int selectedCell = -1;

    float currentInsertBeat = 0;

    // Model Controls
    UniquePointer<Label> modelLabel;
    UniquePointer<TextButton> generateButton;
    UniquePointer<TextButton> loadModelButton;
    UniquePointer<TextButton> saveModelButton;
};
