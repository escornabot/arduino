// Bluetooth.cpp
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

#include "Bluetooth.h"
#include <string.h>

#define NL '\n'

//////////////////////////////////////////////////////////////////////

const static char* BUTTONS_PRESSED = "NESWGR";
const static char* BUTTONS_RELEASED = "neswgr";
const static char* SI_PROGRAM = "PRG: ";

//////////////////////////////////////////////////////////////////////

#include "EventManager.h"
extern EventManager* EVENTS;

//////////////////////////////////////////////////////////////////////

Bluetooth::Bluetooth(const Config* cfg)
{
    _config = cfg;
    _command_idx = 0;
}

//////////////////////////////////////////////////////////////////////

void Bluetooth::init()
{
    _config->serial->begin(_config->bauds, SERIAL_8N1);

    EVENTS->add(this);
}

//////////////////////////////////////////////////////////////////////

void Bluetooth::_readInput()
{
    while (_readLine())
    {
        // one-char commands
        if (strlen(_command) == 1)
        {
            char* found = strchr(BUTTONS_PRESSED, _command[0]);
            if (found)
            {
                BUTTON button = (BUTTON)((found - BUTTONS_PRESSED) + 1);
                EVENTS->indicateButtonLongReleased(button);
            }

            found = strchr(BUTTONS_RELEASED, _command[0]);
            if (found)
            {
                BUTTON button = (BUTTON)((found - BUTTONS_RELEASED) + 1);
                EVENTS->indicateButtonReleased(button);
            }
        }
    }
}

//////////////////////////////////////////////////////////////////////

bool Bluetooth::_readLine()
{
    while (_config->serial->available())
    {
        char key = _config->serial->read();

        if (key == NL)
        {
            _command[_command_idx] = '\0';
            _command_idx = 0;
            return true;
        }

        if (_command_idx < COMMAND_MAX_LENGTH)
        {
            _command[_command_idx++] = key;
        }
    }
    return false;
}

//////////////////////////////////////////////////////////////////////

bool Bluetooth::tick(uint32_t micros)
{
    _readInput();

    return false;
}

//////////////////////////////////////////////////////////////////////

bool Bluetooth::moveExecuting(MOVE move)
{
    _config->serial->print(SI_PROGRAM);
    _config->serial->print(BUTTONS_PRESSED[move - 1]);
    _config->serial->print(" INI");
    _config->serial->print(NL);

    return false;
}

//////////////////////////////////////////////////////////////////////

bool Bluetooth::moveExecuted(MOVE move)
{
    _config->serial->print(SI_PROGRAM);
    _config->serial->print(BUTTONS_RELEASED[move - 1]);
    _config->serial->print(" END");
    _config->serial->print(NL);

    return false;
}

//////////////////////////////////////////////////////////////////////

bool Bluetooth::moveAdded(MOVE move)
{
    _config->serial->print(SI_PROGRAM);
    _config->serial->print(BUTTONS_RELEASED[move - 1]);
    _config->serial->print(NL);

    return false;
}

//////////////////////////////////////////////////////////////////////

bool Bluetooth::programStarted(uint8_t total_moves)
{
    _config->serial->print(SI_PROGRAM);
    _config->serial->print("GO ");
    _config->serial->print(total_moves);
    _config->serial->print(NL);

    return false;
}

//////////////////////////////////////////////////////////////////////

bool Bluetooth::programFinished()
{
    _config->serial->print(SI_PROGRAM);
    _config->serial->print("END");
    _config->serial->print(NL);

    return false;
}

//////////////////////////////////////////////////////////////////////

bool Bluetooth::programReset()
{
    _config->serial->print(SI_PROGRAM);
    _config->serial->print("RESET");
    _config->serial->print(NL);

    return false;
}

//////////////////////////////////////////////////////////////////////

bool Bluetooth::programAborted(uint8_t executed, uint8_t total)
{
    _config->serial->print(SI_PROGRAM);
    _config->serial->print("ABORTED ");
    _config->serial->print(executed);
    _config->serial->print("/");
    _config->serial->print(total);
    _config->serial->print(NL);

    return false;
}

//////////////////////////////////////////////////////////////////////

// EOF
