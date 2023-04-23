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

#include "Common.h"
#include "InstrumentEditorConnector.h"
#include "InstrumentEditor.h"
#include "InstrumentComponent.h"
#include "ColourIDs.h"

InstrumentEditorConnector::InstrumentEditorConnector(WeakReference<Instrument> instrument) :
    instrument(instrument)
{
    this->setPaintingIsUnclipped(true);
    this->setAlwaysOnTop(true);
}

void InstrumentEditorConnector::setInput(const AudioProcessorGraph::NodeAndChannel node)
{
    if (this->connection.source != node)
    {
        this->connection.source = node;
        this->update();
    }
}

void InstrumentEditorConnector::setOutput(const AudioProcessorGraph::NodeAndChannel node)
{
    if (this->connection.destination != node)
    {
        this->connection.destination = node;
        this->update();
    }
}

void InstrumentEditorConnector::dragStart(int x, int y)
{
    this->lastInputX = float(x);
    this->lastInputY = float(y);
    this->resizeToFit();
}

void InstrumentEditorConnector::dragEnd(int x, int y)
{
    this->lastOutputX = float(x);
    this->lastOutputY = float(y);
    this->resizeToFit();
}

void InstrumentEditorConnector::update()
{
    float x1, y1, x2, y2;
    this->getPinPoints(x1, y1, x2, y2);

    if (lastInputX != x1 || lastInputY != y1 || lastOutputX != x2 || lastOutputY != y2)
    {
        this->resizeToFit();
    }
}

void InstrumentEditorConnector::resizeToFit()
{
    float x1, y1, x2, y2;
    this->getPinPoints(x1, y1, x2, y2);

    const Rectangle<int> newBounds(int(jmin(x1, x2)) - 4, int(jmin(y1, y2)) - 4,
        int(fabsf(x1 - x2)) + 8, int(fabsf(y1 - y2)) + 8);

    if (newBounds != this->getBounds())
    {
        this->setBounds(newBounds);
    }
    else
    {
        this->resized();
    }
}

void InstrumentEditorConnector::getPinPoints(float &x1, float &y1, float &x2, float &y2) const
{
    x1 = this->lastInputX;
    y1 = this->lastInputY;
    x2 = this->lastOutputX;
    y2 = this->lastOutputY;

    if (const auto *hostPanel = this->getGraphPanel())
    {
        if (auto *sourceNodeComponent =
            hostPanel->getComponentForNode(this->connection.source.nodeID))
        {
            sourceNodeComponent->getPinPos(this->connection.source.channelIndex, false, x1, y1);
        }

        if (auto *destinationNodeComponent =
            hostPanel->getComponentForNode(this->connection.destination.nodeID))
        {
            destinationNodeComponent->getPinPos(this->connection.destination.channelIndex, true, x2, y2);
        }
    }
}

void InstrumentEditorConnector::paint(Graphics &g)
{
    g.setColour(findDefaultColour(ColourIDs::Instrument::connectorShadow));
    g.fillPath(linePath, AffineTransform::translation(0, 0.5));
    
    const bool isMidiConnector =
        (this->connection.source.channelIndex == Instrument::midiChannelNumber ||
        this->connection.destination.channelIndex == Instrument::midiChannelNumber);

    const Colour lineColour = isMidiConnector ?
        findDefaultColour(ColourIDs::Instrument::midiConnector) :
        findDefaultColour(ColourIDs::Instrument::audioConnector);

    g.setColour(lineColour);
    g.fillPath(linePath);
}

bool InstrumentEditorConnector::hitTest(int x, int y)
{
    if (hitPath.contains(float(x), float(y)))
    {
        double distanceFromStart, distanceFromEnd;
        this->getDistancesFromEnds(x, y, distanceFromStart, distanceFromEnd);

        // avoid clicking the connector when over a pin
        return distanceFromStart > 7.0 && distanceFromEnd > 7.0;
    }

    return false;
}

void InstrumentEditorConnector::mouseDown(const MouseEvent &)
{
    this->dragging = false;
}

void InstrumentEditorConnector::mouseDrag(const MouseEvent &e)
{
    if ((!this->dragging) && ! e.mouseWasClicked())
    {
        this->dragging = true;
        this->instrument->removeConnection(this->connection);

        double distanceFromStart = 0.0, distanceFromEnd = 0.0;
        this->getDistancesFromEnds(e.x, e.y, distanceFromStart, distanceFromEnd);
        const bool isNearerSource = (distanceFromStart < distanceFromEnd);
        const AudioProcessorGraph::NodeID nodeIdZero;

        this->getGraphPanel()->beginConnectorDrag(
            isNearerSource ? nodeIdZero : this->connection.source.nodeID,
            this->connection.source.channelIndex,
            isNearerSource ? this->connection.destination.nodeID : nodeIdZero,
            this->connection.destination.channelIndex,
            e);
    }
    else if (this->dragging)
    {
        this->getGraphPanel()->dragConnector(e);
    }
}

void InstrumentEditorConnector::mouseUp(const MouseEvent &e)
{
    if (this->dragging)
    {
        this->getGraphPanel()->endDraggingConnector(e);
    }
}

void InstrumentEditorConnector::resized()
{
    float x1, y1, x2, y2;
    this->getPinPoints(x1, y1, x2, y2);

    this->lastInputX = x1;
    this->lastInputY = y1;
    this->lastOutputX = x2;
    this->lastOutputY = y2;

    x1 -= this->getX();
    y1 -= this->getY();
    x2 -= this->getX();
    y2 -= this->getY();

    const float dy = (y2 - y1);
    const float dx = (x2 - x1);

    this->linePath.clear();
    this->linePath.startNewSubPath(x1, y1);

    const float curveX = (this->getParentWidth() == 0) ? 0.f :
        (1.f - (fabsf(dx) / float(this->getParentWidth()))) * 1.5f;
    const float curveY = (this->getParentHeight() == 0) ? 0.f :
        (fabsf(dy) / float(this->getParentHeight())) * 1.5f;
    const float curve = (curveX + curveY) / 2.f;
    const float gravity = 0.6f +
        jlimit(-1.f, 1.f, dy / float(this->getParentHeight())) / 3.f;

    this->linePath.cubicTo(x1 + dx * (curve * (1.f - gravity)), y1,
        x1 + dx * (1.f - (curve * gravity)), y2,
                     x2, y2);

    PathStrokeType wideStroke(8.0f);
    wideStroke.createStrokedPath(hitPath, linePath);

    PathStrokeType stroke(6.5f, PathStrokeType::beveled, PathStrokeType::rounded);
    stroke.createStrokedPath(linePath, linePath);

    this->linePath.setUsingNonZeroWinding(false);
}

InstrumentEditor *InstrumentEditorConnector::getGraphPanel() const noexcept
{
    return this->findParentComponentOfClass<InstrumentEditor>();
}

void InstrumentEditorConnector::getDistancesFromEnds(int x, int y, double &distanceFromStart, double &distanceFromEnd) const
{
    float x1, y1, x2, y2;
    this->getPinPoints(x1, y1, x2, y2);

    distanceFromStart = juce_hypot(x - (x1 - this->getX()), y - (y1 - this->getY()));
    distanceFromEnd = juce_hypot(x - (x2 - this->getX()), y - (y2 - this->getY()));
}
