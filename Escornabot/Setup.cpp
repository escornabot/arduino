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
#include <Arduino.h>
#include "Configuration.h"

//////////////////////////////////////////////////////////////////////

extern EventManager* EVENTS;

#if defined(BUTTONS_ANALOG)
#include "KeypadAnalog.h"
extern KeypadAnalog* BUTTONS;
#endif

#if USE_KEYPAD_LEDS
#include "LedsKeypad.h"
extern LedsKeypad KEYPAD_LEDS;
#endif


//////////////////////////////////////////////////////////////////////

void Setup::init()
{
    EVENTS->add(this);
}

//////////////////////////////////////////////////////////////////////


void Setup::_changeStateBefore(STATE state_to)
{
}

//////////////////////////////////////////////////////////////////////

void Setup::_changeStateAfter(STATE state_from)
{
    KEYPAD_LEDS.setAllLed(false);

    switch (getState())
    {
        case SETUP_KEYPAD_UP:
            KEYPAD_LEDS.setLed(BUTTON_UP, true);
            break;

        case SETUP_KEYPAD_RIGHT:
            KEYPAD_LEDS.setLed(BUTTON_RIGHT, true);
            break;

        case SETUP_KEYPAD_DOWN:
            KEYPAD_LEDS.setLed(BUTTON_DOWN, true);
            break;

        case SETUP_KEYPAD_LEFT:
            KEYPAD_LEDS.setLed(BUTTON_LEFT, true);
            break;

        case SETUP_KEYPAD_GO:
            KEYPAD_LEDS.setLed(BUTTON_GO, true);
            break;

        case SETUP_KEYPAD_RESET:
            KEYPAD_LEDS.setLed(BUTTON_RESET, true);
            break;
    }
}

//////////////////////////////////////////////////////////////////////

bool Setup::buttonLongReleased(BUTTON button)
{
    #if defined(BUTTONS_ANALOG)
    if (getState() == SETUP_NO_SETUP && millis() < 5000)
    {
        // start configuring the keypad
        changeState(SETUP_KEYPAD_UP);

        // don't bubble the event
        return true;
    }
    #endif

    return false;
}

//////////////////////////////////////////////////////////////////////

bool Setup::tick(uint32_t micros)
{
    return false;
}

//////////////////////////////////////////////////////////////////////

// EOF
