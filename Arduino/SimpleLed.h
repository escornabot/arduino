// SimpleLed.h

#ifndef _SIMPLE_LED_H
#define _SIMPLE_LED_H

#include <stdint.h>

class SimpleLed
{
public:

	SimpleLed(uint8_t pin);

	void init();

	bool getStatus() { return _status; }

	void setStatus(bool value);

	void toggle();

private:

	uint8_t _pin;

	bool _status;

};

#endif _SIMPLE_LED_H

// EOF
