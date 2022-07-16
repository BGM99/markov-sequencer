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

#include "MidiEvent.h"

class AutomationEvent final : public MidiEvent
{
public:

    AutomationEvent() noexcept;

    AutomationEvent(const AutomationEvent &other) noexcept = default;
    AutomationEvent &operator= (const AutomationEvent &other) = default;

    AutomationEvent(AutomationEvent &&other) noexcept = default;
    AutomationEvent &operator= (AutomationEvent &&other) noexcept = default;

    AutomationEvent(WeakReference<MidiSequence> owner,
        const AutomationEvent &parametersToCopy) noexcept;

    explicit AutomationEvent(WeakReference<MidiSequence> owner,
        float beatVal = 0.f,
        float controllerValue = 0.f) noexcept;

    void exportMessages(MidiMessageSequence &outSequence, const Clip &clip,
        const KeyboardMapping &keyMap, double timeFactor) const noexcept override;

    static float interpolateEvents(float cv1, float cv2, float factor, float easing);

    static constexpr auto curveInterpolationStepBeat = 0.25f;
    static constexpr auto curveInterpolationThreshold = 0.0025f;

    AutomationEvent withBeat(float newBeat) const noexcept;
    AutomationEvent withDeltaBeat(float deltaBeat) const noexcept;
    AutomationEvent withControllerValue(float cv) const noexcept;
    AutomationEvent withInvertedControllerValue() const noexcept;
    AutomationEvent withParameters(float newBeat, float newControllerValue) const noexcept;
    AutomationEvent withCurvature(float newCurvature) const noexcept;
    AutomationEvent withParameters(const SerializedData &parameters) const noexcept;
    // and a special helper for the tempo track events:
    AutomationEvent withTempoBpm(int bpm) const noexcept;

    AutomationEvent withNewId(WeakReference<MidiSequence> newOwner = nullptr) const noexcept;

    //===------------------------------------------------------------------===//
    // Accessors
    //===------------------------------------------------------------------===//

    int getControllerValueAsBPM() const noexcept;
    float getControllerValue() const noexcept;
    float getCurvature() const noexcept;
    
    //===------------------------------------------------------------------===//
    // Pedal helpers
    //===------------------------------------------------------------------===//
    
    bool isPedalDownEvent() const noexcept;
    bool isPedalUpEvent() const noexcept;

    static AutomationEvent pedalUpEvent(MidiSequence *owner, float beatVal = 0.f);
    static AutomationEvent pedalDownEvent(MidiSequence *owner, float beatVal = 0.f);

    //===------------------------------------------------------------------===//
    // Serializable
    //===------------------------------------------------------------------===//

    SerializedData serialize() const override;
    void deserialize(const SerializedData &data) override;
    void reset() noexcept override;

    //===------------------------------------------------------------------===//
    // Helpers
    //===------------------------------------------------------------------===//

    void applyChanges(const AutomationEvent &parameters) noexcept;

    static inline int compareElements(const MidiEvent *const first,
        const MidiEvent *const second) noexcept
    {
        return MidiEvent::compareElements(first, second);
    }

    static inline int compareElements(const AutomationEvent &first,
        const AutomationEvent &second) noexcept
    {
        return AutomationEvent::compareElements(&first, &second);
    }

    static int compareElements(const AutomationEvent *const first,
        const AutomationEvent *const second) noexcept;

protected:

    float controllerValue = 0.f;
    float curvature = Globals::Defaults::automationControllerCurve;

private:

    JUCE_LEAK_DETECTOR(AutomationEvent);
};
