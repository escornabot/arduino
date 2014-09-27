// ButtonSetAnalog.cpp

#include "ButtonSetAnalog.h"

#include <Arduino.h>

// arduino value when analog input is open
#define OPEN_VALUE  1023

ButtonSetAnalog::ButtonSetAnalog(const Config* config)
{
    this->_config = config;
}


void ButtonSetAnalog::init()
{
    pinMode(_config->pin_button_set, INPUT);
    _last_button = BUTTON_NONE;
}


ButtonSet::BUTTON ButtonSetAnalog::scanButtons()
{
    delay(200);
    int16_t value = analogRead(_config->pin_button_set);
    int16_t diff, minor_diff;

    minor_diff = value;
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

    // return button only when it changes
    if (button != _last_button)
    {
        _last_button = button;
        return button;
    }

    return BUTTON_NONE;
}
