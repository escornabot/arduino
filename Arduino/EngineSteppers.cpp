// EngineSteppers.cpp

#include "EngineSteppers.h"

#define HALFSTEP 8

EngineSteppers::EngineSteppers(const Config* cfg) :
	_motor_left(HALFSTEP,
		cfg->motor_left_in1, cfg->motor_left_in3,
		cfg->motor_left_in2, cfg->motor_left_in4),
	_motor_right(HALFSTEP,
		cfg->motor_right_in1, cfg->motor_right_in3,
		cfg->motor_right_in2, cfg->motor_right_in4)
{
	_config = cfg;
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

void EngineSteppers::init()
{
	_motor_left.setMaxSpeed(_config->steps_per_second);
  	_motor_right.setMaxSpeed(_config->steps_per_second);
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
		steps = -_config->turn_steps;
	}
	else
	{
		turns = times;
		steps = _config->turn_steps;
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
	_motor_left.move(steps_left);
	_motor_left.setSpeed(_config->steps_per_second);

	_motor_right.move(steps_right);
	_motor_right.setSpeed(_config->steps_per_second);

	while (!(_motor_left.distanceToGo() == 0
			&& _motor_right.distanceToGo() == 0))
	{
		_motor_left.runSpeedToPosition();
		_motor_right.runSpeedToPosition();
	}
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

// EOF
