/*
  ==============================================================================

    MarkovEditorComponent.cpp
    Created: 1 Feb 2025 11:23:43pm
    Author:  bg

  ==============================================================================
*/

#include <JuceHeader.h>
#include "MarkovEditorPanel.h"
#include "ProjectNode.h"
#include <HelioTheme.h>
#include "MenuItemComponent.h"

#include <SerializationKeys.h>

//==============================================================================
MarkovEditorPanel::MarkovEditorPanel(ProjectNode &project, PianoRoll* roll) : project(project), roll(roll)
{
    this->setPaintingIsUnclipped(true);

    this->listBox = make<TableListBox>();
    this->listBox->setModel(this);
    this->listBox->setMultipleSelectionEnabled(false);
    this->listBox->setRowHeight(65);
    this->listBox->getHeader().setVisible(false);
    this->listBox->getViewport()->setScrollBarPosition(false, true);
    this->listBox->getViewport()->setScrollOnDragMode(Viewport::ScrollOnDragMode::never);
    this->addAndMakeVisible(this->listBox.get());

    this->modelLabel = make<Label>(String("No Model loaded"));
    this->modelLabel->setFont(Globals::UI::Fonts::L);
    this->modelLabel->setBoundsInset(BorderSize(5));
    this->addAndMakeVisible(modelLabel.get());

    this->generateButton = make<TextButton>();
    this->generateButton->setButtonText("Generate Model");
    this->generateButton->setColour (juce::TextButton::buttonColourId, juce::Colours::grey);
    this->generateButton->setColour (juce::Label::textColourId, juce::Colours::white);
    this->generateButton->setBoundsInset(BorderSize(5));
    this->generateButton->onClick = [this] { generateModel(); };
    this->addAndMakeVisible(generateButton.get());

    this->loadModelButton = make<TextButton>();
    this->loadModelButton->setButtonText("Load Model");
    this->loadModelButton->setColour (juce::TextButton::buttonColourId, juce::Colours::grey);
    this->loadModelButton->setColour (juce::Label::textColourId, juce::Colours::white);
    this->loadModelButton->setBoundsInset(BorderSize(5));
    this->loadModelButton->onClick = [this] { loadModelFromFile(); };
    this->addAndMakeVisible(loadModelButton.get());

    this->saveModelButton = make<TextButton>();
    this->saveModelButton->setButtonText("Save Model");
    this->saveModelButton->setColour (juce::TextButton::buttonColourId, juce::Colours::grey);
    this->saveModelButton->setColour (juce::Label::textColourId, juce::Colours::white);
    this->saveModelButton->setBoundsInset(BorderSize(5));
    this->saveModelButton->onClick = [this] { saveModelToFile(); };
    this->addAndMakeVisible(saveModelButton.get());
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

    Rectangle<int> localBounds = getLocalBounds();

    Rectangle<int> modelControlBounds = localBounds.removeFromLeft(150);
    modelLabel.get()->setBounds(modelControlBounds.removeFromTop(20));
    generateButton.get()->setBounds(modelControlBounds.removeFromTop(20));
    loadModelButton.get()->setBounds(modelControlBounds.removeFromTop(20));
    saveModelButton.get()->setBounds(modelControlBounds.removeFromTop(20));

    Rectangle<int> editorControlBounds = modelControlBounds.removeFromRight(100);

    this->listBox->setBounds(localBounds);
}
void MarkovEditorPanel::paintCell(Graphics & g, int rowNumber, int columnId, int width, int height, bool rowIsSelected)
{
    if (this->rowVector[this->currentState].size() < columnId) return;

    auto entry = this->rowVector[this->currentState][columnId - 1];
    float prob = entry.first;
    Sound sound = this->currentModel.States[entry.second];

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

    std::ostringstream stream;
    stream << std::fixed << std::setprecision(1) << (prob * 100) << "%";
    probText.append(stream.str(), 10);

    g.setColour (juce::Colours::white);
    g.setFont (Globals::UI::Fonts::M);
    g.drawText (probText, 0,0, width, height,
                juce::Justification::centred, true);

    g.setFont (Globals::UI::Fonts::XS);
    g.drawText (noteNames, 0,0, width, height,
                juce::Justification::centredBottom, true);

    g.setColour (this->selectedCell == columnId ? Colours::plum : Colours::white);
    g.drawRect (0, 0, width, height, 1);   // draw an outline around the component
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

    g.fillAll(Colours::darkgrey);
}

