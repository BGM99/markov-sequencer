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

class AnnotationsProjectMap;

#include "AnnotationEvent.h"

class AnnotationComponent : public Component
{
public:

    AnnotationComponent(AnnotationsProjectMap &parent, const AnnotationEvent &event) :
        editor(parent), event(event) {}

    const AnnotationEvent &getEvent() const noexcept
    {
        return this->event;
    }

    float getBeat() const noexcept
    {
        return this->event.getBeat();
    }

    float getLength() const noexcept
    {
        return this->event.getLength();
    }

    float hasLength() const noexcept
    {
        return this->event.getLength() != 0.f;
    }

    virtual float getTextWidth() const = 0;
    virtual void updateContent() = 0;
    virtual void setRealBounds(const Rectangle<float> bounds) = 0;

    static int compareElements(const AnnotationComponent *first,
                               const AnnotationComponent *second)
    {
        if (first == second) { return 0; }

        const float diff = first->event.getBeat() - second->event.getBeat();
        const int diffResult = (diff > 0.f) - (diff < 0.f);
        if (diffResult != 0) { return diffResult; }

        return first->event.getId() - second->event.getId();
    }

protected:

    const AnnotationEvent &event;
    AnnotationsProjectMap &editor;

};
