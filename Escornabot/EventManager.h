// EventManager.h
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

#ifndef _EVENT_MANAGER_H
#define _EVENT_MANAGER_H

#include "EventListener.h"

/**
 * \brief Event manager that receives events and dispatch to listeners.
 * \author @caligari
 */
class EventManager
{
public:

    EventManager()
    {
        _first = NULL;
    }

    void add(EventListener* indicator);

    void indicateTick(uint32_t micros);

    void indicateMoveExecuting(MOVE move);

    void indicateMoveExecuted(MOVE move);

    void indicateMoveAdded(MOVE move);

    void indicateProgramStarted(uint8_t total_moves);

    void indicateProgramFinished();

    void indicateProgramReset();

    void indicateProgramAborted(uint8_t executed, uint8_t total);

    void indicateButtonPressed(BUTTON button);

    void indicateButtonReleased(BUTTON button);

    void indicateButtonLongReleased(BUTTON button);

    void indicateGameModeSelected(GAME_MODE mode);

private:

    EventListener* _first;

};

#endif // _EVENT_MANAGER_H

// EOF
