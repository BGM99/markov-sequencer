//
// Created by bg on 12/22/24.
//

#include "MarkovModel.h"


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
        const int deltaKey = next.getKey() - prev.getKey();



    }

}