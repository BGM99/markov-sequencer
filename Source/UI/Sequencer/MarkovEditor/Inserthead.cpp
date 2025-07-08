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
    Listener *movementListener /*= nullptr*/,
    float alpha /*= 1.f*/) :
    roll(parentRoll),
    listener(movementListener),
    shadeColour(findDefaultColour(ColourIDs::Roll::playheadShade).withMultipliedAlpha(alpha)),
    playbackColour(findDefaultColour(ColourIDs::Roll::playheadPlayback).withMultipliedAlpha(alpha)),
    recordingColour(findDefaultColour(ColourIDs::Roll::playheadRecording).withMultipliedAlpha(alpha))
{
    this->currentColour = this->playbackColour;

    this->setInterceptsMouseClicks(false, false);
    this->setPaintingIsUnclipped(true);
    this->setAccessible(false);

    this->setSize(3, 1);

    this->beatAnchor = 0;
}

Inserthead::~Inserthead()
{
}


//===----------------------------------------------------------------------===//
// AsyncUpdater to call updatePosition on the main thread
//===----------------------------------------------------------------------===//

void Inserthead::handleAsyncUpdate()
{
    if (false)
    {
        this->updatePosition();
    }
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

void Inserthead::mouseDrag(const MouseEvent &e)
{

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
        if (this->listener != nullptr)
        {
            this->listener->onMovePlayhead(oldX, newX);
        }

        this->setTopLeftPosition(newX, 0);
    }
}

void Inserthead::updatePosition()
{
    this->updatePosition(this->lastCorrectBeat);
}

InsertheadSmall::InsertheadSmall(PianoRoll &parentRoll) :
    Inserthead(parentRoll, nullptr, 0.75f)
{
    this->setSize(1, 1);
}

void InsertheadSmall::paint(Graphics &g)
{
    g.setColour(this->currentColour);
    g.fillRect(0, 1, 1, this->getHeight() - 1);
}
