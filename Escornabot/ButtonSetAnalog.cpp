// ButtonSetAnalog.cpp
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

#include "ButtonSetAnalog.h"
#include "Configuration.h"
#include <Arduino.h>

#if (BS_ANALOG_WIRES == 2)
#    define PULLUP_VALUE 990
#else
#    define PULLUP_VALUE 0
#endif

//////////////////////////////////////////////////////////////////////

ButtonSetAnalog::ButtonSetAnalog(const Config* config)
{
    this->_config = config;
}

//////////////////////////////////////////////////////////////////////

void ButtonSetAnalog::init()
{
    ButtonSet::init();
    pinMode(_config->pin_button_set, (_config->pullup ? INPUT_PULLUP : INPUT));
    _last_button = BUTTON_NONE;
}

//////////////////////////////////////////////////////////////////////

void ButtonSetAnalog::scanButtons()
{
    int16_t value = analogRead(_config->pin_button_set);
    int16_t diff, minor_diff;

    minor_diff = abs(value - PULLUP_VALUE);
    BUTTON button = BUTTON_NONE;

    diff = abs(value - _config->value_button_up);
    if (diff < minor_diff)
    {
        minor_diff = diff;
        button = BUTTON_UP;
    }

    diff = abs(value - _config->value_button_right);
    if (diff < minor_diff)
    {
        minor_diff = diff;
        button = BUTTON_RIGHT;
    }

    diff = abs(value - _config->value_button_down);
    if (diff < minor_diff)
    {
        minor_diff = diff;
        button = BUTTON_DOWN;
    }

    diff = abs(value - _config->value_button_left);
    if (diff < minor_diff)
    {
        minor_diff = diff;
        button = BUTTON_LEFT;
    }

    diff = abs(value - _config->value_button_go);
    if (diff < minor_diff)
    {
        minor_diff = diff;
        button = BUTTON_GO;
    }

    diff = abs(value - _config->value_button_reset);
    if (diff < minor_diff)
    {
        minor_diff = diff;
        button = BUTTON_RESET;
    }

    if (button != _last_button)
    {
        if (_last_button != BUTTON_NONE) released(_last_button);
        if (button != BUTTON_NONE) pressed(button);
        _last_button = button;
    }
}

//////////////////////////////////////////////////////////////////////

// EOF
