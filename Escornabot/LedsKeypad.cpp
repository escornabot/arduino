// LedsKeypad.cpp
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

#include "LedsKeypad.h"
#include "Enums.h"
#include "Arduino.h"
#include "EventManager.h"
#include "SimpleLed.h"

//////////////////////////////////////////////////////////////////////

extern EventManager* EVENTS;

//////////////////////////////////////////////////////////////////////

LedsKeypad::LedsKeypad(const Config* config) : _leds({
    SimpleLed(config->pin_led_up),
    SimpleLed(config->pin_led_right),
    SimpleLed(config->pin_led_down),
    SimpleLed(config->pin_led_left),
    SimpleLed(config->pin_led_go) })
{
}

//////////////////////////////////////////////////////////////////////

void LedsKeypad::init()
{
    for (int b = 0; b < 5; b++) _leds[b].init();

    EVENTS->add(this);
}

//////////////////////////////////////////////////////////////////////

void LedsKeypad::setStatus(BUTTON button, bool light)
{
    if (button >= 1 && button <= 5) _leds[--button].setStatus(light);
}

//////////////////////////////////////////////////////////////////////

void LedsKeypad::setStatusAll(bool light)
{
    for (int b = 0; b < 5; b++) _leds[b].setStatus(light);
}

//////////////////////////////////////////////////////////////////////

BUTTON LedsKeypad::_mov2btn(MOVE move)
{
    if (move >= 1 && move <= 4) return (BUTTON)move;
    return BUTTON_NONE;
}

//////////////////////////////////////////////////////////////////////

// EOF
