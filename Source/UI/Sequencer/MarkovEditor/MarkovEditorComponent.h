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

//==============================================================================
/*
*/
class MarkovEditorComponent final : public Component
{
public:
    MarkovEditorComponent();
    ~MarkovEditorComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MarkovEditorComponent)

  const Colour borderLineDark = findDefaultColour(ColourIDs::TrackScroller::borderLineDark);
  const Colour borderLineLight = findDefaultColour(ColourIDs::TrackScroller::borderLineLight);
};
