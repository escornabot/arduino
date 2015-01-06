// StatusIndicatorManager.cpp
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

#include "StatusIndicatorManager.h"

//////////////////////////////////////////////////////////////////////

void StatusIndicatorManager::add(StatusIndicator* indicator)
{
    if (_first == NULL)
    {
        _first = indicator;
    }
    else
    {
        StatusIndicator* i = _first;
        while (i->getNext() != NULL) i = i->getNext();
        i->setNext(indicator);
    }
}

//////////////////////////////////////////////////////////////////////

void StatusIndicatorManager::indicateMoveExecuting(MOVE move)
{
    StatusIndicator* i = _first;
    while (i != NULL)
    {
        i->moveExecuting(move);
        i = i->getNext();
    }
}

//////////////////////////////////////////////////////////////////////

void StatusIndicatorManager::indicateMoveExecuted(MOVE move)
{
    StatusIndicator* i = _first;
    while (i != NULL)
    {
        i->moveExecuted(move);
        i = i->getNext();
    }
}

//////////////////////////////////////////////////////////////////////

void StatusIndicatorManager::indicateMoveAdded(MOVE move)
{
    StatusIndicator* i = _first;
    while (i != NULL)
    {
        i->moveAdded(move);
        i = i->getNext();
    }
}

//////////////////////////////////////////////////////////////////////

void StatusIndicatorManager::indicateProgramStarted(uint8_t total_moves)
{
    StatusIndicator* i = _first;
    while (i != NULL)
    {
        i->programStarted(total_moves);
        i = i->getNext();
    }
}

//////////////////////////////////////////////////////////////////////

void StatusIndicatorManager::indicateProgramFinished()
{
    StatusIndicator* i = _first;
    while (i != NULL)
    {
        i->programFinished();
        i = i->getNext();
    }
}

//////////////////////////////////////////////////////////////////////

void StatusIndicatorManager::indicateProgramReset()
{
    StatusIndicator* i = _first;
    while (i != NULL)
    {
        i->programReset();
        i = i->getNext();
    }
}

//////////////////////////////////////////////////////////////////////

void StatusIndicatorManager::indicateProgramAborted(uint8_t executed, uint8_t total)
{
    StatusIndicator* i = _first;
    while (i != NULL)
    {
        i->programAborted(executed, total);
        i = i->getNext();
    }
}

//////////////////////////////////////////////////////////////////////

// EOF
