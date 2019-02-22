// EngineSteppers.cpp
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

#include "EngineSteppers.h"
#include "EventManager.h"
#include <Arduino.h>

//////////////////////////////////////////////////////////////////////

const static uint8_t step_pattern[] = {
    B00001, B00011, B00010, B00110, B00100, B01100, B01000, B01001
};

//////////////////////////////////////////////////////////////////////

extern EventManager* EVENTS;

//////////////////////////////////////////////////////////////////////

EngineSteppers::EngineSteppers(const Config* cfg)
{
    _config = cfg;

    _movement_steps_r = 0;
    _movement_steps_l = 0;

    _pattern_index_left = 0;
    _pattern_index_right = 0;
}

//////////////////////////////////////////////////////////////////////

void EngineSteppers::init()
{
    pinMode(_config->motor_left_in1, OUTPUT);
    pinMode(_config->motor_left_in2, OUTPUT);
    pinMode(_config->motor_left_in3, OUTPUT);
    pinMode(_config->motor_left_in4, OUTPUT);
    pinMode(_config->motor_right_in1, OUTPUT);
    pinMode(_config->motor_right_in2, OUTPUT);
    pinMode(_config->motor_right_in3, OUTPUT);
    pinMode(_config->motor_right_in4, OUTPUT);

    // set coils in row
    _movement_steps_r = 8;
    _movement_steps_l = 8;

    EVENTS->add(this);
}

//////////////////////////////////////////////////////////////////////

void EngineSteppers::turn(int16_t degrees)
{
    int32_t steps = -_config->turn_steps;
    steps *= degrees;
    steps /= 90;

    _movement_steps_r = steps;
    _movement_steps_l = steps;
}

//////////////////////////////////////////////////////////////////////

void EngineSteppers::moveStraight(float advance_units)
{
    _movement_steps_r = _config->line_steps * advance_units;
    _movement_steps_l = -_movement_steps_r;
}

//////////////////////////////////////////////////////////////////////

void EngineSteppers::_motorStepRight(uint8_t pattern)
{
    digitalWrite(_config->motor_right_in1, bitRead(pattern, 0));
    digitalWrite(_config->motor_right_in2, bitRead(pattern, 1));
    digitalWrite(_config->motor_right_in3, bitRead(pattern, 2));
    digitalWrite(_config->motor_right_in4, bitRead(pattern, 3));
}

//////////////////////////////////////////////////////////////////////

void EngineSteppers::_motorStepLeft(uint8_t pattern)
{
    digitalWrite(_config->motor_left_in1, bitRead(pattern, 0));
    digitalWrite(_config->motor_left_in2, bitRead(pattern, 1));
    digitalWrite(_config->motor_left_in3, bitRead(pattern, 2));
    digitalWrite(_config->motor_left_in4, bitRead(pattern, 3));
}

//////////////////////////////////////////////////////////////////////

void EngineSteppers::tick(uint32_t micros)
{
    if (!isExecuting()) return;

    if (_movement_steps_l == 0 && _movement_steps_r == 0)
    {
        // already executing a pause movement
        if (_inPauseMove()) return;

        // deactivate Darlingtons
        _motorStepLeft(0);
        _motorStepRight(0);

        EVENTS->indicateMoveExecuted(_getCurrentMove());

        // prepare next movement
        _program_index++;
        _prepareMove();
        return;
    }

    if (_movement_steps_l != 0)
    {
        // left motor step
        int8_t delta = (_movement_steps_l > 0 ? 1 : -1);
        _motorStepLeft(step_pattern[_pattern_index_left]);
        _pattern_index_left += delta + 8;
        _pattern_index_left %= 8;
        _movement_steps_l -= delta;
    }

    if (_movement_steps_r != 0)
    {
        // right motor step
        int8_t delta = (_movement_steps_r > 0 ? 1 : -1);
        _motorStepRight(step_pattern[_pattern_index_right]);
        _pattern_index_right += delta + 8;
        _pattern_index_right %= 8;
        _movement_steps_r -= delta;
    }

    if (_is_cancelling)
    {
        _movement_steps_r = 0;
        _movement_steps_l = 0;
    }
    else
    {
        delayMicroseconds(1000000 / _config->steps_per_second);
    }
}

//////////////////////////////////////////////////////////////////////

// EOF
