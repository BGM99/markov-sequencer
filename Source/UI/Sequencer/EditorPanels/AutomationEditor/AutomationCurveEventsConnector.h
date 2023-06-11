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

#include "AutomationEditorBase.h"

class AutomationCurveEventsConnector final : public Component
{
public:

    AutomationCurveEventsConnector(AutomationEditorBase &editor,
        AutomationEditorBase::EventComponentBase *c1,
        AutomationEditorBase::EventComponentBase *c2);

    Point<float> getCentrePoint() const;
    void resizeToFit(float newCurvature = 0.5f);
    void retargetAndUpdate(AutomationEditorBase::EventComponentBase *c1,
        AutomationEditorBase::EventComponentBase *c2);

    //===------------------------------------------------------------------===//
    // Component
    //===------------------------------------------------------------------===//

    void paint(Graphics &g) override;
    void resized() override;
    
private:

    AutomationEditorBase &editor;

    SafePointer<AutomationEditorBase::EventComponentBase> component1;
    SafePointer<AutomationEditorBase::EventComponentBase> component2;

    Array<Point<float>> linePath;
    void rebuildLinePath();

    float curvature = 0.5f;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AutomationCurveEventsConnector)
};
