// EngineSteppers.h
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

#ifndef _ENGINE_STEPPERS_H
#define _ENGINE_STEPPERS_H

#include "Engine.h"

class EngineSteppers : Engine
{
public:

	typedef struct {
		uint8_t motor_left_in1;
		uint8_t motor_left_in2;
		uint8_t motor_left_in3;
		uint8_t motor_left_in4;
		uint8_t motor_right_in1;
		uint8_t motor_right_in2;
		uint8_t motor_right_in3;
		uint8_t motor_right_in4;
		int16_t steps_per_second;
        int16_t line_steps;
        int16_t turn_steps;

	} Config;

	EngineSteppers(const Config* cfg);

	void init();

	void turn90Degrees(int8_t times);

	void moveStraight(int8_t units);

private:

	const Config* _config;

	void _motorsOn(int16_t steps_left, int16_t steps_right);
    void _motorStepRight(uint8_t pattern);
    void _motorStepLeft(uint8_t pattern);

	int8_t _pattern_index_left;
	int8_t _pattern_index_right;
};


#endif // _ENGINE_STEPPERS_H

// EOF
