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

#include "ColourScheme.h"

class HelioTheme final : public LookAndFeel_V4
{
public:

    HelioTheme();

    static HelioTheme &getCurrentTheme() noexcept;

    void initResources();
    void initColours(const ::ColourScheme::Ptr colours);
    void updateFont(const Font &font);
    
    Typeface::Ptr getTypefaceForFont(const Font &) override;

    static void drawNoise(Component *target, Graphics &g, float alphaMultiply = 1.f);
    static void drawNoise(const HelioTheme &theme, Graphics &g, float alphaMultiply = 1.f);
    static void drawNoiseWithin(Rectangle<int> bounds, Graphics &g, float alphaMultiply = 1.f);

    inline static void drawDashedRectangle(Graphics &g, const Rectangle<int> &area, int dashLength = 4)
    {
        for (int i = area.getX() + 1; i < area.getWidth() - 1; i += (dashLength * 2))
        {
            g.fillRect(i, area.getY(), dashLength, 1);
            g.fillRect(i, area.getHeight() - 1, dashLength, 1);
        }

        for (int i = area.getY() + 1; i < area.getHeight() - 1; i += (dashLength * 2))
        {
            g.fillRect(area.getX(), i, 1, dashLength);
            g.fillRect(area.getWidth() - 1, i, 1, dashLength);
        }
    }

    template <int thickness = 1>
    inline static void drawDashedHorizontalLine(Graphics &g, float x, float y, float width, float dashLength = 4.f);

    template <>
    inline static void drawDashedHorizontalLine<1>(Graphics &g, float x, float y, float width, float dashLength)
    {
        for (; x < width - dashLength; x += dashLength * 2.f)
        {
            g.fillRect(x, y, dashLength, 1.f);
        }

        if (width > dashLength)
        {
            g.fillRect(x, y, jmax(0.f, 1.f + width - x), 1.f);
        }
    }

    template <>
    inline static void drawDashedHorizontalLine<2>(Graphics &g, float x, float y, float width, float dashLength)
    {
        for (; x < width - dashLength; x += dashLength * 2.f)
        {
            g.fillRect(x + 1.f, y, dashLength, 1.f);
            g.fillRect(x, y + 1.f, dashLength, 1.f);
        }

        if (width > dashLength)
        {
            g.fillRect(x + 1.f, y, jmax(0.f, 1.f + width - x - 2.f), 1.f);
            g.fillRect(x, y + 1.f, jmax(0.f, 1.f + width - x), 1.f);
        }
    }

    template <>
    inline static void drawDashedHorizontalLine<3>(Graphics &g, float x, float y, float width, float dashLength)
    {
        for (; x < width - dashLength; x += dashLength * 2.f)
        {
            g.fillRect(x + 2.f, y, dashLength, 1.f);
            g.fillRect(x + 1.f, y + 1.f, dashLength, 1.f);
            g.fillRect(x, y + 2.f, dashLength, 1.f);
        }

        if (width > dashLength)
        {
            g.fillRect(x + 2.f, y, jmax(0.f, 1.f + width - x - 4.f), 1.f);
            g.fillRect(x + 1.f, y + 1.f, jmax(0.f, 1.f + width - x - 2.f), 1.f);
            g.fillRect(x, y + 2.f, jmax(0.f, 1.f + width - x), 1.f);
        }
    }

    template <int thickness = 1>
    inline static void drawDashedVerticalLine(Graphics &g, float x, float y, float height, float dashLength = 4.f);

    template <>
    inline static void drawDashedVerticalLine<1>(Graphics &g, float x, float y, float height, float dashLength)
    {
        for (; y < height - dashLength; y += dashLength * 2.f)
        {
            g.fillRect(x, y, 1.f, dashLength);
        }

        if (height > dashLength)
        {
            g.fillRect(x, y, 1.f, jmax(0.f, 1.f + height - y));
        }
    }

    void drawStretchableLayoutResizerBar(Graphics &g,
            int /*w*/, int /*h*/, bool /*isVerticalBar*/,
            bool isMouseOver, bool isMouseDragging) override;

    static void drawFrame(Graphics &g, int width, int height,
        float lightAlphaMultiplier = 1.f, float darkAlphaMultiplier = 1.f);

