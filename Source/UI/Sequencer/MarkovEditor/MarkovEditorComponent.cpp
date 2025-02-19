/*
  ==============================================================================

    MarkovEditorComponent.cpp
    Created: 1 Feb 2025 11:23:43pm
    Author:  bg

  ==============================================================================
*/

#include <JuceHeader.h>
#include "MarkovEditorComponent.h"
#include "ProjectNode.h"
#include <HelioTheme.h>
#include "MenuItemComponent.h"

//==============================================================================
MarkovEditorPanel::MarkovEditorPanel(ProjectNode &project) : project(project)
{
    this->setPaintingIsUnclipped(true);

    this->listBox = make<ListBox>();
    this->listBox->setModel(this);
    this->listBox->setMultipleSelectionEnabled(false);
    this->listBox->setRowHeight(Globals::UI::sidebarRowHeight);
    this->listBox->getViewport()->setScrollBarPosition(false, true);
    this->listBox->getViewport()->setScrollOnDragMode(Viewport::ScrollOnDragMode::never);
    this->addAndMakeVisible(this->listBox.get());

    this->setSize(350, 36);
}

MarkovEditorPanel::~MarkovEditorPanel()
{
}

void MarkovEditorPanel::paint (juce::Graphics& g)
{
    Point<int> abc = this->getPosition();
    Rectangle<int> bounds = getLocalBounds();
    int a = getWidth();

    const auto &theme = HelioTheme::getCurrentTheme();
    g.setFillType({ theme.getSidebarBackground(), {} });
    g.fillRect(this->getLocalBounds());

    g.setColour(this->borderLineDark);
    g.fillRect(0, 0, this->getWidth(), 1);

    g.setColour(this->borderLineLight);
    g.fillRect(0, 1, this->getWidth(), 1);

    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (juce::Colours::grey);
    //g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (juce::Colours::white);
    g.setFont (juce::Font (14.0f));
    g.drawText ("MarkovEditorComponent", getLocalBounds(),
                juce::Justification::centred, true);   // draw some placeholder text
}

void MarkovEditorPanel::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..


    constexpr auto toolbarSize = Globals::UI::sidebarWidth;
    constexpr auto headerSize = Globals::UI::rollHeaderHeight;
    constexpr auto footerSize = Globals::UI::sidebarFooterHeight;

    this->listBox->setBounds(this->getWidth() - toolbarSize,
        headerSize - 1,
        toolbarSize,
        this->getHeight() - headerSize - footerSize + 1);
}

int MarkovEditorPanel::getNumRows()
{
    return 0;
}