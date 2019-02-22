// KeypadLeds.cpp
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

#include "KeypadLeds.h"
#include "Enums.h"
#include "Arduino.h"
#include "EventManager.h"

//////////////////////////////////////////////////////////////////////

extern EventManager* EVENTS;

//////////////////////////////////////////////////////////////////////

KeypadLeds::KeypadLeds(const Config* config)
{
    this->_config = config;

    _isPause = false;
}

//////////////////////////////////////////////////////////////////////

void KeypadLeds::init()
{
    pinMode(_config->pin_led_up, OUTPUT);
    pinMode(_config->pin_led_right, OUTPUT);
    pinMode(_config->pin_led_down, OUTPUT);
    pinMode(_config->pin_led_left, OUTPUT);
    pinMode(_config->pin_led_go, OUTPUT);

    EVENTS->add(this);
}

//////////////////////////////////////////////////////////////////////

void KeypadLeds::setLed(uint8_t button, bool light)
{
    int val = light ? HIGH : LOW;

    switch (button)
    {
        case BUTTON_UP:
            digitalWrite(_config->pin_led_up, val);
            break;

        case BUTTON_RIGHT:
            digitalWrite(_config->pin_led_right, val);
            break;

        case BUTTON_DOWN:
            digitalWrite(_config->pin_led_down, val);
            break;

        case BUTTON_LEFT:
            digitalWrite(_config->pin_led_left, val);
            break;

        case BUTTON_GO:
            digitalWrite(_config->pin_led_go, val);
            break;
    }
}

//////////////////////////////////////////////////////////////////////

void KeypadLeds::setAllLed(bool light)
{
    int val = light ? HIGH : LOW;

    digitalWrite(_config->pin_led_up, val);
    digitalWrite(_config->pin_led_right, val);
    digitalWrite(_config->pin_led_down, val);
    digitalWrite(_config->pin_led_left, val);
    digitalWrite(_config->pin_led_go, val);
}

//////////////////////////////////////////////////////////////////////

void KeypadLeds::tick(uint32_t micros)
{
    if (_isPause)
    {
        setLed(BUTTON_PAUSE, (micros / 100000) % 2);
    }
}

//////////////////////////////////////////////////////////////////////

BUTTON KeypadLeds::_mov2btn(MOVE move)
{
    switch (move) {

        case MOVE_FORWARD:
            return BUTTON_UP;
            // break;

        case MOVE_RIGHT:
            return BUTTON_RIGHT;
            // break;

        case MOVE_ALT_RIGHT:
            return BUTTON_RIGHT;
            // break;

        case MOVE_BACKWARD:
            return BUTTON_DOWN;
            // break;

        case MOVE_LEFT:
            return BUTTON_LEFT;
            // break;

        case MOVE_ALT_LEFT:
            return BUTTON_LEFT;
            // break;
    }

    return BUTTON_NONE;
}

//////////////////////////////////////////////////////////////////////

// EOF
