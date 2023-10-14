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

#include "Note.h"
#include "Scale.h"
#include "Temperament.h"
#include "ConfigurationResource.h"

// Arpeggiators are created by user simply as a sequences within a scale.
// Depending on arp type, it has a mapping from that sequence's space into target chord space,
// so that the chord transformation becomes as straightforward as
// iterating through arp's sequence and inserting a transformed note for each arp's key.

// This effectively allows to use any melody/sequence as an arpeggiator
// (the only assumption is that it has no non-scale keys within, which will be ignored),
// with no restrictions on a target chord's scale.

// Which opens huge possibilities for experimentation,
// like using an arpeggiated chord as a new arpeggiator, and so on.
// See DiatonicArpMapper implementation for the most common mapping example.

class Arpeggiator final : public ConfigurationResource
{
public:

    Arpeggiator() = default;
    Arpeggiator(const String &name, 
        const Temperament::Ptr temperament,
        const Scale::Ptr scale,
        const Array<Note> &sequence,
        Note::Key rootKey);

    using Ptr = ReferenceCountedObjectPtr<Arpeggiator>;

    String getName() const noexcept { return this->name; };
    bool isValid() const noexcept { return !this->keys.isEmpty(); }

    float getSequenceLength() const;

    int getNumKeys() const noexcept;
    bool isKeyIndexValid(int index) const noexcept;

    float getBeatFor(int arpKeyIndex) const noexcept;
    Note mapArpKeyIntoChordSpace(const Temperament::Ptr temperament,
        int arpKeyIndex, float startBeat,
        const Array<Note> &chord, const Scale::Ptr chordScale, Note::Key chordRoot,
        bool reversed, float durationMultiplier = 1.f, float randomness = 0.f) const;

    Arpeggiator &operator=(const Arpeggiator &other);
    friend bool operator==(const Arpeggiator &l, const Arpeggiator &r);
    
    //===------------------------------------------------------------------===//
    // Internal
    //===------------------------------------------------------------------===//

    struct Key final : public Serializable
    {
        Key() = default;
        Key(int key, int period, float beat, float length, float velocity) noexcept :
            key(key), period(period), beat(beat), length(length), velocity(velocity) {}

        // Key, relative to the root note, and translated into scale, may be negative
        int key;
        // Number of periods to offset, relative to root key, may be negative
        // We cannot keep this info in a key, as target chord's scale might have different period
        int period;
        // Velocity and length parameters is the same as for note
        float velocity;
        float length;
        // Beat is relative to sequence start (i.e. first one == 0)
        float beat;

        SerializedData serialize() const override;
        void deserialize(const SerializedData &data) override;
        void reset() override;

        static int compareElements(const Key &first, const Key &second) noexcept;
    };

    class Mapper
    {
    public:

        Mapper() = default;
        virtual ~Mapper() = default;

        virtual Note::Key mapArpKeyIntoChord(const Arpeggiator::Key &arpKey,
            const Array<Note> &chord, const Scale::Ptr chordScale,
            Note::Key chordRoot, int scaleOffset = 0) const = 0;

        virtual float mapArpVelocityIntoChord(const Arpeggiator::Key &arpKey,
            const Array<Note> &chord) const = 0;

    protected:

        Note::Key getChordKey(const Array<Note> &chord, int chordKeyIndex,
            const Scale::Ptr chordScale, Note::Key chordRoot, int scaleOffset) const;

        float getChordVelocity(const Array<Note> &chord, int chordKeyIndex) const;

    };

    //===------------------------------------------------------------------===//
    // Serializable
    //===------------------------------------------------------------------===//

    SerializedData serialize() const override;
    void deserialize(const SerializedData &data) override;
    void reset() override;

    //===------------------------------------------------------------------===//
    // BaseResource
    //===------------------------------------------------------------------===//

    String getResourceId() const noexcept override;
    Identifier getResourceType() const noexcept override;

protected:

    String name;
    Identifier type;
    Array<Arpeggiator::Key> keys;
    UniquePointer<Arpeggiator::Mapper> mapper;

    JUCE_LEAK_DETECTOR(Arpeggiator)
};
