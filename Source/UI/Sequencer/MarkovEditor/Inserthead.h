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

namespace juce
{
class Graphics;
}
class Transport;
class RollBase;



class Inserthead :
    public Component,
    private AsyncUpdater
{
public:

    class Listener
    {
    public:
        virtual ~Listener() = default;
        virtual void onMovePlayhead(int oldX, int newX) = 0;
    };

    Inserthead(RollBase &parentRoll,
        Inserthead::Listener *movementListener = nullptr,
        float alpha = 1.f);

    ~Inserthead() override;

    void updatePosition();
    void updatePosition(float position);

    //===------------------------------------------------------------------===//
    // Component
    //===------------------------------------------------------------------===//

    void paint(juce::Graphics &g) override;
    void parentSizeChanged() override;
    void parentHierarchyChanged() override;

protected:

    RollBase &roll;

    Listener *listener = nullptr;

    void handleAsyncUpdate() override;

    // warning: spinlock is not reentrant, use carefully;
    // for now it synchronizes updates in TransportListener callbacks
    // coming from the background thread with the timer callback
    // on the main thread, so that position changes are smooth
    //SpinLock playbackUpdatesLock;

    // it's meant to lock these 4 fields:
    float beatAnchor = 0.f;
    double timeAnchor = 0.0;
    float lastCorrectBeat = 0.f;

    float lastEstimatedBeat = 0.f;
    float calculateEstimatedBeat() const noexcept;

    Colour currentColour;

    const Colour shadeColour;
    const Colour playbackColour;
    const Colour recordingColour;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Inserthead);
};

class PlayheadSmall final : public Playhead
{
public:

    PlayheadSmall(RollBase &parentRoll, Transport &owner);
    void paint(juce::Graphics &g) override;
};
