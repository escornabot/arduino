// KeypadDigital.cpp
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

#include "KeypadDigital.h"
#include "Configuration.h"

//////////////////////////////////////////////////////////////////////

KeypadDigital::KeypadDigital(const Config* config)
{
    this->_config = config;

    for (int b = 0; b < 6; b++) _btn_state[b] = false;
}

//////////////////////////////////////////////////////////////////////

void KeypadDigital::init()
{
    Keypad::init();

    // configure Arduino pins
    _configPin(_config->pin_button_up);
    _configPin(_config->pin_button_right);
    _configPin(_config->pin_button_down);
    _configPin(_config->pin_button_left);
    _configPin(_config->pin_button_go);
    _configPin(_config->pin_button_reset);
}

//////////////////////////////////////////////////////////////////////

void KeypadDigital::_scanBtn(bool state, BUTTON button)
{
    if (state ^ isPressed(button))
    {
        // was changed
        if (state) pressed(button); else released(button);
    }
}

//////////////////////////////////////////////////////////////////////

void KeypadDigital::scanButtons()
{
    _scanBtn(digitalRead(_config->pin_button_up) == HIGH, BUTTON_UP);
    _scanBtn(digitalRead(_config->pin_button_right) == HIGH, BUTTON_RIGHT);
    _scanBtn(digitalRead(_config->pin_button_down) == HIGH, BUTTON_DOWN);
    _scanBtn(digitalRead(_config->pin_button_left) == HIGH, BUTTON_LEFT);
    _scanBtn(digitalRead(_config->pin_button_go) == HIGH, BUTTON_GO);
    _scanBtn(digitalRead(_config->pin_button_reset) == HIGH, BUTTON_RESET);
}

//////////////////////////////////////////////////////////////////////

// EOF
