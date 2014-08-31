// EngineHBridge.h

#ifndef _ENGINE_HBRIDGE_H
#define _ENGINE_HBRIDGE_H

#include "Engine.h"


/**
 * Engine using 2 motors controlled by an H-Bridge L9110 module.
 */
class EngineHBridge : Engine
{
public:

	typedef struct {
		uint8_t motor_left_a;
		uint8_t motor_left_b;
		uint8_t motor_right_a;
		uint8_t motor_right_b;
		int16_t step_millis;
		int16_t turn_millis;
	} Config;

	/**
	 * Constructor.
	 */
    EngineHBridge(const Config* config);

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

private:

	enum MOTOR : uint8_t
	{
		MOTOR_RIGHT,
		MOTOR_LEFT,
	};

	const Config* _config;

	void motorOn(MOTOR motor, bool reverse);

	void motorOff(MOTOR motor);

	void turn(int32_t millis);

};


#endif // _ENGINE_HBRIDGE_H

// EOF

