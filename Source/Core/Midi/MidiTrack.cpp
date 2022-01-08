/*
    This file is part of Helio Workstation.

    Helio is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Helio is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Helio. If not, see <http://www.gnu.org/licenses/>.
*/

#include "Common.h"
#include "MidiTrack.h"
#include "SerializationKeys.h"

int MidiTrack::compareElements(const MidiTrack &first, const MidiTrack &second)
{
    if (&first == &second) { return 0; }
    return first.getTrackName().compareNatural(second.getTrackName());
}

int MidiTrack::compareElements(const MidiTrack *const first, const MidiTrack *const second)
{
    if (first == second) { return 0; }
    return first->getTrackName().compareNatural(second->getTrackName());
}

void MidiTrack::serializeTrackProperties(SerializedData &tree) const
{
    using namespace Serialization;
    tree.setProperty(Core::trackId, this->getTrackId());
    tree.setProperty(Core::trackColour, this->getTrackColour().toString());
    tree.setProperty(Core::trackChannel, this->getTrackChannel());
    tree.setProperty(Core::trackInstrumentId, this->getTrackInstrumentId());
    tree.setProperty(Core::trackControllerNumber, this->getTrackControllerNumber());
}

void MidiTrack::deserializeTrackProperties(const SerializedData &tree)
{
    using namespace Serialization;

    const auto trackId = tree.getProperty(Core::trackId, this->getTrackId());
    const auto colour = tree.getProperty(Core::trackColour, this->getTrackColour().toString()).toString();
    const auto channel = tree.getProperty(Core::trackChannel, this->getTrackChannel());
    const auto instrumentId = tree.getProperty(Core::trackInstrumentId, this->getTrackInstrumentId());
    const auto controllerNumber = tree.getProperty(Core::trackControllerNumber, this->getTrackControllerNumber());

    this->setTrackId(trackId);

    // Do not send notifications:
    // track is not supposed to update listeners meanwhile loading,
    // its up to caller to make sure the views are updated after
    this->setTrackColour(Colour::fromString(colour), false, dontSendNotification);
    this->setTrackInstrumentId(instrumentId, false, dontSendNotification);
    this->setTrackInstrumentId(instrumentId, false, dontSendNotification);
    this->setTrackControllerNumber(controllerNumber, dontSendNotification);
}

bool MidiTrack::isTempoTrack() const noexcept
{
    return this->getTrackControllerNumber() == MidiTrack::tempoController;
}

bool MidiTrack::isOnOffAutomationTrack() const noexcept
{
    // hardcoded for now
    return this->getTrackControllerNumber() >= 64 &&
        this->getTrackControllerNumber() <= 69;
}
