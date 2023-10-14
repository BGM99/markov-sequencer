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
#include "PatternDiffHelpers.h"

namespace VCS
{

void deserializePatternChanges(const SerializedData &state, const SerializedData &changes,
    Array<Clip> &stateClips, Array<Clip> &changesClips)
{
    if (state.isValid())
    {
        forEachChildWithType(state, e, Serialization::Midi::clip)
        {
            Clip clip;
            clip.deserialize(e);
            stateClips.addSorted(clip, clip);
        }
    }

    if (changes.isValid())
    {
        forEachChildWithType(changes, e, Serialization::Midi::clip)
        {
            Clip clip;
            clip.deserialize(e);
            changesClips.addSorted(clip, clip);
        }
    }
}

SerializedData serializePattern(Array<Clip> changes, const Identifier &tag)
{
    SerializedData tree(tag);

    for (int i = 0; i < changes.size(); ++i)
    {
        tree.appendChild(changes.getUnchecked(i).serialize());
    }

    return tree;
}

DeltaDiff PatternDiffHelpers::serializePatternChanges(Array<Clip> changes,
    const String &description, int64 numChanges, const Identifier &deltaType)
{
    DeltaDiff changesFullDelta;
    changesFullDelta.delta = make<Delta>(DeltaDescription(description, numChanges), deltaType);
    changesFullDelta.deltaData = serializePattern(changes, deltaType);
    return changesFullDelta;
}

bool PatternDiffHelpers::checkIfDeltaIsPatternType(const Delta *d)
{
    using namespace Serialization::VCS;
    return (d->hasType(PatternDeltas::clipsAdded) ||
        d->hasType(PatternDeltas::clipsRemoved) ||
        d->hasType(PatternDeltas::clipsChanged));
}

SerializedData PatternDiffHelpers::mergeClipsAdded(const SerializedData &state, const SerializedData &changes)
{
    using namespace Serialization::VCS;

    Array<Clip> stateClips;
    Array<Clip> changesClips;
    deserializePatternChanges(state, changes, stateClips, changesClips);

    Array<Clip> result;
    result.addArray(stateClips);

    FlatHashSet<Clip::Id> stateIDs;

    for (int j = 0; j < stateClips.size(); ++j)
    {
        stateIDs.insert(stateClips.getUnchecked(j).getId());
    }

    for (int i = 0; i < changesClips.size(); ++i)
    {
        const Clip changesClip(changesClips.getUnchecked(i));
        const bool foundInState = stateIDs.contains(changesClip.getId());

        if (!foundInState)
        {
            result.add(changesClip);
        }
    }

    return serializePattern(result, PatternDeltas::clipsAdded);
}

SerializedData PatternDiffHelpers::mergeClipsRemoved(const SerializedData &state, const SerializedData &changes)
{
    using namespace Serialization::VCS;

    Array<Clip> stateClips;
    Array<Clip> changesClips;
    deserializePatternChanges(state, changes, stateClips, changesClips);

    Array<Clip> result;
    FlatHashSet<Clip::Id> changesIDs;

    for (int j = 0; j < changesClips.size(); ++j)
    {
        changesIDs.insert(changesClips.getUnchecked(j).getId());
    }

    for (int i = 0; i < stateClips.size(); ++i)
    {
        const Clip stateClip(stateClips.getUnchecked(i));
        const bool foundInChanges = changesIDs.contains(stateClip.getId());

        if (!foundInChanges)
        {
            result.add(stateClip);
        }
    }

    return serializePattern(result, PatternDeltas::clipsAdded);
}

SerializedData PatternDiffHelpers::mergeClipsChanged(const SerializedData &state, const SerializedData &changes)
{
    using namespace Serialization::VCS;

    Array<Clip> stateClips;
    Array<Clip> changesClips;
    deserializePatternChanges(state, changes, stateClips, changesClips);

    Array<Clip> result;
    result.addArray(stateClips);

    FlatHashMap<Clip::Id, Clip> changesIDs;

    for (int j = 0; j < changesClips.size(); ++j)
    {
        const Clip changesClip(changesClips.getUnchecked(j));
        changesIDs[changesClip.getId()] = changesClip;
    }

    for (int i = 0; i < stateClips.size(); ++i)
    {
        const Clip stateClip(stateClips.getUnchecked(i));

        if (changesIDs.contains(stateClip.getId()))
        {
            const auto changesClip = changesIDs[stateClip.getId()];
            result.removeAllInstancesOf(stateClip);
            result.addIfNotAlreadyThere(changesClip);
        }
    }

    return serializePattern(result, PatternDeltas::clipsAdded);
}

Array<VCS::DeltaDiff> PatternDiffHelpers::createClipsDiffs(const SerializedData &state, const SerializedData &changes)
{
    using namespace Serialization::VCS;

    Array<Clip> stateClips;
    Array<Clip> changesClips;

    deserializePatternChanges(state, changes, stateClips, changesClips);

    Array<DeltaDiff> res;

    Array<Clip> addedClips;
    Array<Clip> removedClips;
    Array<Clip> changedClips;

    for (int i = 0; i < stateClips.size(); ++i)
    {
        bool foundInChanges = false;
        const Clip stateClip(stateClips.getUnchecked(i));

        for (int j = 0; j < changesClips.size(); ++j)
        {
            const Clip changesClip(changesClips.getUnchecked(j));

            if (stateClip.getId() == changesClip.getId())
            {
                foundInChanges = true;
                if (stateClip.getKey() != changesClip.getKey() ||
                    stateClip.getBeat() != changesClip.getBeat() ||
                    stateClip.getVelocity() != changesClip.getVelocity() ||
                    stateClip.isMuted() != changesClip.isMuted() ||
                    stateClip.isSoloed() != changesClip.isSoloed())
                {
                    changedClips.add(changesClip);
                }

                break;
            }
        }

        if (!foundInChanges)
        {
            removedClips.add(stateClip);
        }
    }

    for (int i = 0; i < changesClips.size(); ++i)
    {
        bool foundInState = false;
        const Clip changesClip(changesClips.getUnchecked(i));

        for (int j = 0; j < stateClips.size(); ++j)
        {
            const Clip stateClip(stateClips.getUnchecked(j));
            if (stateClip.getId() == changesClip.getId())
            {
                foundInState = true;
                break;
            }
        }

        if (!foundInState)
        {
            addedClips.add(changesClip);
        }
    }

    if (addedClips.size() > 0)
    {
        res.add(serializePatternChanges(addedClips,
            "added {x} clips",
            addedClips.size(),
            PatternDeltas::clipsAdded));
    }

    if (removedClips.size() > 0)
    {
        res.add(serializePatternChanges(removedClips,
            "removed {x} clips",
            removedClips.size(),
            PatternDeltas::clipsRemoved));
    }

    if (changedClips.size() > 0)
    {
        res.add(serializePatternChanges(changedClips,
            "changed {x} clips",
            changedClips.size(),
            PatternDeltas::clipsChanged));
    }

    return res;
}

}
