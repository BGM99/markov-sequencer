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

#include <SerializationKeys.h>

//==============================================================================
MarkovEditorPanel::MarkovEditorPanel(ProjectNode &project) : project(project)
{
    this->setPaintingIsUnclipped(true);

    this->listBox = make<TableListBox>();
    this->listBox->setModel(this);
    this->listBox->setMultipleSelectionEnabled(false);
    this->listBox->setRowHeight(45);
    this->listBox->getHeader().setVisible(false);
    this->listBox->getViewport()->setScrollBarPosition(false, true);
    this->listBox->getViewport()->setScrollOnDragMode(Viewport::ScrollOnDragMode::never);
    this->addAndMakeVisible(this->listBox.get());
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
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

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

    this->listBox->setBounds(getLocalBounds());
}
void MarkovEditorPanel::paintCell(Graphics & g, int rowNumber, int columnId, int width, int height, bool rowIsSelected)
{
    float prob = this->items[rowNumber].first;
    Sound sound = this->items[rowNumber].second;

    String probText = "";
    String noteNames = "";

    if (std::holds_alternative<Note>(sound))
    {
        Note note = std::get<Note>(sound);
        noteNames.append(midiNoteToString(note.getKey()), 5);
        noteNames.append(std::to_string(note.getLength()), 5);
        
    } else if (std::holds_alternative<std::vector<Note>>(sound))
    {
        for (const auto &note : std::get<std::vector<Note>>(sound))
        {
            noteNames.append(midiNoteToString(note.getKey()), 5);
            noteNames.append(", ", 5);
            noteNames.append(std::to_string(note.getLength()), 5);
        }
    } else if (std::holds_alternative<float>(sound))
    {
        noteNames.append("Rest, ", 10);
        noteNames.append(std::to_string(std::get<float>(sound)), 4);
    }

    probText.append(std::to_string(prob), 4);
    probText.append("%", 4);

    g.setColour (juce::Colours::white);
    g.setFont (Globals::UI::Fonts::M);
    g.drawText (probText, 0,0, width, height,
                juce::Justification::centred, true);

    g.setFont (Globals::UI::Fonts::XS);
    g.drawText (noteNames, 0,0, width, height,
                juce::Justification::centredBottom, true);
}

void MarkovEditorPanel::paintRowBackground(Graphics &g, int rowNumber, int width, int height, bool rowIsSelected)
{
    // const auto &theme = HelioTheme::getCurrentTheme();
    // g.setFillType({theme.getPageBackgroundB(), {}});
    // g.fillRect(0, 0, width, height);

    g.setColour(this->borderLineDark);
    g.fillRect(0, 0, width, 1);

    g.setColour(this->borderLineLight);
    g.fillRect(0, 1, width, 1);

    g.fillAll(juce::Colours::darkgrey);
}

void MarkovEditorPanel::createColumns(int n)
{
    this->listBox->getHeader().removeAllColumns();

    for (int i = 0; i < n; i++)
    {
        this->listBox->getHeader().addColumn("", n, 150);
    }

    this->listBox->updateContent();
}

String MarkovEditorPanel::midiNoteToString(int midiKey) {
    if (midiKey < 0 || midiKey > 127) {
        return "Invalid MIDI key";
    }

    const std::string noteNames[] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
    int noteIndex = midiKey % 12;
    int octave = (midiKey / 12) - 1;

    return noteNames[noteIndex] + std::to_string(octave);
}