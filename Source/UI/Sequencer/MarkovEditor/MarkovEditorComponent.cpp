/*
  ==============================================================================

    MarkovEditorComponent.cpp
    Created: 1 Feb 2025 11:23:43pm
    Author:  bg

  ==============================================================================
*/

#include <JuceHeader.h>
#include "MarkovEditorComponent.h"

#include <HelioTheme.h>

//==============================================================================
MarkovEditorComponent::MarkovEditorComponent()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

MarkovEditorComponent::~MarkovEditorComponent()
{
}

void MarkovEditorComponent::paint (juce::Graphics& g)
{
    const auto &theme = HelioTheme::getCurrentTheme();
    g.setFillType({ theme.getSidebarBackground(), {} });
    g.fillRect(this->getLocalBounds());

    g.setColour(this->borderLineDark);
    g.fillRect(0, 0, this->getWidth(), 1);

    g.setColour(this->borderLineLight);
    g.fillRect(0, 1, this->getWidth(), 1);

    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (juce::Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (juce::Colours::white);
    g.setFont (juce::Font (14.0f));
    g.drawText ("MarkovEditorComponent", getLocalBounds(),
                juce::Justification::centred, true);   // draw some placeholder text
}

void MarkovEditorComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
