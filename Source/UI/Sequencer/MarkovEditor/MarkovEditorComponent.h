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

class ProjectNode;
//==============================================================================
/*
*/
class MarkovEditorPanel final : public Component,
private ListBoxModel
{
public:
    MarkovEditorPanel(ProjectNode &project);
    ~MarkovEditorPanel() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    void paintListBoxItem(int, Graphics &, int, int, bool) override {}
    int getNumRows() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MarkovEditorPanel)

  ProjectNode &project;

  const Colour borderLineDark = findDefaultColour(ColourIDs::TrackScroller::borderLineDark);
  const Colour borderLineLight = findDefaultColour(ColourIDs::TrackScroller::borderLineLight);

  UniquePointer<ListBox> listBox;
};
