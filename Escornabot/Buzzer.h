// Buzzer.h
/*

Copyright (C) 2014-2019 Escornabot - http://escornabot.com

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

// https://www.vex.net/~lawrence/ringtones.html
// https://adamonsoon.github.io/rtttl-play/

#define RTTL_INTEL   ":d=8,o=5,b=320:d,p,d,p,d,p,g,p,g,p,g,p,d,p,d,p,d,p,a,p,a,p,"
#define RTTL_FIDO    ":d=16,o=6,b=800:f,4p,f,4p,f,4p,f,4p,c,4p,c,4p,c,4p,c,"
#define RTTL_MOSAIC  ":d=8,o=6,b=400:c,e,g,e,c,g,e,g,c,g,c,e,c,g,e,g,e,c,"
#define RTTL_ELISA   ":d=8,o=6,b=125:e,d#,e,d#,e,b5,d,c,a,"
#define RTTL_GUP     ":d=16,o=6,b=140:c,p,e,p,g,"
#define RTTL_STARTUP "fanfare:d=16,o=6,b=180:e,8p,e,p,e,p,4g,"
#define RTTL_BTTF    ":d=16,o=5,b=200:4g.,p,4c.,p,2f#.,p,g.,p,a.,p,8g,p,8e,p,8c,p,4f#,p,g.,p,a.,p,8g.,p,8d.,p,8g.,p,8d.6,p,4d.6,p,4c#6,p,b.,p,c#.6,p,2d.6,"
#define RTTL_TEST    ":d=16,o=4,b=200:c,c#,d,d#,e,f,f#,g,g#,a,a#,b,c5,c#5,d5,d#5,e5,f5,f#5,g5,g#5,a5,a#5,b5,c6,c#6,d6,d#6,e6,f6,f#6,g6,g#6,a6,a#6,b6,c7,c#7,d7,d#7,e7,f7,f#7,g7,g#7,a7,a#7,b7,"

#define BUZZER_BEEP_FREQUENCY 4699
#define BUZZER_BEEP_MILLIS 100

#include <stdint.h>
#include "EventListener.h"

/**
 * \brief Generates tones with a buzzer connected to a PWM output.
 * \author @caligari
 */
class Buzzer : public EventListener
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
    void beep() { beep(BUZZER_BEEP_FREQUENCY); }

    /**
     * Beep generator with a tone.
     */
    void beep(uint16_t frequency);

    /**
     * RTTL parser and tone player.
     * @param rttl Ring Tone Transfer Language string.
     */
    void playRttl(const char* rttl);


    //////////////////////////////////////////////////////////////////////
    // Buzzer interface
    //////////////////////////////////////////////////////////////////////

    virtual void buttonReleased(BUTTON btn)
        { _beepDirection(btn, BUZZER_BEEP_MILLIS); }

    virtual void buttonLongReleased(BUTTON btn)
        { _beepDirection(btn, 2 * BUZZER_BEEP_MILLIS); }

    virtual void moveExecuting(MOVE move)
        { _beepDirection(move, BUZZER_BEEP_MILLIS); }

    virtual void gameModeSelected(GAME_MODE mode);

private:

    uint8_t _pin;

    void _beepDirection(uint8_t direction, uint16_t duration);

};

#endif // _BUZZER_H

// EOF