    //===------------------------------------------------------------------===//
    // Text Editor
    //===------------------------------------------------------------------===//

    void fillTextEditorBackground(Graphics&, int w, int h, TextEditor&) override;
    void drawTextEditorOutline(Graphics&, int w, int h, TextEditor&) override {}
        
    //===------------------------------------------------------------------===//
    // Labels
    //===------------------------------------------------------------------===//

    void drawLabel(Graphics &, Label &) override;
    void drawLabel(Graphics &, Label &, juce_wchar passwordCharacter);
    Font getLabelFont(Label&) override;

    //===------------------------------------------------------------------===//
    // Button
    //===------------------------------------------------------------------===//

    Font getTextButtonFont(TextButton&, int buttonHeight) override;
    void drawButtonText(Graphics &, TextButton &button,
        bool isMouseOverButton, bool isButtonDown) override;
    void drawButtonBackground(Graphics &g, Button &button,
        const Colour &backgroundColour,
        bool isMouseOverButton, bool isButtonDown) override;

    //===------------------------------------------------------------------===//
    // Tables
    //===------------------------------------------------------------------===//

    void drawTableHeaderBackground(Graphics&, TableHeaderComponent&) override;
    void drawTableHeaderColumn(Graphics&, TableHeaderComponent&,
        const String &columnName, int columnId, int width, int height,
        bool isMouseOver, bool isMouseDown, int columnFlags) override;

    //===------------------------------------------------------------------===//
    // Scrollbars
    //===------------------------------------------------------------------===//

    int getDefaultScrollbarWidth() override;
    bool areScrollbarButtonsVisible() override { return false; }
    void drawScrollbarButton(Graphics &g, ScrollBar &bar,
        int width, int height, int buttonDirection,
        bool isScrollbarVertical, bool isMouseOverButton,
        bool isButtonDown) override {}
    void drawScrollbar(Graphics &g, ScrollBar &bar,
        int x, int y, int width, int height,
        bool isScrollbarVertical, int thumbStartPosition, int thumbSize,
        bool isMouseOver, bool isMouseDown) override;

    //===------------------------------------------------------------------===//
    // Sliders
    //===------------------------------------------------------------------===//

    void drawRotarySlider(Graphics&, int x, int y, int width, int height,
        float sliderPosProportional, float rotaryStartAngle,
        float rotaryEndAngle, Slider&) override;
        
    //===------------------------------------------------------------------===//
    // Window
    //===------------------------------------------------------------------===//

    void drawCornerResizer(Graphics& g, int w, int h,
        bool /*isMouseOver*/, bool /*isMouseDragging*/) override;

    void drawResizableFrame(Graphics &g, int w, int h,
        const BorderSize<int> &border) override;

    void drawDocumentWindowTitleBar(DocumentWindow &window,
        Graphics &g, int w, int h,
        int titleSpaceX, int titleSpaceW,
        const Image *icon,
        bool drawTitleTextOnLeft) override;

    Button *createDocumentWindowButton(int buttonType) override;
    void positionDocumentWindowButtons(DocumentWindow &window,
            int titleBarX, int titleBarY,
            int titleBarW, int titleBarH,
            Button *minimiseButton,
            Button *maximiseButton,
            Button *closeButton,
            bool positionTitleBarButtonsOnLeft) override;
    
    inline Image &getBgCacheA() noexcept { return this->bgCacheA; }
    inline const Image &getBgCacheA() const noexcept { return this->bgCacheA; }

    inline Image &getBgCacheB() noexcept { return this->bgCacheB; }
    inline const Image &getBgCacheB() const noexcept { return this->bgCacheB; }

    inline Image &getBgCacheC() noexcept { return this->bgCacheC; }
    inline const Image &getBgCacheC() const noexcept { return this->bgCacheC; }

    inline bool isDark() const noexcept
    {
        return this->isDarkTheme;
    }

protected:
    
    const Image backgroundNoise;
    Colour backgroundTextureBaseColour;
    Image cachedBackground;
    
    Typeface::Ptr textTypefaceCache;
    
    Image bgCacheA;
    Image bgCacheB;
    Image bgCacheC;

    bool isDarkTheme = false;

    JUCE_LEAK_DETECTOR(HelioTheme);

};
