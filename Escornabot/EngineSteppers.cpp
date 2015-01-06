// EngineSteppers.cpp
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

#include "EngineSteppers.h"
#include <Arduino.h>

const static uint8_t step_pattern[] = {
    B00001, B00011, B00010, B00110, B00100, B01100, B01000, B01001
};

EngineSteppers::EngineSteppers(const Config* cfg)
{
    _config = cfg;
    _pattern_index_left = 0;
    _pattern_index_right = 0;
}

//////////////////////////////////////////////////////////////////////
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
    _motorsOn(8, 8);
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

void EngineSteppers::turn90Degrees(int8_t times)
{
    uint8_t turns;
    uint16_t steps;

    if (times < 0)
    {
        turns = -times;
        steps = _config->turn_steps;
    }
    else
    {
        turns = times;
        steps = -_config->turn_steps;
    }

    while (turns-- > 0)
    {
        _motorsOn(steps, steps);
    }
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

void EngineSteppers::moveStraight(int8_t units)
{
    uint8_t moves;
    uint16_t steps;

    if (units < 0)
    {
        moves = -units;
        steps = -_config->line_steps;
    }
    else
    {
        moves = units;
        steps = _config->line_steps;
    }

    while (moves-- > 0)
    {
        _motorsOn(-steps, steps);
    }
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

void EngineSteppers::_motorsOn(int16_t steps_left, int16_t steps_right)
{
    int8_t delta_left = (steps_left > 0 ? 1 : -1);
    int8_t delta_right = (steps_right > 0 ? 1 : -1);

    bool end = false;
    while (!end)
    {
        end = true;

        if (steps_left != 0)
        {
            end = false;
            _motorStepLeft(step_pattern[_pattern_index_left]);
            _pattern_index_left += delta_left + 8;
            _pattern_index_left %= 8;
            steps_left -= delta_left;
        }

        if (steps_right != 0)
        {
            end = false;
            _motorStepRight(step_pattern[_pattern_index_right]);
            _pattern_index_right += delta_right + 8;
            _pattern_index_right %= 8;
            steps_right -= delta_right;
        }

        delayMicroseconds(1000000 / _config->steps_per_second);
    }

    _motorStepLeft(0);
    _motorStepRight(0);
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

void EngineSteppers::_motorStepRight(uint8_t pattern)
{
    digitalWrite(_config->motor_right_in1, bitRead(pattern, 0));
    digitalWrite(_config->motor_right_in2, bitRead(pattern, 1));
    digitalWrite(_config->motor_right_in3, bitRead(pattern, 2));
    digitalWrite(_config->motor_right_in4, bitRead(pattern, 3));
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

void EngineSteppers::_motorStepLeft(uint8_t pattern)
{
    digitalWrite(_config->motor_left_in1, bitRead(pattern, 0));
    digitalWrite(_config->motor_left_in2, bitRead(pattern, 1));
    digitalWrite(_config->motor_left_in3, bitRead(pattern, 2));
    digitalWrite(_config->motor_left_in4, bitRead(pattern, 3));
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

// EOF
