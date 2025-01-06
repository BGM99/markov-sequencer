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
    for (int i = 0; i < sortedSelection.size() - 1; ++i)
    {
        Note prev = sortedSelection.getReference(i);
        Note next = sortedSelection.getReference(i + 1);

        this->TransitionFrequency[{prev, next}] += 1;

        this->SoundFrequency[prev] += 1;

        this->states.insert(prev);
    }

    this->states.insert(sortedSelection.getReference(sortedSelection.size() - 1));
    this->SoundFrequency[sortedSelection.getReference(sortedSelection.size() - 1)] += 1;

    //this->builtMatrix();
    this->builtInitialVector();
}

void MarkovModel::builtMatrix()
{
    this->StateMatrix = new dsp::Matrix<float>(this->Size(), this->Size());

    for (int i = 0; i < this->StateMatrix->getNumColumns(); ++i)
    {
        int l = (*this->StateMatrix)(0, i);
    }

    for (auto note : this->states)
    {
        for (auto state : this->states)
        {
            int test = this->TransitionFrequency[{state, note}];
        }
    }
}

void MarkovModel::builtInitialVector()
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
        (*this->InitialStateVector)(0, i) = it->second / sum;
        prob[i] = (float) it->second / sum;
    }
}