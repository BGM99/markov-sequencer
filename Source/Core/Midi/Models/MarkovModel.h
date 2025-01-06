#pragma once

#include "Common.h"
#include "JuceHeader.h"
#include "juce_dsp/juce_dsp.h"
#include "../../ThirdParty/HopscotchMap/include/tsl/hopscotch_map.h"
#include "Note.h"

#include <cmath>


class MarkovModel {

    template <class T>
    static void hash_combine(std::size_t& seed, const T& v) noexcept
    {
        std::hash<T> hasher;
        seed ^= hasher(v) + 0x9e3779b9 + (seed<<6) + (seed>>2);
    }

    struct NoteHash {
        std::size_t operator()(const Note & note) const {
            HashCode result = 0;
            hash_combine(result, note.getKey());
            //hash_combine(result, int(this->beat * Globals::ticksPerBeat));
            hash_combine(result, int(note.getLength() * Globals::ticksPerBeat));
            return result;
        }
    };

    struct PairHash {
        std::size_t operator()(const std::pair<Note, Note>& pair) const {
            HashCode result = 0;
            NoteHash hasher;
            hash_combine(result, hasher(pair.first));
            hash_combine(result, hasher(pair.second));
            return result;
        }
    };

    struct NoteEqual {
        bool operator()(const Note &lhs, const Note &rhs) const
        {
            return lhs.getKey() == rhs.getKey() && lhs.getLength() == rhs.getLength();
        }
    };

    struct PairEqual {
        bool operator()(const std::pair<Note, Note> &pair1, const std::pair<Note, Note> &pair2) const {
            NoteEqual equal;
            return equal(pair1.first, pair2.first) && equal(pair1.second, pair2.second);
        }
    };

    public:
    MarkovModel();
    ~MarkovModel();

    // Counts the Transitions from a Sound Object to another
    // {from, to} -> count
    std::unordered_map<std::pair<Note, Note>, int, PairHash, PairEqual> TransitionFrequency;

    // Probability matrix based on TransitionFrequency
    dsp::Matrix<float>* StateMatrix;

    // Counts how often a sound object appears
    // {sound} -> count
    std::unordered_map<Note, int, NoteHash, NoteEqual> SoundFrequency;

    // Probability vector based on SoundFrequency and states
    dsp::Matrix<float>* InitialStateVector;

    std::unordered_set<Note, NoteHash, NoteEqual> states;

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
