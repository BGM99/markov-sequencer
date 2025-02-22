/*
  ==============================================================================

    ModelControlPanel.h
    Created: 22 Feb 2025 11:09:46pm
    Author:  levib

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class ModelControlPanel  : public juce::Component
{
public:
    ModelControlPanel();
    ~ModelControlPanel() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ModelControlPanel)
};
