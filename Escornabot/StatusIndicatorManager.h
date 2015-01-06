// StatusIndicatorManager.h
/*

Copyright (C) 2014 Bricolabs - http://bricolabs.cc

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301,
USA.

See LICENSE.txt for details

*/

#ifndef _STATUS_INDICATOR_MANAGER_H
#define _STATUS_INDICATOR_MANAGER_H

#include "StatusIndicator.h"

class StatusIndicatorManager
{
public:

    StatusIndicatorManager()
    {
        _first = NULL;
    }

    void add(StatusIndicator* indicator);

    void indicateMoveExecuting(MOVE move);

    void indicateMoveExecuted(MOVE move);

    void indicateMoveAdded(MOVE move);

    void indicateProgramStarted(uint8_t total_moves);

    void indicateProgramFinished();

    void indicateProgramReset();

    void indicateProgramAborted(uint8_t executed, uint8_t total);

private:

    StatusIndicator* _first;

};

#endif // _STATUS_INDICATOR_MANAGER_H

// EOF
