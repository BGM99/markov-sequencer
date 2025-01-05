/*
    This file is part of Helio music sequencer.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "Common.h"
#include "JuceHeader.h"
#include "juce_dsp/juce_dsp.h"
#include "../../ThirdParty/HopscotchMap/include/tsl/hopscotch_map.h"
#include "Note.h"

#include <cmath>


class MarkovModel {


    struct PairHash {
        std::size_t operator()(const std::pair<Note, Note>& pair) const {
            std::size_t h1 = pair.first.hashCode();
            std::size_t h2 = pair.second.hashCode();
            return h1 ^ (h2 << 1);
        }
    };

    struct SingleHash {
        std::size_t operator()(const Note & note) const {
            return note.hashCode();
        }
    };

    public:
    MarkovModel();
    ~MarkovModel();

    // Counts the Transitions from a Sound Object to another
    // {from, to} -> count
    tsl::hopscotch_map<std::pair<Note, Note>, int, PairHash> TransitionFrequency;

    // Probability matrix based on TransitionFrequency
    dsp::Matrix<float>* StateMatrix;

    // Counts how often a sound object appears
    // {sound} -> count
    tsl::hopscotch_map<Note, int, SingleHash> SoundFrequency;

    // Probability vector based on SoundFrequency and states
    dsp::Matrix<float>* InitialStateVector;

    std::unordered_set<Note, SingleHash> states;

    // Number of all sound objects or states of the model
    int Size() const {
        return static_cast<int>(this->states.size());
    }

    void generateFromSequence(Array<Note> sortedSelection);

    //saveToFile
    //loadFromFile

    private:
    void builtMatrix();
    void builtInitialVector();
};
