// EventListener.h
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

#ifndef _STATUS_INDICATOR_H
#define _STATUS_INDICATOR_H

#include <stddef.h>
#include "Enums.h"


/**
 * \brief Abstract event listener to be implemented by listeners.
 * \author @caligari
 */
class EventListener
{

public:

    EventListener()
    {
        this->_next = NULL;
    }

    EventListener* getNext()
    {
        return this->_next;
    }

    void setNext(EventListener* value)
    {
        this->_next = value;
    }

    //////////////////////////////////////////////////////////////////////
    // public interface
    //////////////////////////////////////////////////////////////////////

    virtual void tick(uint32_t micros) {}

    /**
     * Handles when a movement from the program has started its execution.
     * @param move The movement.
     */
    virtual void moveExecuting(MOVE move) {}

    /**
     * Handles when a movement from the program has finished its execution.
     * @param move The movement.
     */
    virtual void moveExecuted(MOVE move) {}

    /**
     * Handles when a new movement was added to the program.
     * @param move The movement.
     */
    virtual void moveAdded(MOVE move) {}

    /**
     * Handles when the program has started.
     * @param total_moves Total moves in the program.
     */
    virtual void programStarted(uint8_t total_moves) {}

    /**
     * Handles when the program has finished.
     */
    virtual void programFinished() {}

    /**
     * Handles when the program has reset.
     */
    virtual void programReset() {}

    /**
     * Handles when the program was aborted.
     * @param executed Number of executed moves after aborted.
     * @param total Total moves in the program.
     */
    virtual void programAborted(uint8_t executed, uint8_t total) {}

    /**
     * Handles when a button was pressed.
     * @param button The button.
     */
    virtual void buttonPressed(BUTTON button) {}

    /**
     * Handles when a button was released.
     * @param button The button.
     */
    virtual void buttonReleased(BUTTON button) {}

    /**
     * Handles when a button was long released.
     * @param button The button.
     */
    virtual void buttonLongReleased(BUTTON button) {}

    /**
     * Handles when a new game mode was selected
     * @param mode The game mode (see GAME_MODE_* enumeration)
     */
    virtual void gameModeSelected(GAME_MODE mode) {}

private:

    EventListener* _next;
};

#endif //  _EVENT_LISTENER_H

// EOF
