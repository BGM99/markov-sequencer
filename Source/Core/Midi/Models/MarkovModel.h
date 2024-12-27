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

#include "JuceHeader.h"
#include "juce_dsp/juce_dsp.h"
#include "../../ThirdParty/HopscotchMap/include/tsl/hopscotch_map.h"
#include "Note.h"
#include "PianoSequence.h"

#include <cmath>



class MarkovModel {

    struct PairHash {
        std::size_t operator()(const std::pair<PianoSequence, PianoSequence>& pair) const {
            std::size_t h1 = pair.first.hashCode();
            std::size_t h2 = pair.second.hashCode();
            return h1 ^ (h2 << 1); // Kombiniert die Hashes von first und second
        }
    };

    template <class Key, class T, class HashFn = PairHash, class EqualKey = std::equal_to<Key>>
    using FlatHashMap = tsl::hopscotch_map<Key, T, HashFn, EqualKey>;

    public:
    MarkovModel();

    //Count the Transitions from a Sound Object to another
    // {from, to} -> count
    FlatHashMap<std::pair<PianoSequence, PianoSequence>, int> TransitionFrequency;

    dsp::Matrix<int> SoundMatrix;
    Array<PianoSequence> states;

    void generateFromSequence(Array<Note> sortedSelection);

    private:

    //dsp::Matrix
    //createFromTrack
    //saveToFile
    //loadFromFile
};
