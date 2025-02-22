/*
  ==============================================================================

    EditorControlPanel.h
    Created: 22 Feb 2025 11:11:57pm
    Author:  levib

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class EditorControlPanel  : public juce::Component
{
public:
    EditorControlPanel();
    ~EditorControlPanel() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (EditorControlPanel)
};
