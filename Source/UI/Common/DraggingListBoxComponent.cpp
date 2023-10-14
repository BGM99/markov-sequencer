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
#include "DraggingListBoxComponent.h"
#include "ViewportKineticSlider.h"

DraggingListBoxComponent::DraggingListBoxComponent(Viewport *parent, bool disablesAllChildren) :
    HighlightedComponent(),
    parentViewport(parent),
    shouldDisableAllChildren(disablesAllChildren)
{
    if (this->parentViewport)
    {
        this->parentViewport->setScrollBarThickness(2);
        this->parentViewport->setScrollOnDragMode(Viewport::ScrollOnDragMode::never);
    }
    
    this->setInterceptsMouseClicks(true, false);
    this->setMouseClickGrabsKeyboardFocus(false);
}


//===----------------------------------------------------------------------===//
// Component
//===----------------------------------------------------------------------===//

void DraggingListBoxComponent::childrenChanged()
{
    // all children are not to be clicked on
    if (this->shouldDisableAllChildren)
    {
        for (int i = 0; i < this->getNumChildComponents(); ++i)
        {
            Component *childComponent = this->getChildComponent(i);
            childComponent->setInterceptsMouseClicks(false, false);
        }
    }
}

void DraggingListBoxComponent::mouseDown(const MouseEvent &event)
{
    if (!event.mods.isLeftButtonDown())
    {
        return;
    }
    
    if (! this->parentViewport)
    {
        this->setSelected(true);
        return;
    }

    if (this->listCanBeScrolled())
    {
        this->maxDragDistance = 0;
        this->viewportStartPosY = this->parentViewport->getViewPosition().getY();
        this->isDraggingListbox = true;
        
        this->dragStartMilliseconds = Time::getMillisecondCounterHiRes();
        ViewportKineticSlider::instance().stopAnimationForViewport(this->parentViewport);
    }
    else
    {
        this->setSelected(true);
    }
}

void DraggingListBoxComponent::mouseUp(const MouseEvent &event)
{
    this->isDraggingListbox = false;
    
    if (!event.mods.isLeftButtonDown())
    {
        return;
    }
    
    if (this->listCanBeScrolled())
    {
        if (this->maxDragDistance < DraggingListBoxComponent::dragStartThreshold)
        {
            this->setSelected(true);
            return;
        }
        else
        {
            const float dragTimeMs = float(Time::getMillisecondCounterHiRes() - this->dragStartMilliseconds);
            const float dragDistance = float(event.getOffsetFromDragStart().getY());
            const float pixelsPerMs = dragDistance / dragTimeMs;
            ViewportKineticSlider::instance().startAnimationForViewport(this->parentViewport, Point<float>(0.f, pixelsPerMs));
        }
    }
}

void DraggingListBoxComponent::mouseDrag(const MouseEvent &event)
{
    if (!event.mods.isLeftButtonDown())
    {
        return;
    }
    
    if (this->parentViewport && this->isDraggingListbox)
    {
        this->parentViewport->setViewPosition(0, this->viewportStartPosY - event.getDistanceFromDragStartY());
        this->maxDragDistance = jmax(abs(event.getDistanceFromDragStartY()), this->maxDragDistance);
        ViewportKineticSlider::instance().calculateDragSpeedForViewport(this->parentViewport, event.getOffsetFromDragStart().toFloat());
    }
}

void DraggingListBoxComponent::mouseWheelMove(const MouseEvent &event,
                                              const MouseWheelDetails &wheel)
{
    const int forwardWheel = int(wheel.deltaY *
        (wheel.isReversed ? -DraggingListBoxComponent::dragSpeed : DraggingListBoxComponent::dragSpeed));
    
    if (this->parentViewport != nullptr)
    {
        const BailOutChecker checker(this);
        this->parentViewport->setViewPosition(0, this->parentViewport->getViewPosition().getY() - forwardWheel);
        
        // If viewport is owned by Listbox,
        // the Listbox has just updated its contents here,
        // and the component may be deleted:
        if (! checker.shouldBailOut())
        {
            ViewportKineticSlider::instance().startAnimationForViewport(this->parentViewport, Point<float>(0.f, float(forwardWheel) / 50.f));
            
            const bool eventWasUsed =
                (wheel.deltaX != 0 && this->parentViewport->getHorizontalScrollBar().isVisible()) ||
                (wheel.deltaY != 0 && this->parentViewport->getVerticalScrollBar().isVisible());
            
            if (!eventWasUsed)
            {
                Component::mouseWheelMove(event, wheel);
            }
        }
    }
}

bool DraggingListBoxComponent::listCanBeScrolled() const
{
    if (! this->parentViewport)
    {
        return false;
    }
    
    if (this->parentViewport->getViewedComponent() == nullptr)
    {
        return false;
    }
    
    return this->parentViewport->getViewHeight() <
        this->parentViewport->getViewedComponent()->getHeight();
}