void MarkovEditorPanel::cellClicked(int rowNumber, int columnId, const MouseEvent &mouse_event)
{
    if (this->selectedCell != -1)
    {
        this->modifyTrackSoundObject(false, this->selectedCell - 1, this->currentInsertBeat, false);
    }

    this->selectedCell = columnId;

    this->modifyTrackSoundObject(true, columnId - 1, this->currentInsertBeat, false);

    this->listBox->repaint();
}

void MarkovEditorPanel::cellDoubleClicked(int rowNumber, int columnId, const MouseEvent &mouse_event)
{
    this->selectedCell = -1;
    this->currentState = columnId - 1;

    float length = 0;

    length = this->modifyTrackSoundObject(true, this->currentState, this->currentInsertBeat, true);

    this->currentInsertBeat += length;

    this->listBox->repaint();
}

void MarkovEditorPanel::generateModel()
{
    const auto * sequence = dynamic_cast<PianoSequence *>(this->roll->getActiveTrack().get()->getSequence());
    if (sequence == nullptr) {
        return;
    }

    Array<Note> sortedSelection;
    for (int i = 0; i < sequence->size(); ++i) {
        const auto &note = sequence->getNoteUnchecked(i);
        sortedSelection.addSorted(note, note);
    }

    auto mm = new MarkovModel();
    mm->generateFromSequence(sortedSelection);
    this->currentModel = *mm;

    for (int r = 0; r < mm->Size(); ++r) {
        for (int c = 0; c < mm->Size(); ++c) {
            if ((*mm->StateMatrix)(r, c) != 0.0f) {
                this->rowVector[r].emplace_back((*mm->StateMatrix)(r, c), c);
            }
        }

        std::sort(this->rowVector[r].begin(), this->rowVector[r].end(), [](const auto& a, const auto& b) {
            return a.first > b.first;
        });
    }

    for (int c = 0; c < mm->Size(); ++c) {
        if ((*mm->InitialStateVector)(0, c) != 0.0f) {
            this->rowVector[-1].emplace_back((*mm->InitialStateVector)(0, c), c);
        }
    }

    std::sort(this->rowVector[-1].begin(), this->rowVector[-1].end(), [](const auto& a, const auto& b) {
        return a.first > b.first;
    });

    this->currentState = -1;

    createColumns(mm->Size());
}

void MarkovEditorPanel::loadModelFromFile()
{
}
void MarkovEditorPanel::saveModelToFile()
{
}

void MarkovEditorPanel::createColumns(int n)
{
    this->listBox->getHeader().removeAllColumns();

    for (int i = 1; i <= n; i++)
    {
        this->listBox->getHeader().addColumn("", i, 70);
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

float MarkovEditorPanel::modifyTrackSoundObject(bool insert, int objectIndex, float beat, bool checkpoint)
{
    auto *sequence = dynamic_cast<PianoSequence *>(this->roll->getActiveTrack().get()->getSequence());
    if (sequence == nullptr)
    {
        return 0;
    }

    Sound sound = this->currentModel.States[objectIndex];
    Array<Note> notes;
    float length = 0;

    if (std::holds_alternative<Note>(sound))
    {
        Note note = std::get<Note>(sound).withBeat(beat);
        notes.add(checkpoint ? note.withNewId(sequence) : note);
        length = note.getLength();
    }
    else if (std::holds_alternative<std::vector<Note>>(sound))
    {
        auto noteList = std::get<std::vector<Note>>(sound);
        float startBeat = noteList.front().getBeat();
        for (const auto &note : noteList)
        {
            notes.add(note.withBeat(note.getBeat() - startBeat + beat));
            length += note.getLength();
        }
    }
    else if (std::holds_alternative<float>(sound))
    {
        //this->currentInsertBeat += insert ? std::get<float>(sound) : -std::get<float>(sound);
        length = std::get<float>(sound);
    }

    if (checkpoint) sequence->checkpoint();

    if (insert)
    {
        sequence->insertGroup(notes, checkpoint);
    }
    else
    {
        sequence->removeGroup(notes, checkpoint);
    }
    return length;
}
