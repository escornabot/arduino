// Buzzer.cpp
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

#include "Buzzer.h"
#include "EventManager.h"
#include <Arduino.h>
#include "Configuration.h"

//////////////////////////////////////////////////////////////////////

// fast index between tones and directions
const static uint16_t BTN_TONES[] = {
    TONE_FREQ_UP,     // 1
    TONE_FREQ_RIGHT,  // 2
    TONE_FREQ_DOWN,   // 3
    TONE_FREQ_LEFT    // 4
};

//////////////////////////////////////////////////////////////////////

extern EventManager* EVENTS;

//////////////////////////////////////////////////////////////////////

Buzzer::Buzzer(uint8_t pin)
{
    this->_pin = pin;
}

//////////////////////////////////////////////////////////////////////

void Buzzer::init()
{
    pinMode(_pin, OUTPUT);
    EVENTS->add(this);
}


//////////////////////////////////////////////////////////////////////
// utility functions
//////////////////////////////////////////////////////////////////////

void Buzzer::beep(uint16_t frequency)
{
    tone(_pin, frequency, BUZZER_BEEP_MILLIS);
}

//////////////////////////////////////////////////////////////////////

static const uint16_t FREQUENCIES[] =
{
    440, 466, 494, 523, 554, 587, 622, 659, 698, 740, 784, 831,
    880, 932, 987, 1046, 1108, 1174, 1244,1318, 1396, 1479, 1567, 1661,
    1760, 1864, 1975, 2093, 2217, 2349, 2489, 2637, 2793, 2959, 3135, 3322,
    3520, 3729, 3951, 4186, 4434, 4698, 4978, 5274, 5587, 5919, 6271, 6644,
    7040, 7458, 7902, 8372, 8869, 9397, 9956, 10548, 11175, 11839, 12543, 13289,
    14080, 14917, 15804, 16744, 17739, 18794, 19912, 21096, 22350, 23679, 25087,
};

//////////////////////////////////////////////////////////////////////

void Buzzer::playRttl(const char* rttl)
{
    // song name
    while (*rttl && *rttl != ':') rttl++;
    rttl++;

    // default values
    uint8_t default_duration= 16, default_octave = 5;
    uint16_t bps = 320;
    while (*rttl && *rttl != ':')
    {
        switch (*rttl)
        {
        case 'd': // note duration
            rttl += 2;
            default_duration = atoi(rttl);
            while (*rttl >= '0' && *rttl <= '9') rttl++;
            break;

        case 'o': // octave
            rttl += 2;
            default_octave = atoi(rttl);
            while (*rttl >= '0' && *rttl <= '9') rttl++;
            break;

        case 'b': // beats per second
            rttl += 2;
            bps = atoi(rttl);
            while (*rttl >= '0' && *rttl <= '9') rttl++;
            break;

        default:
            rttl++;
        }
    }
    rttl++;

    // play notes
    uint16_t duration = default_duration;
    int8_t note = -1;
    uint8_t octave = default_octave;
    while (*rttl)
    {
        if (*rttl >= 0 && *rttl <= 9)
        {
            // eat numbers
            if (note < 0) duration = atoi(rttl) * bps / 60;
                else octave = atoi(rttl);
            while (*rttl >= '0' && *rttl <= '9') rttl++;
        }
        else
        {
            // eat note
            switch (*rttl)
            {
                // tone
                case 'p': note = 0; break;
                case 'a': note = 1; break;
                case 'b': note = 3; break;
                case 'c': note = 4; break;
                case 'd': note = 6; break;
                case 'e': note = 8; break;
                case 'f': note = 9; break;
                case 'g': note = 10; break;
                case '#': note++; break;

                case ',': case '\0':

                    if (note != -1 && octave >= 4 && octave <= 8) {
                        if (note > 0) tone(_pin,
                            FREQUENCIES[((octave - 4) * 10) + note - 1]);
                        delay(1000 / duration);
                        noTone(_pin);
                    }

                    duration = default_duration;
                    note = -1;
                    octave = default_octave;
                    break;
            }
            rttl++;
        }
    }
}

//////////////////////////////////////////////////////////////////////

void Buzzer::_beepDirection(uint8_t direction, uint16_t duration)
{
    uint16_t frequency = (direction >= 1 && direction <= 4 ?
            BTN_TONES[direction - 1] : BUZZER_BEEP_FREQUENCY);

    tone(_pin, frequency, duration);
}

//////////////////////////////////////////////////////////////////////

void Buzzer::gameModeSelected(GAME_MODE mode)
{
    mode++;
    while (mode-- > 0)
    {
        tone(_pin, BUZZER_BEEP_FREQUENCY, 100);
        delay(200);
    }
}

//////////////////////////////////////////////////////////////////////

// EOF
