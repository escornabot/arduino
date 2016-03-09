// KeypadLeds.cpp

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

BUTTON KeypadLeds::_mov2btn(MOVE move)
{
    switch (move) {

        case MOVE_FORWARD:
            return BUTTON_UP;
            // break;

        case MOVE_RIGHT:
            return BUTTON_RIGHT;
            // break;

        case MOVE_BACKWARD:
            return BUTTON_DOWN;
            // break;

        case MOVE_LEFT:
            return BUTTON_LEFT;
            // break;
    }

    return BUTTON_NONE;
}

//////////////////////////////////////////////////////////////////////

// EOF
