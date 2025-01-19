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
            this->States.insert(left);
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
        this->States.insert(left);
    }
}

void MarkovModel::generateMultiNoteChain(const Array<Note>& sortedSelection)
{
    for (int i = 0; i < sortedSelection.size() - 1; ++i)
    {
        Note startNote = sortedSelection.getReference(i);
        std::vector<Note> prev = getAllNotesFromBeat(sortedSelection, startNote.getBeat());
        std::vector<Note> next = getAllNotesFromBeat(sortedSelection, startNote.getBeat() + 1);

        this->TransitionFrequency[{prev, next}] += 1;

        this->SoundFrequency[prev] += 1;

        this->States.insert(prev);
    }

    this->States.insert(getAllNotesFromBeat(sortedSelection, sortedSelection.size() - 1));
}

std::vector<Note> MarkovModel::getAllNotesFromBeat(const Array<Note>& sortedSelection, int index)
{
    std::vector<Note> chord;
    Note prev = sortedSelection.getReference(index);
    Note next = sortedSelection.getReference(index + 1);

    chord.push_back(prev);

    for (int b = index + 2; prev.getBeat() == next.getBeat(); ++b)
    {
        chord.push_back(next);
        next = sortedSelection.getReference(b);
    }

    return chord;
}

void MarkovModel::buildMatrix()
{
    this->StateMatrix = new dsp::Matrix<float>(this->Size(), this->Size());

    for (int r = 0; r < Size(); ++r)
    {
        auto itRow = this->States.begin();
        std::advance(itRow, r);

        int sum = 0;
        for (int c = 0; c < this->Size(); ++c)
        {
            auto itCol = this->States.begin();
            std::advance(itCol, c);

            auto row = *itRow;
            auto col = *itCol;

            auto it = this->TransitionFrequency.find({row, col});
            if (it != this->TransitionFrequency.end()) {
                sum += it->second;
            }
        }

        if (sum == 0) continue;

        float prob[this->Size()];
        for (int c = 0; c < this->Size(); ++c)
        {
            auto itCol = this->States.begin();
            std::advance(itCol, c);

            (*this->StateMatrix)(r,c) = float(this->TransitionFrequency[{*itRow, *itCol}] / sum);
            prob[c] = float(this->TransitionFrequency[{*itRow, *itCol}] / sum);
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

    for (int i = 0; i < Size(); ++i)
    {
        auto it = this->SoundFrequency.begin();
        std::advance(it, i);
        (*this->InitialStateVector)(0, i) = float(it->second / sum);
        prob[i] = float(it->second / sum);
    }
}