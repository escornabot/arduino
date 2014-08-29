// ButtonSetDigital.h

#ifndef _BUTTON_SET_DIGITAL_H
#define _BUTTON_SET_DIGITAL_H

#include "ButtonSet.h"

/**
 * Implementation of a button set connected to 6 digital inputs.
 */
class ButtonSetDigital : ButtonSet
{
public:

	typedef struct {
		uint8_t pin_button_up;
		uint8_t pin_button_right;
		uint8_t pin_button_down;
		uint8_t pin_button_left;
		uint8_t pin_button_go;
		uint8_t pin_button_reset;
	} Config;

	ButtonSetDigital(const Config* config);

	/**
	 * Does the hardware initialization.
	 */
	virtual void init();

	/**
	 * Reads the buttons
	 * @return The button being pressed.
	 */
	virtual BUTTON scanButtons();

private:

	const Config* _config;

	bool _btn_state[6];
};


#endif // _BUTTON_SET_DIGITAL_H

// EOF
