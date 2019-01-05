// BluetoothInterface.h
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

#ifndef _BLUETOOTH_INTERFACE_H
#define _BLUETOOTH_INTERFACE_H

#include "ButtonSet.h"
#include "EventListener.h"
#include <Arduino.h>

#define COMMAND_MAX_LENGTH 10

/**
 * \brief Interface to use a bluetooth module over serial interface
 * \author @caligari
 */
class BluetoothInterface : public ButtonSet
{
public:

    typedef struct {
        HardwareSerial* serial;
        uint32_t bauds;
    } Config;

    /**
     * Constructor.
     */
    BluetoothInterface(const Config* cfg);

    ////////////////////////////////////////////////////////////
    // ButtonSet interface
    ////////////////////////////////////////////////////////////

    /**
     * Does the hardware initialization.
     */
    virtual void init();

    /**
     * Reads the buttons
     * @return The button being pressed.
     */
    virtual void scanButtons();

    ////////////////////////////////////////////////////////////
    // EventListener interface
    ////////////////////////////////////////////////////////////

    /**
     * Handles when a movement from the program was executed.
     */
    virtual void MoveExecuting(MOVE move);

    /**
     * Handles when a movement from the program was executed.
     */
    virtual void MoveExecuted(MOVE move);

    /**
     * Handles when a new movement was added to the program.
     */
    virtual void MoveAdded(MOVE move);

    /**
     * Handles when the program has stated.
     */
    virtual void ProgramStarted(uint8_t total_moves);

    /**
     * Handles when the program has finished.
     */
    virtual void ProgramFinished();

    /**
     * Handles when the program has reset.
     */
    virtual void ProgramReset();

    /**
     * Handles when the program was aborted.
     */
    virtual void ProgramAborted(uint8_t executed, uint8_t total);

private:

    const Config* _config;

    char _command[COMMAND_MAX_LENGTH + 1];
    uint8_t _command_idx;

    bool _readLine();

};

#endif // _BLUETOOTH_INTERFACE_H

// EOF
