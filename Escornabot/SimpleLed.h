// SimpleLed.h

#ifndef _SIMPLE_LED_H
#define _SIMPLE_LED_H

#include <stdint.h>
#include "EventListener.h"


/**
 * \brief Listener of events and turning on/off a digital output.
 * \author @caligari
 */
class SimpleLed : public EventListener
{
public:

	SimpleLed(uint8_t pin);

	void init();

	bool getStatus() { return _status; }

	void setStatus(bool value);

	void toggle();

	void flashOne(uint16_t millis);


	//////////////////////////////////////////////////////////////////////
	// StatusIndicator interface
	//////////////////////////////////////////////////////////////////////

	// turn on between movement pauses
    virtual void moveExecuted(MOVE move) { setStatus(true); }
	virtual void moveExecuting(MOVE move) { setStatus(false); }
    virtual void programFinished() { setStatus(false); }

	// turn on when button is pressed (200 milliseconds)
    virtual void moveAdded(MOVE move) { flashOne(200); }
    virtual void programReset() { flashOne(200); }
    virtual void programStarted(uint8_t total_moves) { flashOne(200); }




private:

	uint8_t _pin;

	bool _status;

};

#endif // _SIMPLE_LED_H

// EOF
