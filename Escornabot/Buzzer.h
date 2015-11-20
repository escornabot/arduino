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

#define RTTL_INTEL ":d=16,o=5,b=320:d,p,d,p,d,p,g,p,g,p,g,p,d,p,d,p,d,p,a,p,a,p,"
#define RTTL_FIDO ":d=16,o=6,b=800:f,4p,f,4p,f,4p,f,4p,c,4p,c,4p,c,4p,c"
#define RTTL_MOSAIC ":d=8,o=6,b=400:c,e,g,e,c,g,e,g,c,g,c,e,c,g,e,g,e,c"
#define RTTL_ELISA ":d=4,o=7,b=125:e,d#,e,d#,e,b,d,c,a"


#include <stdint.h>

/**
 * \brief Generates tones with a buzzer connected to a PWM output.
 * \author @caligari
 */
class Buzzer
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

private:

	uint8_t _pin;

};

#endif // _BUZZER_H

// EOF
