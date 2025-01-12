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

    this->buildMatrix();
    this->buildInitialVector();
}

void MarkovModel::buildMatrix()
{
    this->StateMatrix = new dsp::Matrix<float>(this->Size(), this->Size());

    for (int r = 0; r < Size(); ++r)
    {
        auto itRow = this->states.begin();
        std::advance(itRow, r);

        int sum = 0;
        for (int c = 0; c < this->Size(); ++c)
        {
            auto itCol = this->states.begin();
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
            auto itCol = this->states.begin();
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