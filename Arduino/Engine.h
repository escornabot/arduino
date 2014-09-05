// Engine.h

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
