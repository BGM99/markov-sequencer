#include "MarkovModel.h"


MarkovModel::MarkovModel() :
    StateMatrix(nullptr), InitialStateVector(nullptr)
{
}

MarkovModel::~MarkovModel()
{
    delete StateMatrix;
    delete InitialStateVector;
}

void MarkovModel::generateFromSequence(Array<Note> sortedSelection)
{
    if (true)
    {
        generateSingleNoteChain(sortedSelection);
    } else
    {
        generateMultiNoteChain(sortedSelection);
    }

    // Move the states from unordered set to a vector to get a deterministic iteration sequence
    for (int i = 0; i < this->StatesSet.size(); i++)
    {
        auto sound = this->StatesSet.begin();
        std::advance(sound, i);
        this->States.push_back(*sound);
    }

    this->buildMatrix();
    this->buildInitialVector();
}

void MarkovModel::generateSingleNoteChain(const Array<Note>& sortedSelection)
{
    float lastBeat = sortedSelection.getReference(sortedSelection.size() - 1).getBeat();

    for (int i = 0; i < sortedSelection.size() - 1; ++i)
    {
        Note left = sortedSelection.getReference(i);
        Note right = sortedSelection.getReference(i + 1);

        int offset = 0;

        if (left.getBeat() == lastBeat)
        {
            this->StatesSet.insert(left);
            this->SoundFrequency[left] += 1;
            break;
        }

        while (left.getBeat() == right.getBeat())
        {
            offset++;
            right = sortedSelection.getReference(i + offset + 1);
        }

        i += offset;

        this->TransitionFrequency[{left, right}] += 1;
        this->SoundFrequency[left] += 1;
        this->StatesSet.insert(left);
    }
}

void MarkovModel::generateMultiNoteChain(const Array<Note>& sortedSelection)
{
    int i = 0;
    while (i <= sortedSelection.size() - 1)
    {
        std::vector<Note> prev = getAllNotesFromBeat(sortedSelection, i);
        std::vector<Note> next = getAllNotesFromBeat(sortedSelection, i);
        if (i < sortedSelection.size()) {
            i -= next.size();
        } else {
            this->SoundFrequency[next] += 1;
            this->StatesSet.insert(next);
        }

        this->TransitionFrequency[{prev, next}] += 1;

        this->SoundFrequency[prev] += 1;
        this->StatesSet.insert(prev);
    }
}

std::vector<Note> MarkovModel::getAllNotesFromBeat(const Array<Note>& sortedSelection, int& index)
{
    std::vector<Note> chord;
    Note note = sortedSelection.getReference(index);
    chord.push_back(note);
    float beat = note.getBeat();

    while (beat == note.getBeat())
    {
        index++;
        if (index <= sortedSelection.size() - 1 &&
            sortedSelection.getReference(index).getBeat() == beat) {
            note = sortedSelection.getReference(index);
        } else {
            break;
        }
        chord.push_back(note);
    }

    return chord;
}

void MarkovModel::buildMatrix()
{
    this->StateMatrix = new dsp::Matrix<float>(this->Size(), this->Size());

    for (int r = 0; r < this->Size(); ++r)
    {
        auto row = this->States[r];
        int sum = 0;
        for (int c = 0; c < this->Size(); ++c)
        {
            auto col = this->States[c];

            auto it = this->TransitionFrequency.find({row, col});
            if (it != this->TransitionFrequency.end()) {
                sum += it->second;
            }
        }

        if (sum == 0) continue;

        float prob[this->Size()];
        for (int c = 0; c < this->Size(); ++c)
        {
            auto col = this->States[c];
            auto val = this->TransitionFrequency[{row, col}];
            (*this->StateMatrix)(r,c) = static_cast<float>(val) / static_cast<float>(sum);
            prob[c] = static_cast<float>(val) / static_cast<float>(sum);
        }
    }
}

void MarkovModel::buildInitialVector()
{
    float prob[this->Size()];
    this->InitialStateVector = new dsp::Matrix<float>(1, this->Size());
    int sum = 0;
    for (auto it = this->SoundFrequency.begin(); it != this->SoundFrequency.end(); ++it) {
        sum += it->second;
    }

    for (int i = 0; i < this->Size(); ++i)
    {
        auto it = this->SoundFrequency.begin();
        std::advance(it, i);
        (*this->InitialStateVector)(0, i) = static_cast<float>(it->second) / static_cast<float>(sum);
        prob[i] = static_cast<float>(it->second) / static_cast<float>(sum);
    }
}