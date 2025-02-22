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
#include <variant>

class ProjectNode;
//==============================================================================
/*
*/
class MarkovEditorPanel final : public Component,
private ListBoxModel
{
  using Sound = std::variant<Note, std::vector<Note>, float>;

public:
    MarkovEditorPanel(ProjectNode &project);
    ~MarkovEditorPanel() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    void paintListBoxItem(int rowNumber, Graphics & g, int width, int height, bool isSelected) override;
    int getNumRows() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MarkovEditorPanel)

  ProjectNode &project;

  const Colour borderLineDark = findDefaultColour(ColourIDs::TrackScroller::borderLineDark);
  const Colour borderLineLight = findDefaultColour(ColourIDs::TrackScroller::borderLineLight);

  UniquePointer<ListBox> listBox;
  std::vector<std::pair<float, Sound>> items;
};
