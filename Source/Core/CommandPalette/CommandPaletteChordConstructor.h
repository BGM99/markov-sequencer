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

#include "CommandPaletteActionsProvider.h"

class PianoRoll;
class ChordCompiler;

class CommandPaletteChordConstructor final : public CommandPaletteActionsProvider
{
public:

    explicit CommandPaletteChordConstructor(PianoRoll &roll);
    ~CommandPaletteChordConstructor() override;

    void updateFilter(const String &pattern, bool skipPrefix) override;
    void clearFilter() override;

protected:

    const Actions &getActions() const override;
    mutable Actions actions;

private:

    static constexpr auto noteLength = 4.f;
    static constexpr auto noteVelocity = 0.35f;

    const UniquePointer<ChordCompiler> chordCompiler;

    PianoRoll &roll;
    Array<int> chord;

    bool hasMadeChanges = false;
    void undoIfNeeded();
    void previewIfNeeded();

};
