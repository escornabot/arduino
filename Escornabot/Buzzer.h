// Buzzer.h
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

#ifndef _BUZZER_H
#define _BUZZER_H

#include <stdint.h>
#include "StatusIndicator.h"

class Buzzer : public StatusIndicator
{
public:

	/**
	 * Constructor.
	 * @param pin Pin where the buzzer is connected (PWM output)
	 */
	Buzzer(uint8_t pin);

	/**
	 * Does the hardware initialization.
	 */
	void init();

    /**
     * Simple beep generator.
     */
	void beep();

    /**
     * RTTL parser and tone player.
     * @param rttl Ring Tone Transfer Language string.
     */
    void playRttl(const char* rttl);

protected:

	//////////////////////////////////////////////////////////////////////
	// StatusIndicator implementation
	//////////////////////////////////////////////////////////////////////

    /**
     * Handles when a movement from the program was executed.
     * @param move The movement.
     */
    virtual void moveExecuting(MOVE move);

    /**
     * Handles when a movement from the program was executed.
     * @param move The movement.
     */
    virtual void moveExecuted(MOVE move);

    /**
     * Handles when a new movement was added to the program.
     * @param move The movement.
     */
    virtual void moveAdded(MOVE move);

    /**
     * Handles when the program has stated.
     * @param total_moves Total moves in the program.
     */
    virtual void programStarted(uint8_t total_moves);

    /**
     * Handles when the program has finished.
     */
    virtual void programFinished();

    /**
     * Handles when the program has reset.
     */
    virtual void programReset();

    /**
     * Handles when the program was aborted.
     * @param executed Number of executed moves after aborted.
     * @param total Total moves in the program.
     */
    virtual void programAborted(uint8_t executed, uint8_t total);

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

private:

	uint8_t _pin;

};

#endif // _BUZZER_H
