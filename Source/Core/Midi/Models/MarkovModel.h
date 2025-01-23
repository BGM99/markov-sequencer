#pragma once

#include "Common.h"
#include "JuceHeader.h"
#include "juce_dsp/juce_dsp.h"
#include "../../ThirdParty/HopscotchMap/include/tsl/hopscotch_map.h"
#include "Note.h"
#include <variant>

#include <cmath>


class MarkovModel {
    // Sound Object is either a single Note, multiple Notes or Rest
    using Sound = std::variant<Note, std::vector<Note>, float>;
    // Rest is characterized by its length (float)

    template <class T>
    constexpr static void hash_combine(std::size_t& seed, const T& v) noexcept
    {
        std::hash<T> hasher;
        seed ^= hasher(v) + 0x9e3779b9 + (seed<<6) + (seed>>2);
    }

    constexpr static void hash_note(std::size_t& seed, const Note& n) noexcept
    {
        hash_combine(seed, n.getKey());
        //hash_combine(result, int(this->beat * Globals::ticksPerBeat));
        hash_combine(seed, int(n.getLength() * Globals::ticksPerBeat));
    }

    struct SoundHash {
        std::size_t operator()(const Sound & sound) const {
            HashCode result = 0;
            if (std::holds_alternative<Note>(sound)) {
                hash_note(result, std::get<Note>(sound));
            } else if (std::holds_alternative<std::vector<Note>>(sound)) {
                for (const auto& note : std::get<std::vector<Note>>(sound)) {
                    hash_note(result, note);
                }
            } else if (std::holds_alternative<float>(sound)) {
                constexpr std::hash<float> hasher;
                result = hasher(std::get<float>(sound));
            }
            return result;
        }
    };

    struct PairHash {
        std::size_t operator()(const std::pair<Sound, Sound>& pair) const {
            HashCode result = 0;
            constexpr SoundHash hasher;
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

    struct SoundEqual
    {
        bool operator()(const Sound &lhs, const Sound &rhs) const
        {
            NoteEqual equal;
            if (std::holds_alternative<Note>(lhs) && std::holds_alternative<Note>(rhs)) {
                return equal(std::get<Note>(lhs), std::get<Note>(rhs));
            } if (std::holds_alternative<std::vector<Note>>(lhs)
                && std::holds_alternative<std::vector<Note>>(rhs))
            {
                auto left = std::get<std::vector<Note>>(lhs).begin();
                auto right = std::get<std::vector<Note>>(rhs).begin();
                for (int i = 0; i < std::get<std::vector<Note>>(rhs).size(); ++i)
                {
                    std::advance(left, i);
                    std::advance(right, i);
                    if (!equal(*left, *right))
                    {
                        return false;
                    }
                }
                return true;
            } if (std::holds_alternative<float>(lhs)
                && std::holds_alternative<float>(rhs))
            {
                return std::get<float>(lhs) == std::get<float>(rhs);
            }
            return false;
        }
    };

    struct PairEqual {
        bool operator()(const std::pair<Sound, Sound> &pair1, const std::pair<Sound, Sound> &pair2) const {
            constexpr SoundEqual equal;
            return equal(pair1.first, pair2.first) && equal(pair1.second, pair2.second);
        }
    };

    public:
    MarkovModel();
    ~MarkovModel();

    // Counts the Transitions from a Sound Object to another
    // {from, to} -> count
    std::unordered_map<std::pair<Sound, Sound>, int, PairHash, PairEqual> TransitionFrequency;

    // Probability matrix based on TransitionFrequency
    dsp::Matrix<float>* StateMatrix;

    // Counts how often a sound object appears
    // {sound} -> count
    std::unordered_map<Sound, int, SoundHash, SoundEqual> SoundFrequency;

    // Probability vector based on SoundFrequency and states
    dsp::Matrix<float>* InitialStateVector;

    // All Sound Objects of the Chain
    std::unordered_set<Sound, SoundHash, SoundEqual> States;

    // Number of all sound objects or states of the model
    int Size() const {
        return static_cast<int>(this->States.size());
    }

    void generateFromSequence(Array<Note> sortedSelection);

    //saveToFile
    //loadFromFile

    private:

    // Use only single Notes for the Model (ignores Chords)
    void generateSingleNoteChain(const Array<Note>& sortedSelection);

    // Use Arrays of Notes for the Model
    void generateMultiNoteChain(const Array<Note>& sortedSelection);

    // Collects all Notes that start at the same beat in an array
    static std::vector<Note> getAllNotesFromBeat(const Array<Note>& sortedSelection, int& index);

    void buildMatrix();
    void buildInitialVector();
};
