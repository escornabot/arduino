// EventManager.cpp
/*

Copyright (C) 2014-2017 Escornabot - http://escornabot.com

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

#include "EventManager.h"

//////////////////////////////////////////////////////////////////////

void EventManager::add(EventListener* indicator)
{
    if (_first == NULL)
    {
        _first = indicator;
    }
    else
    {
        EventListener* i = _first;
        while (i->getNext() != NULL) i = i->getNext();
        i->setNext(indicator);
    }
}

//////////////////////////////////////////////////////////////////////

void EventManager::indicateTick(uint32_t micros)
{
    EventListener* i = _first;
    while (i != NULL)
    {
        if (i->tick(micros)) break;
        i = i->getNext();
    }
}

//////////////////////////////////////////////////////////////////////

void EventManager::indicateMoveExecuting(MOVE move)
{
    EventListener* i = _first;
    while (i != NULL)
    {
        if (i->moveExecuting(move)) break;
        i = i->getNext();
    }
}

//////////////////////////////////////////////////////////////////////

void EventManager::indicateMoveExecuted(MOVE move)
{
    EventListener* i = _first;
    while (i != NULL)
    {
        if (i->moveExecuted(move)) break;
        i = i->getNext();
    }
}

//////////////////////////////////////////////////////////////////////

void EventManager::indicateMoveAdded(MOVE move)
{
    EventListener* i = _first;
    while (i != NULL)
    {
        if (i->moveAdded(move)) break;
        i = i->getNext();
    }
}

//////////////////////////////////////////////////////////////////////

void EventManager::indicateProgramStarted(uint8_t total_moves)
{
    EventListener* i = _first;
    while (i != NULL)
    {
        if (i->programStarted(total_moves)) break;
        i = i->getNext();
    }
}

//////////////////////////////////////////////////////////////////////

void EventManager::indicateProgramFinished()
{
    EventListener* i = _first;
    while (i != NULL)
    {
        if (i->programFinished()) break;
        i = i->getNext();
    }
}

//////////////////////////////////////////////////////////////////////

void EventManager::indicateProgramReset()
{
    EventListener* i = _first;
    while (i != NULL)
    {
        if (i->programReset()) break;
        i = i->getNext();
    }
}

//////////////////////////////////////////////////////////////////////

void EventManager::indicateProgramAborted(uint8_t executed, uint8_t total)
{
    EventListener* i = _first;
    while (i != NULL)
    {
        if (i->programAborted(executed, total)) break;
        i = i->getNext();
    }
}

//////////////////////////////////////////////////////////////////////

void EventManager::indicateButtonPressed(BUTTON button)
{
    EventListener* i = _first;
    while (i != NULL)
    {
        if (i->buttonPressed(button)) break;
        i = i->getNext();
    }
}

//////////////////////////////////////////////////////////////////////

void EventManager::indicateButtonReleased(BUTTON button)
{
    EventListener* i = _first;
    while (i != NULL)
    {
        if (i->buttonReleased(button)) break;
        i = i->getNext();
    }
}

//////////////////////////////////////////////////////////////////////

void EventManager::indicateButtonLongReleased(BUTTON button)
{
    EventListener* i = _first;
    while (i != NULL)
    {
        if (i->buttonLongReleased(button)) break;
        i = i->getNext();
    }
}

//////////////////////////////////////////////////////////////////////


// EOF
