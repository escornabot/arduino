// Engine.h
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

#ifndef _ENGINE_H
#define _ENGINE_H

#include <stdint.h>
#include "MoveList.h"


/**
 * \brief Interface to different Escornabot engines.
 * \author @caligari
 */
class Engine
{
public:

	/**
	 * Constructor.
	 */
	Engine();

	/**
	 * Does the hardware initialization.
	 */
	virtual void init() = 0;

	/**
	 * Turns left or right in 90 degrees angles (from Escornabot's POV).
	 * @param times Amount of right angles to turn. Positive is clockwise,
	 *     negative is counter-clockwise.
	 */
	virtual void turn90Degrees(int8_t times) = 0;

	/**
	 * Turns left or right an angle specified in degrees (from Escornabot's POV).
	 * @param degrees Amount of degrees to turn. Positive is clockwise,
	 *     negative is counter-clockwise.
	 */
	virtual void turn(int16_t degrees) = 0;

	/**
	 * Moves forward or backward direction (from Escornabot's POV).
	 * @param units Amount of units to move. Positive is forwards, negative
	 *     is backwards.
	 */
	virtual void moveStraight(int8_t units) = 0;

	/**
	 * Executes the movement program.
	 * @param program Movements to execute.
	 * @param pause Milliseconds waiting between movements.
	 * @param pov Point of view of movements (POV_ESCORNABOT or POV_CHILD).
	 */
	void execute(MoveList* program, uint16_t pause, POV pov);

	bool isExecuting() { return _is_executing; }

	void cancelExecution() { _is_cancelling = true; }

protected:

	bool _is_executing;

	bool _is_cancelling;

	MoveList* _program;

	uint8_t _current_move;

};


#endif // _ENGINE_H

// EOF
