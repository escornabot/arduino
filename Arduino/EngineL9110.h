// EngineL9110.h

#ifndef _ENGINE_L9110_H
#define _ENGINE_L9110_H

#include "Engine.h"
#include "Configuration.h"


/**
 * Engine using 2 motors controlled by an H-Bridge L9110 module.
 */
class EngineL9110 : Engine
{
public:

//	EngineL9110();

	// Engine interface

	/**
	 * Does the hardware initialization.
	 */
	void init();

	/**
	 * Turns left or right in 90 degrees angles (from Vacaloura's POV).
	 * @param times Amount of right angles to turn. Positive is clockwise,
	 *     negative is counter-clockwise.
	 */
	void turn90Degrees(int8_t times);

	/**
	 * Moves forward or backward direction (from Vacaloura's POV).
	 * @param units Amount of units to move. Positive is forwards, negative
	 *     is backwards.
	 */
	void moveStraight(int8_t units);

};


#endif // _ENGINE_L9110_H

// EOF
