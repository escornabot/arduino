// ButtonSetAnalog.h

#ifndef _BUTTON_SET_ANALOG_H
#define _BUTTON_SET_ANALOG_H

#include "ButtonSet.h"

/**
 * Implementation of a button set connected to 1 analog input.
 */
class ButtonSetAnalog : ButtonSet
{
public:

	typedef struct {
		uint8_t pin_button_set;
		uint16_t value_button_up;
		uint16_t value_button_right;
		uint16_t value_button_down;
		uint16_t value_button_left;
		uint16_t value_button_go;
		uint16_t value_button_reset;
	} Config;

	ButtonSetAnalog(const Config* config);

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

	int16_t _last_value;

};


#endif // _BUTTON_SET_ANALOG_H

// EOF
