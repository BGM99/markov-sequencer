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

class RollBase;

#include "FloatBoundsComponent.h"
#include "SelectableComponent.h"

class RollChildComponentBase : public FloatBoundsComponent, public SelectableComponent
{
public:

    explicit RollChildComponentBase(RollBase &editor) noexcept;

    // non-editable events may still be enabled and intercept mouse events,
    // for example, for activating their clip on rclick mouse down or long-tap:
    bool isActiveAndEditable() const noexcept;

    void setEditable(bool val);
    void setActive(bool val, bool force = false);

    virtual float getBeat() const noexcept = 0;
    virtual void updateColours() = 0;

    //===------------------------------------------------------------------===//
    // SelectableComponent
    //===------------------------------------------------------------------===//

    void setSelected(bool selected) override;
    bool isSelected() const noexcept override;

    //===------------------------------------------------------------------===//
    // Component
    //===------------------------------------------------------------------===//

    void mouseDown(const MouseEvent &e) override;

protected:

    RollBase &roll;

    struct Flags final
    {
        bool isSelected : 1;            // both clips and notes can be displayed as selected
        bool isActive : 1;              // whether a note belongs to the currently active clip or not
        bool isEditable : 1;            // whether an event is editable or not for whatever reason
        bool isGhost : 1;               // indicates helper notes which are used for visual cue
        bool isGenerated : 1;           // indicates notes generated or affected by parametric modifiers
        bool isInstanceOfSelected : 1;  // used to highlight all "instances" of selected clips
        bool isRecordingTarget : 1;     // indicates that a clip is used as a target to MIDI recording
        bool isMergeTarget : 1;         // indicates clips which are to be merged into one
    };

    union
    {
        uint16 componentFlags = 0;
        Flags flags;
    };

protected:

    // this is similar to JUCE's ComponentDragger, except it keeps the mouse down position
    // in percents not pixels to avoid glitches when the dragged component changes its size,
    // e.g. when zooming the roll while dragging the note/clip
    struct ComponentDragger final
    {
        ComponentDragger() = default;

        void startDraggingComponent(Component *componentToDrag, const MouseEvent &e)
        {
            jassert(componentToDrag != nullptr);
            jassert(e.mods.isAnyMouseButtonDown());

            this->mouseDownWithinTarget =
                e.getEventRelativeTo(componentToDrag).getMouseDownPosition().toFloat() /
                    Point<float>(jmax(0.01f, float(componentToDrag->getWidth())),
                        jmax(0.01f, float(componentToDrag->getHeight())));
        }

        // returns the mouse down offset in pixels
        Point<int> dragComponent(Component *componentToDrag, const MouseEvent &e) const
        {
            jassert(componentToDrag != nullptr);
            jassert(e.mods.isAnyMouseButtonDown());

            const Point<int> mouseOffset(componentToDrag->proportionOfWidth(this->mouseDownWithinTarget.x),
                componentToDrag->proportionOfHeight(this->mouseDownWithinTarget.y));

            componentToDrag->setBounds(componentToDrag->getBounds() +
                e.getEventRelativeTo(componentToDrag).getPosition() - mouseOffset);

            return mouseOffset;
        }

        Point<float> mouseDownWithinTarget;

        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ComponentDragger)
    };

    ComponentDragger dragger;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RollChildComponentBase)
};
