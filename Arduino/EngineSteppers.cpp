// EngineSteppers.cpp

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
	uint8_t pattern;

	bool end = false;
	while (!end)
	{
		end = true;

		if (steps_left != 0)
		{
			end = false;
			pattern = step_pattern[_pattern_index_left];
			digitalWrite(_config->motor_left_in1, bitRead(pattern, 0));
			digitalWrite(_config->motor_left_in2, bitRead(pattern, 1));
			digitalWrite(_config->motor_left_in3, bitRead(pattern, 2));
			digitalWrite(_config->motor_left_in4, bitRead(pattern, 3));
			_pattern_index_left += delta_left + 8;
			_pattern_index_left %= 8;
			steps_left -= delta_left;
		}

		if (steps_right != 0)
		{
			end = false;
			pattern = step_pattern[_pattern_index_right];
			digitalWrite(_config->motor_right_in1, bitRead(pattern, 0));
			digitalWrite(_config->motor_right_in2, bitRead(pattern, 1));
			digitalWrite(_config->motor_right_in3, bitRead(pattern, 2));
			digitalWrite(_config->motor_right_in4, bitRead(pattern, 3));
			_pattern_index_right += delta_right + 8;
			_pattern_index_right %= 8;
			steps_right -= delta_right;
		}

		delayMicroseconds(1000000 / _config->steps_per_second);
	}

}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

// EOF
