// ButtonSetAnalog.cpp

#include "ButtonSetAnalog.h"

#include "Arduino.h"

// arduino value when analog input is open
#define OPEN_VALUE  1023


ButtonSetAnalog::ButtonSetAnalog(const Config* config)
{
    this->_config = config;
}


void ButtonSetAnalog::init()
{
    pinMode(_config->pin_button_set, INPUT);
    _last_value = 0;
}


inline int16_t _abs(int16_t v)
{
    return (v < 0 ? -v : v);
}


ButtonSet::BUTTON ButtonSetAnalog::scanButtons()
{
    int16_t value = analogRead(_config->pin_button_set);

    if (value < 10 && _last_value > 0)
    {
        // release
        BUTTON button = BUTTON_UP;
        int16_t minor_diff = _abs(_last_value - _config->value_button_up);

        int16_t diff = _abs(_last_value - _config->value_button_right);
        Serial.print(diff); Serial.print(" ");
        if (diff < minor_diff)
        {
            minor_diff = diff;
            button = BUTTON_RIGHT;
        }

        diff = _abs(_last_value - _config->value_button_down);
        Serial.print(diff); Serial.print(" ");
        if (diff < minor_diff)
        {
            minor_diff = diff;
            button = BUTTON_DOWN;
        }

        diff = _abs(_last_value - _config->value_button_left);
        Serial.print(diff); Serial.print(" ");
        if (diff < minor_diff)
        {
            minor_diff = diff;
            button = BUTTON_LEFT;
        }

        diff = _abs(_last_value - _config->value_button_go);
        Serial.print(diff); Serial.print(" ");
        if (diff < minor_diff)
        {
            minor_diff = diff;
            button = BUTTON_GO;
        }

        diff = _abs(_last_value - _config->value_button_reset);
        Serial.print(diff); Serial.print(" ");
        if (diff < minor_diff)
        {
            minor_diff = diff;
            button = BUTTON_RESET;
        }

        Serial.println(button);

        _last_value = 0;
        return button;
    }

    _last_value = value;
    return BUTTON_NONE;
}
