// EngineL9110.cpp

#include "EngineL9110.h"
#include <Arduino.h>


EngineL9110::EngineL9110(const Config* config)
{
    this->_config = config;
}


void EngineL9110::init()
{
    pinMode(_config->motor_left_a, OUTPUT);
    pinMode(_config->motor_left_b, OUTPUT);
    pinMode(_config->motor_right_a, OUTPUT);
    pinMode(_config->motor_right_b, OUTPUT);
}


void EngineL9110::motorOn(MOTOR motor, bool reverse)
{
    uint8_t a_value = (reverse ? LOW : HIGH);
    uint8_t b_value = (reverse ? HIGH : LOW);

    if (motor == MOTOR_RIGHT)
    {
        // right motor
        digitalWrite(_config->motor_right_a, a_value);
        digitalWrite(_config->motor_right_b, b_value);
    }
    else
    {
        // left motor
        digitalWrite(_config->motor_left_a, a_value);
        digitalWrite(_config->motor_left_b, b_value);
    }
}


void EngineL9110::motorOff(MOTOR motor)
{
    if (motor == MOTOR_RIGHT)
    {
        // motor dereita
        digitalWrite(_config->motor_right_a, LOW);
        digitalWrite(_config->motor_right_b, LOW);
    }
    else
    {
        // motor esquerda
        digitalWrite(_config->motor_left_a, LOW);
        digitalWrite(_config->motor_left_b, LOW);
    }
}


void EngineL9110::turn(int32_t millis)
{
    // motors on
    if (millis > 0)
    {
        // clockwise
        motorOn(MOTOR_LEFT, false);
        motorOn(MOTOR_RIGHT, true);
    }
    else
    {
        // counterclockwise
        motorOn(MOTOR_RIGHT, false);
        motorOn(MOTOR_LEFT, true);
    }

    delay(abs(millis));

    // motors off
    motorOff(MOTOR_LEFT);
    motorOff(MOTOR_RIGHT);
}


void EngineL9110::turn90Degrees(int8_t times)
{
    if (times != 0)
    {
        turn(_config->turn_millis * times);
    }
}


void EngineL9110::moveStraight(int8_t units)
{
    if (units != 0)
    {
        bool reverse = (units < 0);

        // turn on both motors
        motorOn(MOTOR_RIGHT, reverse);
        motorOn(MOTOR_LEFT, reverse);

        delay(abs(units) * _config->step_millis);

        // turn off both motors
        motorOff(MOTOR_RIGHT);
        motorOff(MOTOR_LEFT);
    }
}


// EOF
