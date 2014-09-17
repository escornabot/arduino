// ButtonSet.h

#ifndef _BUTTON_SET_H
#define _BUTTON_SET_H

#include <stdint.h>

/**
 * Interface to different Vacaloura engines.
 */
class ButtonSet
{
public:

	enum
	{
		BUTTON_NONE,
		BUTTON_UP,
		BUTTON_RIGHT,
		BUTTON_DOWN,
		BUTTON_LEFT,
		BUTTON_GO,
		BUTTON_RESET,
	};
        typedef uint8_t BUTTON;

	/**
	 * Does the hardware initialization.
	 */
	virtual void init() = 0;

	/**
	 * Scans the button input to test if anyone is pressed.
	 * @return The button being pressed.
	 */
	virtual BUTTON scanButtons() = 0;

};


#endif // _BUTTON_SET_H

// EOF
