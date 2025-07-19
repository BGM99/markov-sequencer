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

#include "Common.h"
#include "Inserthead.h"
#include "RollBase.h"
#include "ColourIDs.h"

Inserthead::Inserthead(PianoRoll &parentRoll,
    float alpha /*= 1.f*/) :
    roll(parentRoll),
    shadeColour(findDefaultColour(ColourIDs::Roll::playheadShade).withMultipliedAlpha(alpha)),
    playbackColour(findDefaultColour(ColourIDs::Roll::playheadPlayback).withMultipliedAlpha(alpha)),
    recordingColour(findDefaultColour(ColourIDs::Roll::playheadRecording).withMultipliedAlpha(alpha))
{
    this->currentColour = this->playbackColour;

    this->roll.markovInsertBeat.addListener(this);

    this->setInterceptsMouseClicks(true, true);
    this->setPaintingIsUnclipped(true);
    this->setAccessible(false);

    this->setSize(3, 1);
}

Inserthead::~Inserthead()
{
    this->roll.markovInsertBeat.removeListener(this);
}

//===----------------------------------------------------------------------===//
// juce::Value::Listener
//===----------------------------------------------------------------------===//

void Inserthead::valueChanged (Value& value)
{
    this->updatePosition(value.getValue());
}

//===----------------------------------------------------------------------===//
// Component
//===----------------------------------------------------------------------===//

void Inserthead::paint(Graphics &g)
{
    g.setColour(this->currentColour);
    g.fillRect(0, 0, 3, this->getHeight());

    g.setColour(this->shadeColour);
    g.fillRect(3, 0, 1, this->getHeight());
}

void Inserthead::mouseDown(const MouseEvent &e)
{
    if (this->roll.isMultiTouchEvent(e))
    {
        return;
    }

    if (e.mods.isLeftButtonDown())
    {
        this->dragger.startDraggingComponent(this, e);
        this->draggingState = true;
    }
}

void Inserthead::mouseDrag(const MouseEvent &e)
{
    if (this->roll.isMultiTouchEvent(e))
    {
        return;
    }

    if (e.mods.isLeftButtonDown() && e.getDistanceFromDragStart() > 4)
    {
        if (this->draggingState)
        {
            this->setMouseCursor(MouseCursor::DraggingHandCursor);
            this->dragger.dragComponent(this, e, nullptr);
            const float newBeat = this->roll.getBeatByXPosition(this->getX());
            const auto oldBeat = static_cast<float> (this->roll.markovInsertBeat.getValue());

            if (oldBeat != newBeat)
            {
                this->updatePosition(newBeat);

                if (auto* parent = this->getParentComponent())
                {
                    parent->repaint();
                }
            }
        }
    }
}

void Inserthead::mouseUp(const MouseEvent &e)
{
    if (e.mods.isLeftButtonDown())
    {
        if (this->draggingState)
        {
            this->setMouseCursor(MouseCursor::PointingHandCursor);
            this->draggingState = false;
            const float newBeat = this->roll.getBeatByXPosition(this->getX());
            this->roll.markovInsertBeat.setValue(newBeat);
        }
    }
}

void Inserthead::mouseEnter(const MouseEvent &e)
{
    this->setMouseCursor(MouseCursor::PointingHandCursor);
}

void Inserthead::mouseExit(const MouseEvent &e)
{
    this->setMouseCursor(MouseCursor::NormalCursor);
}

void Inserthead::parentSizeChanged()
{
    this->setSize(this->getWidth(), this->getParentHeight());
    this->updatePosition();
}

void Inserthead::parentHierarchyChanged()
{
    if (this->getParentComponent() == nullptr)
    {
        return;
    }

    this->setAlwaysOnTop(true);
    this->setSize(this->getWidth(), this->getParentHeight());
    this->updatePosition();
}

void Inserthead::updatePosition(float position)
{
    const auto oldX = this->getX();
    const int newX = this->roll.getXPositionByBeat(position, float(this->getParentWidth()));

    if (oldX != newX)
    {
        this->setTopLeftPosition(newX, 0);
    }
}

void Inserthead::updatePosition()
{
    this->updatePosition(this->roll.markovInsertBeat.getValue());
}