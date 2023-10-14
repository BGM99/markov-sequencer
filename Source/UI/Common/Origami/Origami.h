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

class Origami : public Component
{
public:

    class ChildConstrainer final : public ComponentBoundsConstrainer
    {
    public:
        explicit ChildConstrainer(Origami &origamiRef) : origami(origamiRef) { }
        void applyBoundsToComponent(Component &component, Rectangle<int> bounds) override;

    private:
        Origami &origami;
    };

    struct Page final
    {
        SafePointer<Component> component;
        UniquePointer<Component> shadowAtStart;
        UniquePointer<Component> shadowAtEnd;
        UniquePointer<Component> resizer;
        UniquePointer<Origami::ChildConstrainer> constrainer;
        int size = 0;
        int min = Origami::defaultMinSize;
        int max = Origami::defaultMaxSize;
        bool fixedSize = 0;
    };

    Origami();

    //===------------------------------------------------------------------===//
    // Origami
    //===------------------------------------------------------------------===//

    virtual void addFlexiblePage(Component *component) = 0;
    virtual void addFixedPage(Component *component) = 0;
    virtual void addShadowAtTheStart() = 0;
    virtual void addShadowAtTheEnd() = 0;
    virtual void addResizer(int minSize, int maxSize) = 0;

    int getMinimumCommonSize() const;
    int getMaximumCommonSize() const;
    bool removePageContaining(Component *component);
    void clear();
    bool containsComponent(Component *component) const;

protected:

    virtual void onPageResized(Component *component) = 0;

    OwnedArray<Origami::Page> pages;

private:

    static constexpr auto defaultMinSize = 100;
    static constexpr auto defaultMaxSize = 1000;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Origami)

};
