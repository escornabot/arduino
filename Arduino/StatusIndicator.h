// StatusIndicator.h
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

#ifndef _STATUS_INDICATOR_H
#define _STATUS_INDICATOR_H

<<<<<<< HEAD
#include "Move.h"
#include <stddef.h>

class StatusIndicator
{

public:

    StatusIndicator()
    {
        this->_next = NULL;
    }

    StatusIndicator* getNext()
    {
        return this->_next;
    }

    void setNext(StatusIndicator* value)
    {
        this->_next = value;
    }

    //////////////////////////////////////////////////////////////////////
    // public interface
    //////////////////////////////////////////////////////////////////////

=======
#include "MoveProgram.h"

class StatusIndicator
{
public:

>>>>>>> f6e182e... Indicador de estado por Bluetooth.
    /**
     * Handles when a movement from the program was executed.
     * @param move The movement.
     */
<<<<<<< HEAD
    virtual void moveExecuting(MOVE move) = 0;
=======
    virtual void SiMoveExecuting(MOVE move) = 0;
>>>>>>> f6e182e... Indicador de estado por Bluetooth.

    /**
     * Handles when a movement from the program was executed.
     * @param move The movement.
     */
<<<<<<< HEAD
    virtual void moveExecuted(MOVE move) = 0;
=======
    virtual void SiMoveExecuted(MOVE move) = 0;
>>>>>>> f6e182e... Indicador de estado por Bluetooth.

    /**
     * Handles when a new movement was added to the program.
     * @param move The movement.
     */
<<<<<<< HEAD
    virtual void moveAdded(MOVE move) = 0;
=======
    virtual void SiMoveAdded(MOVE move) = 0;
>>>>>>> f6e182e... Indicador de estado por Bluetooth.

    /**
     * Handles when the program has stated.
     * @param total_moves Total moves in the program.
     */
<<<<<<< HEAD
    virtual void programStarted(uint8_t total_moves) = 0;
=======
    virtual void SiProgramStarted(uint8_t total_moves) = 0;
>>>>>>> f6e182e... Indicador de estado por Bluetooth.

    /**
     * Handles when the program has finished.
     */
<<<<<<< HEAD
    virtual void programFinished() = 0;
=======
    virtual void SiProgramFinished() = 0;
>>>>>>> f6e182e... Indicador de estado por Bluetooth.

    /**
     * Handles when the program has reset.
     */
<<<<<<< HEAD
    virtual void programReset() = 0;
=======
    virtual void SiProgramReset() = 0;
>>>>>>> f6e182e... Indicador de estado por Bluetooth.

    /**
     * Handles when the program was aborted.
     * @param executed Number of executed moves after aborted.
     * @param total Total moves in the program.
     */
<<<<<<< HEAD
    virtual void programAborted(uint8_t executed, uint8_t total) = 0;

private:

    StatusIndicator* _next;
=======
    virtual void SiProgramAborted(uint8_t executed, uint8_t total) = 0;
>>>>>>> f6e182e... Indicador de estado por Bluetooth.
};

#endif //  _STATUS_INDICATOR_H

// EOF
