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
#include "AutomationCurveHelper.h"
#include "AutomationSequence.h"

AutomationCurveHelper::AutomationCurveHelper(const AutomationEvent &event,
    AutomationEditorBase::EventComponentBase *target1,
    AutomationEditorBase::EventComponentBase *target2) :
    event(event),
    component1(target1),
    component2(target2)
{
    this->setFocusContainerType(Component::FocusContainerType::none);
    this->setWantsKeyboardFocus(false);
    this->setMouseCursor(MouseCursor::UpDownResizeCursor);

    this->setInterceptsMouseClicks(true, false);
    this->setMouseClickGrabsKeyboardFocus(false);
    this->setPaintingIsUnclipped(true);
}

float AutomationCurveHelper::getCurvature() const
{
    return this->event.getCurvature();
}

void AutomationCurveHelper::setEditable(bool shouldBeEditable)
{
    if (this->isEditable == shouldBeEditable)
    {
        return;
    }

    this->isEditable = shouldBeEditable;
}

void AutomationCurveHelper::paint(Graphics &g)
{
    if (this->component1 != nullptr)
    {
        g.setColour(this->component1->getColour());
    }

    g.fillEllipse(0.f, 0.f, float(this->getWidth()), float(this->getHeight()));

    if (this->isDragging)
    {
        g.fillEllipse(0.f, 0.f, float(this->getWidth()), float(this->getHeight()));
    }
}

bool AutomationCurveHelper::hitTest(int x, int y)
{
    if (!this->isEditable)
    {
        return false;
    }

    const int xCenter = this->getWidth() / 2;
    const int yCenter = this->getHeight() / 2;

    const int dx = x - xCenter;
    const int dy = y - yCenter;
    const int r = (this->getWidth() + this->getHeight()) / 4;

    return (dx * dx) + (dy * dy) < (r * r);
}

void AutomationCurveHelper::mouseDown(const MouseEvent &e)
{
    if (this->component1 == nullptr || this->component2 == nullptr)
    {
        return;
    }

    jassert (this->isEditable);

    if (e.mods.isLeftButtonDown())
    {
        this->event.getSequence()->checkpoint();
        this->dragger.startDraggingComponent(this, e, this->getCurvature(),
            0.f, 1.f, 1.f / 100.f,
            FineTuningComponentDragger::Mode::DragOnlyY);

        this->anchor = this->getBounds().getCentre();
        this->isDragging = true;
        this->repaint();
    }
}

void AutomationCurveHelper::mouseDrag(const MouseEvent &e)
{
    if (this->component1 == nullptr || this->component2 == nullptr)
    {
        return;
    }

    if (e.mods.isLeftButtonDown())
    {
        if (this->isDragging)
        {
            this->dragger.dragComponent(this, e);
            const float newCurvature = this->dragger.getValue();
            if (newCurvature != this->getCurvature())
            {
                if (this->tuningIndicator == nullptr)
                {
                    this->tuningIndicator = make<FineTuningValueIndicator>(this->event.getCurvature(), "");

                    // adding it to grandparent to avoid clipping
                    jassert(this->getParentComponent() != nullptr);
                    jassert(this->getParentComponent()->getParentComponent() != nullptr);
                    auto *grandParent = this->getParentComponent()->getParentComponent();

                    grandParent->addAndMakeVisible(this->tuningIndicator.get());
                    this->fader.fadeIn(this->tuningIndicator.get(), Globals::UI::fadeInLong);
                }

                auto *sequence = static_cast<AutomationSequence *>(this->event.getSequence());
                sequence->change(this->event, this->event.withCurvature(newCurvature), true);

                if (this->tuningIndicator != nullptr)
                {
                    const float cv = this->event.getCurvature();
                    this->tuningIndicator->setValue(cv, cv);
                    this->tuningIndicator->repositionAtTargetCenter(this);
                }
            }
        }
    }
}

void AutomationCurveHelper::mouseUp(const MouseEvent &e)
{
    if (this->component1 == nullptr || this->component2 == nullptr)
    {
        return;
    }

    if (this->tuningIndicator != nullptr)
    {
        this->fader.fadeOut(this->tuningIndicator.get(), Globals::UI::fadeOutLong);
        this->tuningIndicator = nullptr;
    }

    if (e.mods.isLeftButtonDown())
    {
        if (this->isDragging)
        {
            this->isDragging = false;
        }

        this->repaint();
    }
}
