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
    STATE state = getState();

    if (state >= SETUP_KEYPAD_UP && state <= SETUP_KEYPAD_RESET)
    {
        KEYPAD_LEDS.getLed((BUTTON)state)->blink(false);
    }
}

//////////////////////////////////////////////////////////////////////

void Setup::_changeStateAfter(STATE state_from)
{
    switch (getState())
    {
        case SETUP_KEYPAD_UP:
            KEYPAD_LEDS.getLed(BUTTON_UP)->blink(true);
            BUTTONS->rescan(BUTTON_UP);
            break;

        case SETUP_KEYPAD_RIGHT:
            KEYPAD_LEDS.getLed(BUTTON_RIGHT)->blink(true);
            BUTTONS->rescan(BUTTON_RIGHT);
            break;

        case SETUP_KEYPAD_DOWN:
            KEYPAD_LEDS.getLed(BUTTON_DOWN)->blink(true);
            BUTTONS->rescan(BUTTON_DOWN);
            break;

        case SETUP_KEYPAD_LEFT:
            KEYPAD_LEDS.getLed(BUTTON_LEFT)->blink(true);
            BUTTONS->rescan(BUTTON_LEFT);
            break;

        case SETUP_KEYPAD_GO:
            KEYPAD_LEDS.getLed(BUTTON_GO)->blink(true);
            BUTTONS->rescan(BUTTON_GO);
            break;

        case SETUP_KEYPAD_RESET:
            KEYPAD_LEDS.getLed(BUTTON_RESET)->blink(true);
            BUTTONS->rescan(BUTTON_RESET);
            break;
    }
}

//////////////////////////////////////////////////////////////////////

bool Setup::buttonLongReleased(BUTTON button)
{
    if (getState() == SETUP_NO_SETUP)
    {
        if (_wait_for_setup)
        {
            #if defined(BUTTONS_ANALOG)
            // start configuring the keypad
            changeState(SETUP_KEYPAD_UP);
            #endif

            _wait_for_setup = 0;

            // don't bubble the event
            return true;
        }
    }

    return false;
}

//////////////////////////////////////////////////////////////////////

bool Setup::tick(uint32_t micros)
{
    if (_wait_for_setup)
    {
        // current second
        int second = (micros / 1000000) + 1;

        if (_wait_for_setup != 6 - second)
        {
            // second has changed
            KEYPAD_LEDS.setStatus((BUTTON)second, true);
            KEYPAD_LEDS.setStatus((BUTTON)second - 1, false);
            _wait_for_setup--;
        }
    }
    else if (getState() >= SETUP_KEYPAD_UP && getState() <= SETUP_KEYPAD_RESET)
    {
        // configuring the keypad
        if (!(BUTTONS->isRescanning()))
        {
            if (getState() == SETUP_KEYPAD_RESET)
            {
                // finished
                changeState(SETUP_NO_SETUP);
            }
            else
            {
                // next state
                changeState(getState() + 1);
            }
        }
    }

    return false;
}

//////////////////////////////////////////////////////////////////////

// EOF
