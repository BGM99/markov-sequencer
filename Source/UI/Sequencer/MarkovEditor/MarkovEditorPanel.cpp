/*
  ==============================================================================

    MarkovEditorComponent.cpp
    Created: 1 Feb 2025 11:23:43pm
    Author:  bg

  ==============================================================================
*/

#include "MarkovEditorPanel.h"
#include "ProjectNode.h"
#include "MenuItemComponent.h"
#include <JuceHeader.h>
#include <PianoRoll.h>
#include <HelioTheme.h>
#include <random>

//==============================================================================
MarkovEditorPanel::MarkovEditorPanel(ProjectNode &project, PianoRoll *roll) :
    project(project), roll(roll)
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

    // Model Controls
    this->modelLabel = make<Label>(String("No Model loaded"));
    this->modelLabel->setFont(Globals::UI::Fonts::L);
    this->modelLabel->setBoundsInset(BorderSize(5));
    this->addAndMakeVisible(modelLabel.get());

    this->generateButton = make<TextButton>();
    this->generateButton->setButtonText("Generate Model");
    this->generateButton->setColour(juce::TextButton::buttonColourId, juce::Colours::grey);
    this->generateButton->setColour(juce::Label::textColourId, juce::Colours::white);
    this->generateButton->setBoundsInset(BorderSize(5));
    this->generateButton->onClick = [this] { generateModel(); };
    this->addAndMakeVisible(generateButton.get());

    this->loadModelButton = make<TextButton>();
    this->loadModelButton->setButtonText("Load Model");
    this->loadModelButton->setColour(juce::TextButton::buttonColourId, juce::Colours::grey);
    this->loadModelButton->setColour(juce::Label::textColourId, juce::Colours::white);
    this->loadModelButton->setBoundsInset(BorderSize(5));
    this->loadModelButton->onClick = [this] { loadModelFromFile(); };
    this->addAndMakeVisible(loadModelButton.get());

    this->saveModelButton = make<TextButton>();
    this->saveModelButton->setButtonText("Save Model");
    this->saveModelButton->setColour(juce::TextButton::buttonColourId, juce::Colours::grey);
    this->saveModelButton->setColour(juce::Label::textColourId, juce::Colours::white);
    this->saveModelButton->setBoundsInset(BorderSize(5));
    this->saveModelButton->onClick = [this] { saveModelToFile(); };
    this->addAndMakeVisible(saveModelButton.get());

    // Editor Controls
    this->navigatePrevious = make<IconButton>(Icons::findByName(Icons::back, 32), CommandIDs::MovePreviousState);
    this->addAndMakeVisible(this->navigatePrevious.get());

    this->navigateNext = make<IconButton>(Icons::findByName(Icons::forward, 32), CommandIDs::MoveNextState);
    this->navigateNext->setEnabled(true);
    this->addAndMakeVisible(this->navigateNext.get());

    this->updateState();
}

MarkovEditorPanel::~MarkovEditorPanel()
{
}

float MarkovEditorPanel::getCurrentInsertBeat()
{
    return roll->markovInsertBeat.getValue();
}

void MarkovEditorPanel::setCurrentInsertBeat(float newValue)
{
    return roll->markovInsertBeat.setValue(newValue);
}

void MarkovEditorPanel::paint(juce::Graphics &g)
{
    const auto &theme = HelioTheme::getCurrentTheme();
    // g.setFillType({theme.getSidebarBackground(), {}});
    //   g.fillRect(this->getLocalBounds());
    g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));

    g.setColour(this->borderLineDark);
    g.fillRect(0, 0, this->getWidth(), 1);

    g.setColour(this->borderLineLight);
    g.fillRect(0, 1, this->getWidth(), 1);

    g.setColour(juce::Colours::grey);
    g.drawRect(getLocalBounds(), 1); // draw an outline around the component

    g.setColour(juce::Colours::white);
    g.setFont(juce::Font(14.0f));
    g.drawText("MarkovEditorComponent", getLocalBounds(),
        juce::Justification::centred, true); // draw some placeholder text
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

    Rectangle<int> editorControlBounds = localBounds.removeFromRight(100);
    Rectangle<int> navigationPanel = editorControlBounds.removeFromTop(50);
    navigationPanel.removeFromRight(30);
    navigateNext.get()->setBounds(navigationPanel.removeFromRight(20));
    navigatePrevious.get()->setBounds(navigationPanel.removeFromRight(20));

    this->listBox->setBounds(localBounds);
}

void MarkovEditorPanel::handleCommandMessage(int commandId)
{
    switch (commandId)
    {
        case CommandIDs::MoveNextState:
            moveNextState();
            break;
        case CommandIDs::MovePreviousState:
            if (this->canMovePreviousState())
            {
                movePreviousState();
            }
            break;
        default:
            return;
            break;
    }
}

