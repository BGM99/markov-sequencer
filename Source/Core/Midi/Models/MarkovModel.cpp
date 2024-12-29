#include "MarkovModel.h"


MarkovModel::MarkovModel() :
    SoundMatrix(nullptr)
{
}

MarkovModel::~MarkovModel()
{
    delete SoundMatrix;
}

void MarkovModel::generateFromSequence(Array<Note> sortedSelection)
{
    for (int i = 0; i < sortedSelection.size() - 1; ++i)
    {
        auto prev = sortedSelection.getReference(i);
        auto next = sortedSelection.getReference(i + 1);

        this->TransitionFrequency[{prev, next}] += 1;

        this->states.insert(prev);
    }

    this->states.insert(sortedSelection.getReference(sortedSelection.size() - 1));

    int statesCount = this->states.size();

    //std::vector<Note> v;
    //std::copy(this->states.begin(), this->states.end(), back_inserter(v));

    this->builtMatrix();
}

void MarkovModel::builtMatrix()
{
    this->SoundMatrix = new dsp::Matrix<int>(this->states.size(), this->states.size());

    for (int i = 0; i < this->SoundMatrix->getNumColumns(); ++i)
    {
        int l = (*this->SoundMatrix)(0, i);
    }

    for (auto note : this->states)
    {
        for (auto state : this->states)
        {
            int test = this->TransitionFrequency[{state, note}];
        }
    }
}