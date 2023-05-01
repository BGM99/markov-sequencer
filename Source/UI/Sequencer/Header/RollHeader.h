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

#pragma once

class RollBase;
class Transport;
class SoundProbeIndicator;
class TimeDistanceIndicator;
class HeaderSelectionIndicator;
class ClipRangeIndicator;
class PlaybackLoopMarker;

class RollHeader final : public Component
{
public:

    RollHeader(Transport &transport, RollBase &roll, Viewport &viewport);
    ~RollHeader() override;
    
    void setSoundProbeMode(bool shouldProbeOnClick);

    void showPopupMenu();
    void showRecordingMode(bool showRecordingMarker);
    void showLoopMode(bool hasLoop, float startBeat, float endBeat);

    void updateClipRangeIndicator(const Colour &colour, float firstBeat, float lastBeat);
    void updateSelectionRangeIndicator(const Colour &colour, float firstBeat, float lastBeat);

    Colour getBarColour() const noexcept;

    //===------------------------------------------------------------------===//
    // Component
    //===------------------------------------------------------------------===//

    void mouseUp(const MouseEvent &e) override;
    void mouseDown(const MouseEvent &e) override;
    void mouseDrag(const MouseEvent &e) override;
    void mouseMove(const MouseEvent &e) override;
    void mouseExit(const MouseEvent &e) override;
    void mouseDoubleClick(const MouseEvent &e) override;
    void paint(Graphics &g) override;
    void resized() override;

protected:
    
    Transport &transport;
    RollBase &roll;
    Viewport &viewport;

    Atomic<bool> soundProbeMode = false;
    Atomic<bool> recordingMode = false;

    Colour backColour;
    Colour barColour;
    Colour barShadeColour;
    Colour beatColour;
    Colour snapColour;
    Colour bevelLightColour;
    Colour bevelDarkColour;
    Colour recordingColour;

    void updateColours();

    UniquePointer<ClipRangeIndicator> clipRangeIndicator;
    UniquePointer<ClipRangeIndicator> selectionRangeIndicator;

    UniquePointer<SoundProbeIndicator> probeIndicator;
    UniquePointer<SoundProbeIndicator> pointingIndicator;
    UniquePointer<TimeDistanceIndicator> timeDistanceIndicator;
    UniquePointer<HeaderSelectionIndicator> selectionIndicator;

    UniquePointer<PlaybackLoopMarker> loopMarkerStart;
    UniquePointer<PlaybackLoopMarker> loopMarkerEnd;

    static constexpr auto minTimeDistanceIndicatorSize = 40;

    void updateSoundProbeIndicatorPosition(SoundProbeIndicator *indicator, const MouseEvent &e);
    double getUnalignedAnchorForEvent(const MouseEvent &e) const;
    void updateTimeDistanceIndicator();
    void updateClipRangeIndicatorPosition();
    void updateSelectionRangeIndicatorPosition();

};
