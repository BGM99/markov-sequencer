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

class ViewportFitProxyComponent final : public Component
{
public:

    ViewportFitProxyComponent(Viewport &parentViewport,
        Component *child, bool deleteChildOnRelease = true);

    ~ViewportFitProxyComponent() override;

    void centerTargetToViewport();


    //===------------------------------------------------------------------===//
    // Component
    //===------------------------------------------------------------------===//

    void mouseMove(const MouseEvent &e) override;
    void mouseDown(const MouseEvent &event) override;
    void mouseDrag(const MouseEvent &event) override;
    void mouseUp(const MouseEvent &event) override;
    void parentSizeChanged() override;

private:

    bool fitsViewport() const;

    Viewport &viewport;

    Component *target = nullptr;
    const bool shouldDeleteChild = true;
    Point<int> viewportDragStart;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ViewportFitProxyComponent)

};
