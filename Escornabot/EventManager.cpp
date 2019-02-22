// EventManager.cpp
/*

Copyright (C) 2014-2019 Escornabot - http://escornabot.com

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
        i->tick(micros);
        i = i->getNext();
    }
}

//////////////////////////////////////////////////////////////////////

void EventManager::indicateMoveExecuting(MOVE move)
{
    EventListener* i = _first;
    while (i != NULL)
    {
        i->moveExecuting(move);
        i = i->getNext();
    }
}

//////////////////////////////////////////////////////////////////////

void EventManager::indicateMoveExecuted(MOVE move)
{
    EventListener* i = _first;
    while (i != NULL)
    {
        i->moveExecuted(move);
        i = i->getNext();
    }
}

//////////////////////////////////////////////////////////////////////

void EventManager::indicateMoveAdded(MOVE move)
{
    EventListener* i = _first;
    while (i != NULL)
    {
        i->moveAdded(move);
        i = i->getNext();
    }
}

//////////////////////////////////////////////////////////////////////

void EventManager::indicateProgramStarted(uint8_t total_moves)
{
    EventListener* i = _first;
    while (i != NULL)
    {
        i->programStarted(total_moves);
        i = i->getNext();
    }
}

//////////////////////////////////////////////////////////////////////

void EventManager::indicateProgramFinished()
{
    EventListener* i = _first;
    while (i != NULL)
    {
        i->programFinished();
        i = i->getNext();
    }
}

//////////////////////////////////////////////////////////////////////

void EventManager::indicateProgramReset()
{
    EventListener* i = _first;
    while (i != NULL)
    {
        i->programReset();
        i = i->getNext();
    }
}

//////////////////////////////////////////////////////////////////////

void EventManager::indicateProgramAborted(uint8_t executed, uint8_t total)
{
    EventListener* i = _first;
    while (i != NULL)
    {
        i->programAborted(executed, total);
        i = i->getNext();
    }
}

//////////////////////////////////////////////////////////////////////

void EventManager::indicateButtonPressed(BUTTON button)
{
    EventListener* i = _first;
    while (i != NULL)
    {
        i->buttonPressed(button);
        i = i->getNext();
    }
}

//////////////////////////////////////////////////////////////////////

void EventManager::indicateButtonReleased(BUTTON button)
{
    EventListener* i = _first;
    while (i != NULL)
    {
        i->buttonReleased(button);
        i = i->getNext();
    }
}

//////////////////////////////////////////////////////////////////////

void EventManager::indicateButtonLongReleased(BUTTON button)
{
    EventListener* i = _first;
    while (i != NULL)
    {
        i->buttonLongReleased(button);
        i = i->getNext();
    }
}

//////////////////////////////////////////////////////////////////////

void EventManager::indicateGameModeSelected(GAME_MODE mode)
{
    EventListener* i = _first;
    while (i != NULL)
    {
        i->gameModeSelected(mode);
        i = i->getNext();
    }
}

//////////////////////////////////////////////////////////////////////

// EOF
