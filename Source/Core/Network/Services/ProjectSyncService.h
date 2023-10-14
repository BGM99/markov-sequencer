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

#if !NO_NETWORK

#include "BackendService.h"
#include "RevisionsSyncThread.h"
#include "ProjectCloneThread.h"
#include "ProjectDeleteThread.h"

class ProjectSyncService final : private BackendService
{
public:

    ProjectSyncService() = default;

    void fetchRevisionsInfo(WeakReference<VersionControl> vcs,
        const String &projectId, const String &projectName);

    void syncRevisions(WeakReference<VersionControl> vcs,
        const String &projectId, const String &projectName,
        const Array<String> &revisionIdsToPull,
        const Array<String> &revisionIdsToPush);

    void cancelSyncRevisions();


    void cloneProject(WeakReference<VersionControl> vcs,
        const String &projectId);

    void cancelCloneProject();

    void deleteProject(const String &projectId);


private:

    ProjectCloneThread *prepareProjectCloneThread();
    ProjectDeleteThread *prepareProjectDeleteThread();

    RevisionsSyncThread *prepareSyncRevisionsThread();
    RevisionsSyncThread *prepareFetchRevisionsThread();
};

#endif
