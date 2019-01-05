// ButtonSetDigital.cpp
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

#include "ButtonSetDigital.h"
#include "Configuration.h"
#include <Arduino.h>

ButtonSetDigital::ButtonSetDigital(const Config* config)
{
    this->_config = config;

    for (int b = 0; b < 6; b++) _btn_state[b] = false;
}


void ButtonSetDigital::init()
{
    ButtonSet::init();

    // configure Arduino pins
    pinMode(_config->pin_button_up, INPUT);
    pinMode(_config->pin_button_right, INPUT);
    pinMode(_config->pin_button_down, INPUT);
    pinMode(_config->pin_button_left, INPUT);
    pinMode(_config->pin_button_go, INPUT);
    pinMode(_config->pin_button_reset, INPUT);
}


void ButtonSetDigital::scanButtons()
{
    bool state;

    state = (digitalRead(_config->pin_button_up) == HIGH);
    if (state ^ isPressed(BUTTON_UP))
    {
            if (state) pressed(BUTTON_UP); else released(BUTTON_UP);
    }

    state = (digitalRead(_config->pin_button_right) == HIGH);
    if (state ^ isPressed(BUTTON_RIGHT))
    {
            if (state) pressed(BUTTON_RIGHT); else released(BUTTON_RIGHT);
    }

    state = (digitalRead(_config->pin_button_down) == HIGH);
    if (state ^ isPressed(BUTTON_DOWN))
    {
            if (state) pressed(BUTTON_DOWN); else released(BUTTON_DOWN);
    }

    state = (digitalRead(_config->pin_button_left) == HIGH);
    if (state ^ isPressed(BUTTON_LEFT))
    {
            if (state) pressed(BUTTON_LEFT); else released(BUTTON_LEFT);
    }

    state = (digitalRead(_config->pin_button_go) == HIGH);
    if (state ^ isPressed(BUTTON_GO))
    {
            if (state) pressed(BUTTON_GO); else released(BUTTON_GO);
    }

    state = (digitalRead(_config->pin_button_reset) == HIGH);
    if (state ^ isPressed(BUTTON_RESET))
    {
            if (state) pressed(BUTTON_RESET); else released(BUTTON_RESET);
    }
}

// EOF
