// Setup.cpp
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

#include "Setup.h"
#include "EventManager.h"
#include "KeypadAnalog.h"
#include <Arduino.h>

//////////////////////////////////////////////////////////////////////

extern EventManager* EVENTS;
extern KeypadAnalog* BUTTONS;

//////////////////////////////////////////////////////////////////////

void Setup::init()
{
    EVENTS->add(this);
}

//////////////////////////////////////////////////////////////////////

bool Setup::buttonLongReleased(BUTTON button)
{
    // bubble the event
    if (millis() > 5000 && _step == SETUP_NO_SETUP) return false;

    switch (_step)
    {
        case SETUP_NO_SETUP:
            #if defined(BUTTONS_ANALOG)
            _step = SETUP_KEYPAD_UP;
            #endif
            break;

        case SETUP_KEYPAD_UP:
            BUTTONS->reconfigureLast(BUTTON_UP);
            _step = SETUP_KEYPAD_RIGHT;
            break;

        case SETUP_KEYPAD_RIGHT:
            BUTTONS->reconfigureLast(BUTTON_RIGHT);
            _step = SETUP_KEYPAD_DOWN;
            break;

        case SETUP_KEYPAD_DOWN:
            BUTTONS->reconfigureLast(BUTTON_DOWN);
            _step = SETUP_KEYPAD_LEFT;
            break;

        case SETUP_KEYPAD_LEFT:
            BUTTONS->reconfigureLast(BUTTON_LEFT);
            _step = SETUP_KEYPAD_GO;
            break;

        case SETUP_KEYPAD_GO:
            BUTTONS->reconfigureLast(BUTTON_GO);
            if (BUTTONS->hasResetButton())
                _step = SETUP_KEYPAD_RESET;
            else
                _step = SETUP_NO_SETUP;
            break;

        case SETUP_KEYPAD_RESET:
            BUTTONS->reconfigureLast(BUTTON_RESET);
            _step = SETUP_NO_SETUP;
            break;
    }

    // don't bubble events
    return true;
}

//////////////////////////////////////////////////////////////////////

// EOF
