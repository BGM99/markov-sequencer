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
#include "ViewportFitProxyComponent.h"
#include "CommandIDs.h"

ViewportFitProxyComponent::ViewportFitProxyComponent(Viewport &parentViewport,
        Component *child, bool deleteChildOnRelease /*= true*/) :
    viewport(parentViewport),
    shouldDeleteChild(deleteChildOnRelease),
    target(child),
    viewportDragStart(0, 0)
{
    this->setInterceptsMouseClicks(true, true);
    this->setMouseClickGrabsKeyboardFocus(false);
    this->addAndMakeVisible(this->target);
    this->setSize(this->target->getWidth(), this->target->getHeight());
    this->centerTargetToViewport();
    
#if PLATFORM_MOBILE
    this->viewport.setScrollBarThickness(2);
#endif
}

ViewportFitProxyComponent::~ViewportFitProxyComponent()
{
    this->removeChildComponent(this->target);

    if (this->shouldDeleteChild)
    {
        delete this->target;
    }
}

void ViewportFitProxyComponent::centerTargetToViewport()
{
    static constexpr auto padding = 30;

    // не хочу разбираться, почему одной итерации мало
    // пусть остается костыль.
    for (int i = 0; i < 2; ++i)
    {
        const int tH = this->target->getHeight();
        const int pH = this->viewport.getMaximumVisibleHeight();

        if (tH < pH)
        {
            this->setSize(this->getWidth(), pH);
            this->target->setTopLeftPosition(this->target->getX(), (pH / 2) - (tH / 2));
        }
        else
        {
            this->setSize(this->getWidth(), tH + padding);
            this->target->setTopLeftPosition(this->target->getX(), padding / 2);
        }

        const int tW = this->target->getWidth();
        const int pW = this->viewport.getMaximumVisibleWidth();

        if (tW < pW)
        {
            this->setSize(pW, this->getHeight());
            this->target->setTopLeftPosition((pW / 2) - (tW / 2), this->target->getY());
        }
        else
        {
            this->setSize(tW + padding, this->getHeight());
            this->target->setTopLeftPosition(padding / 2, this->target->getY());
        }
    }
}

//===----------------------------------------------------------------------===//
// Component
//===----------------------------------------------------------------------===//

void ViewportFitProxyComponent::mouseMove(const MouseEvent &e)
{
    if (this->fitsViewport())
    {
        this->setMouseCursor(MouseCursor::NormalCursor);
    }
    else
    {
        this->setMouseCursor(MouseCursor::DraggingHandCursor);
    }
}

void ViewportFitProxyComponent::mouseDown(const MouseEvent &event)
{
    this->viewportDragStart = this->viewport.getViewPosition();
    this->target->postCommandMessage(CommandIDs::StartDragViewport);
}

void ViewportFitProxyComponent::mouseDrag(const MouseEvent &event)
{
    if (this->fitsViewport())
    {
        return;
    }

    const Point<int> dragDelta(event.getDistanceFromDragStartX(), event.getDistanceFromDragStartY());
    this->viewport.setViewPosition(this->viewportDragStart - dragDelta);
}

void ViewportFitProxyComponent::mouseUp(const MouseEvent &event)
{
    target->postCommandMessage(CommandIDs::EndDragViewport);
}

void ViewportFitProxyComponent::parentSizeChanged()
{
    this->centerTargetToViewport();
}

//===----------------------------------------------------------------------===//
// Private
//===----------------------------------------------------------------------===//

bool ViewportFitProxyComponent::fitsViewport() const
{
    return this->getHeight() <= this->viewport.getMaximumVisibleHeight() &&
        this->getWidth() <= this->viewport.getMaximumVisibleWidth();
}
