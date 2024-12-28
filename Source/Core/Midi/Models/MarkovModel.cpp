//
// Created by bg on 12/22/24.
//

#include "MarkovModel.h"
#include <bits/stdc++.h>


MarkovModel::MarkovModel() :
    SoundMatrix(30, 30)
{
}
void MarkovModel::generateFromSequence(Array<Note> sortedSelection)
{
    for (int i = 0; i < sortedSelection.size() - 1; ++i)
    {
        const auto &prev = sortedSelection.getReference(i);
        const auto &next = sortedSelection.getReference(i + 1);

        this->TransitionFrequency[{prev, next}] += 1;

        this->states.insert(prev);
    }

    this->states.insert(sortedSelection.getReference(sortedSelection.size() - 1));

    int statesCount = this->states.size();

    std::vector<Note> v;
    std::copy(this->states.begin(), this->states.end(), back_inserter(v));

}