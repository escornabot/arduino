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
#include "MoveProgram.h"

/**
 * Interface to different Vacaloura engines.
 */
class Engine
{
public:

	/**
	 * Does the hardware initialization.
	 */
	virtual void init() = 0;

	/**
	 * Turns left or right in 90 degrees angles (from Vacaloura's POV).
	 * @param times Amount of right angles to turn. Positive is clockwise,
	 *     negative is counter-clockwise.
	 */
	virtual void turn90Degrees(int8_t times) = 0;

	/**
	 * Moves forward or backward direction (from Vacaloura's POV).
	 * @param units Amount of units to move. Positive is forwards, negative
	 *     is backwards.
	 */
	virtual void moveStraight(int8_t units) = 0;

	/**
	 * Executes the movement program.
	 * @param program The program with the movements.
	 */
	void executeProgram(MoveProgram* program);
};


#endif // _ENGINE_H

// EOF