void MarkovEditorPanel::paintCell(Graphics &g, int rowNumber, int columnId, int width, int height, bool rowIsSelected)
{
    if (this->rowVector[this->currentState].size() < columnId)
        return;

    auto entry = this->rowVector[this->currentState][columnId - 1];
    float prob = entry.first;
    Sound sound = this->currentModel.States[entry.second];

    String probText = "";
    String noteNames = "";
    std::ostringstream stream;

    bool moreThanTwoNotes = false;

    if (std::holds_alternative<Note>(sound))
    {
        Note note = std::get<Note>(sound);
        noteNames.append(midiNoteToString(note.getKey()), 5);
        noteNames.append(", ", 5);
        stream << std::fixed << std::setprecision(1) << note.getLength() << std::endl;
        noteNames.append(stream.str(), 5);
        stream.str("");
    }
    else if (std::holds_alternative<std::vector<Note>>(sound))
    {
        moreThanTwoNotes = std::get<std::vector<Note>>(sound).size() > 2;
        for (const auto &note : std::get<std::vector<Note>>(sound))
        {
            noteNames.append(midiNoteToString(note.getKey()), 5);
            noteNames.append(", ", 5);
            stream << std::fixed << std::setprecision(1) << note.getLength() << std::endl;
            noteNames.append(stream.str(), 5);
            stream.str("");
        }
    }
    else if (std::holds_alternative<float>(sound))
    {
        noteNames.append("Rest, ", 10);
        noteNames.append(std::to_string(std::get<float>(sound)), 4);
    }

    stream << std::fixed << std::setprecision(1) << (prob * 100) << "%";
    probText.append(stream.str(), 10);

    g.setColour(juce::Colours::white);
    moreThanTwoNotes ? g.setFont(Globals::UI::Fonts::XS) : g.setFont(Globals::UI::Fonts::S);

    g.drawFittedText(noteNames, 0, 0, width, height,
        juce::Justification::centred,
        3,   // max rows
        1.0f // scale factor
    );

    g.setFont(Globals::UI::Fonts::XS);
    g.drawText(probText, 0, 0, width, height,
        juce::Justification::centredBottom, true);

    g.setColour(this->selectedCell == columnId ? Colours::plum : Colours::white);
    g.drawRect(0, 0, width, height, 1); // draw an outline around the component
}

void MarkovEditorPanel::paintRowBackground(Graphics &g, int rowNumber, int width, int height, bool rowIsSelected)
{
    const auto &theme = HelioTheme::getCurrentTheme();
    g.setFillType({theme.getPageBackgroundB(), {}});
    g.fillRect(0, 0, width, height);

    g.setColour(this->borderLineDark);
    g.fillRect(0, 0, width, 1);

    g.setColour(this->borderLineLight);
    g.fillRect(0, 1, width, 1);
}

void MarkovEditorPanel::removeSelectedNotes()
{
    if (this->selectedCell != -1)
    {
        int removeIndex = this->rowVector[this->currentState][this->selectedCell - 1].second;
        this->modifyTrackSoundObject(false, removeIndex, this->getCurrentInsertBeat(), false);
    }
}

int MarkovEditorPanel::getRandomSoundObject()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(0.0f, 1.0f);

    float random = dis(gen);

    std::vector<float> cumulativeSums;
    cumulativeSums.reserve(this->rowVector[this->currentState].size());

    float sum = 0.0f;
    for (const auto &[prob, _] : this->rowVector[this->currentState])
    {
        sum += prob;
        cumulativeSums.push_back(sum);
    }

    int index = this->findNearestAbove(cumulativeSums, random);
    return this->rowVector[this->currentState][index].second;
}

void MarkovEditorPanel::cellClicked(int rowNumber, int columnId, const MouseEvent &mouse_event)
{
    if (this->rowVector[this->currentState].size() < columnId)
        return;

    int index = this->rowVector[this->currentState][columnId - 1].second;

    if (this->selectedCell == columnId)
    {
        this->selectedCell = -1;
        this->modifyTrackSoundObject(false, index, this->getCurrentInsertBeat(), false);
    }
    else
    {
        removeSelectedNotes();
        this->selectedCell = columnId;
        this->modifyTrackSoundObject(true, index, this->getCurrentInsertBeat(), false);
    }

    this->listBox->repaint();
}

void MarkovEditorPanel::cellDoubleClicked(int rowNumber, int columnId, const MouseEvent &mouse_event)
{
    if (this->rowVector[this->currentState].size() < columnId)
        return;

    int index = this->rowVector[this->currentState][columnId - 1].second;

    removeSelectedNotes();

    float length = 0;

    length = this->modifyTrackSoundObject(true, index, this->getCurrentInsertBeat(), true);

    this->setCurrentInsertBeat(this->getCurrentInsertBeat() + length);

    this->selectedCell = -1;
    this->currentState = index;
    this->updateState();
    this->listBox->repaint();
}

