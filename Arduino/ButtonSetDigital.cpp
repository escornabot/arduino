// ButtonSetDigital.cpp

#include "ButtonSetDigital.h"

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
}

// EOF
