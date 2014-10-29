// ButtonSetDigital.cpp
/*

Copyright (C) 2014 Bricolabs - http://bricolabs.cc

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
	// configure Arduino pins
	pinMode(_config->pin_button_up, INPUT);
	pinMode(_config->pin_button_right, INPUT);
	pinMode(_config->pin_button_down, INPUT);
	pinMode(_config->pin_button_left, INPUT);
	pinMode(_config->pin_button_go, INPUT);
	pinMode(_config->pin_button_reset, INPUT);
}


ButtonSet::BUTTON ButtonSetDigital::scanButtons()
{
	delay(BUTTON_MIN_PRESSED);

	if (digitalRead(_config->pin_button_up) ^ _btn_state[0])
	{
		_btn_state[0] = !_btn_state[0];
		if (_btn_state[0]) return BUTTON_UP;
	}

	if (digitalRead(_config->pin_button_right) ^ _btn_state[1])
	{
		_btn_state[1] = !_btn_state[1];
		if (_btn_state[1]) return BUTTON_RIGHT;
	}

	if (digitalRead(_config->pin_button_down) ^ _btn_state[2])
	{
		_btn_state[2] = !_btn_state[2];
		if (_btn_state[2]) return BUTTON_DOWN;
	}

	if (digitalRead(_config->pin_button_left) ^ _btn_state[3])
	{
		_btn_state[3] = !_btn_state[3];
		if (_btn_state[3]) return BUTTON_LEFT;
	}

	if (digitalRead(_config->pin_button_go) ^ _btn_state[4])
	{
		_btn_state[4] = !_btn_state[4];
		if (_btn_state[4]) return BUTTON_GO;
	}

	if (digitalRead(_config->pin_button_reset) ^ _btn_state[5])
	{
		_btn_state[5] = !_btn_state[5];
		if (_btn_state[5]) return BUTTON_RESET;
	}

	return BUTTON_NONE;
}

// EOF