void MarkovEditorPanel::updateState()
{
    auto canGoPrevious = canMovePreviousState();
    this->navigatePrevious->setInterceptsMouseClicks(canGoPrevious, false);
    this->navigatePrevious->setIconAlphaMultiplier(canGoPrevious ? 1.0f : 0.4f);
}

bool MarkovEditorPanel::canMovePreviousState() const
{
    return !this->insertedSounds.empty();
}

void MarkovEditorPanel::movePreviousState()
{
    removeSelectedNotes();

    auto notes = std::get<1>(this->insertedSounds.top());

    auto *sequence = dynamic_cast<PianoSequence *>(this->roll->getActiveTrack().get()->getSequence());
    if (sequence == nullptr)
    {
        return;
    }

    sequence->removeGroup(notes, true);

    this->setCurrentInsertBeat(this->getCurrentInsertBeat() - std::get<2>(this->insertedSounds.top()));
    this->currentState = std::get<0>(this->insertedSounds.top());
    this->selectedCell = -1;

    this->insertedSounds.pop();
    this->updateState();
    this->listBox->repaint();
}

void MarkovEditorPanel::moveNextState()
{
    removeSelectedNotes();

    int index = getRandomSoundObject();

    float length = 0;

    length = this->modifyTrackSoundObject(true, index, this->getCurrentInsertBeat(), true);

    this->setCurrentInsertBeat(this->getCurrentInsertBeat() + length);

    this->selectedCell = -1;
    this->currentState = index;
    this->updateState();
    this->listBox->repaint();
}

void MarkovEditorPanel::generateModel()
{
    const auto *sequence = dynamic_cast<PianoSequence *>(this->roll->getActiveTrack().get()->getSequence());
    if (sequence == nullptr)
    {
        return;
    }

    Array<Note> sortedSelection;
    for (int i = 0; i < sequence->size(); ++i)
    {
        const auto &note = sequence->getNoteUnchecked(i);
        sortedSelection.addSorted(note, note);
    }

    auto mm = new MarkovModel();
    mm->generateFromSequence(sortedSelection);
    this->currentModel = *mm;

    for (int r = 0; r < mm->Size(); ++r)
    {
        for (int c = 0; c < mm->Size(); ++c)
        {
            if ((*mm->StateMatrix)(r, c) != 0.0f)
            {
                this->rowVector[r].emplace_back((*mm->StateMatrix)(r, c), c);
            }
        }

        std::sort(this->rowVector[r].begin(), this->rowVector[r].end(), [](const auto &a, const auto &b) {
            return a.first > b.first;
        });
    }

    for (int c = 0; c < mm->Size(); ++c)
    {
        if ((*mm->InitialStateVector)(0, c) != 0.0f)
        {
            this->rowVector[-1].emplace_back((*mm->InitialStateVector)(0, c), c);
        }
    }

    std::sort(this->rowVector[-1].begin(), this->rowVector[-1].end(), [](const auto &a, const auto &b) {
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

String MarkovEditorPanel::midiNoteToString(int midiKey)
{
    if (midiKey < 0 || midiKey > 127)
    {
        return "Invalid MIDI key";
    }

    const std::string noteNames[] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
    int noteIndex = midiKey % 12;
    int octave = (midiKey / 12) - 1;

    return noteNames[noteIndex] + std::to_string(octave);
}

int MarkovEditorPanel::findNearestAbove(const std::vector<float> &v, float target)
{
    float minDiff = std::numeric_limits<float>::max();
    int index = -1; // -1 if no value found

    for (size_t i = 0; i < v.size(); ++i)
    {
        float diff = v[i] - target;
        if (diff > 0 && diff < minDiff)
        {
            minDiff = diff;
            index = i;
        }
    }

    return index;
}

float MarkovEditorPanel::modifyTrackSoundObject(bool insert, int objectIndex, float beat, bool checkpoint)
{
    auto *sequence = dynamic_cast<PianoSequence *>(this->roll->getActiveTrack().get()->getSequence());
    if (sequence == nullptr || objectIndex == -1)
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

        auto min_it = std::min_element(noteList.begin(), noteList.end(),
            [](const Note &a, const Note &b) {
                return a.getBeat() < b.getBeat();
            });

        float startBeat = min_it->getBeat();

        for (const auto &note : noteList)
        {
            auto n = note.withBeat(note.getBeat() - startBeat + beat);
            notes.add(checkpoint ? n.withNewId(sequence) : n);
            length = std::max(length, note.getBeat() + note.getLength() - startBeat);
        }
    }
    else if (std::holds_alternative<float>(sound))
    {
        length = std::get<float>(sound);
    }

    if (checkpoint) sequence->checkpoint();

    if (insert)
    {
        if (checkpoint) this->insertedSounds.push({this->currentState, notes, length});
        sequence->insertGroup(notes, checkpoint);
    }
    else
    {
        sequence->removeGroup(notes, checkpoint);
        if (checkpoint) this->insertedSounds.pop();
    }
    return length;
}