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
#include "PianoRoll.h"

namespace juce
{
class Graphics;
}
class Transport;
class PianoRoll;


class Inserthead :
    public Component,
    public Value::Listener
{
public:
    Inserthead(PianoRoll &parentRoll,
        float alpha = 1.f);

    ~Inserthead() override;

    void updatePosition();
    void updatePosition(float position);

    //===------------------------------------------------------------------===//
    // Value::Listener
    //===------------------------------------------------------------------===//

    void valueChanged (Value& value) override;

    //===------------------------------------------------------------------===//
    // Component
    //===------------------------------------------------------------------===//

    void mouseDown(const MouseEvent &e) override;
    void mouseDrag(const MouseEvent &e) override;
    void mouseUp(const MouseEvent &e) override;

    void paint(Graphics &g) override;
    void parentSizeChanged() override;
    void parentHierarchyChanged() override;

protected:

    PianoRoll &roll;

    ComponentDragger dragger;
    bool draggingState = false;

    Colour currentColour;

    const Colour shadeColour;
    const Colour playbackColour;
    const Colour recordingColour;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Inserthead);
};