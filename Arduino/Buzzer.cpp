// Buzzer.cpp
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

#include "Buzzer.h"
#include <Arduino.h>

#define BUZZER_BEEP_MILLIS 100

// note frequencies
#define BUZZER_B2     123
#define BUZZER_C3     131
#define BUZZER_CS3    139
#define BUZZER_D3     147
#define BUZZER_DS3    156
#define BUZZER_E3     165
#define BUZZER_F3     175
#define BUZZER_FS3    185
#define BUZZER_G3     196
#define BUZZER_GS3    208
#define BUZZER_A3     220
#define BUZZER_AS3    233
#define BUZZER_B3     247
#define BUZZER_C4     262
#define BUZZER_CS4    277
#define BUZZER_D4     294
#define BUZZER_DS4    311
#define BUZZER_E4     330
#define BUZZER_F4     349
#define BUZZER_FS4    370
#define BUZZER_G4     392
#define BUZZER_GS4    415
#define BUZZER_A4     440
#define BUZZER_AS4    466
#define BUZZER_B4     494
#define BUZZER_C5     523
#define BUZZER_CS5    554
#define BUZZER_D5     587
#define BUZZER_DS5    622
#define BUZZER_E5     659
#define BUZZER_F5     698
#define BUZZER_FS5    740
#define BUZZER_G5     784
#define BUZZER_GS5    831
#define BUZZER_A5     880
#define BUZZER_AS5    932
#define BUZZER_B5     988
#define BUZZER_C6     1047
#define BUZZER_CS6    1109
#define BUZZER_D6     1175
#define BUZZER_DS6    1245
#define BUZZER_E6     1319
#define BUZZER_F6     1397
#define BUZZER_FS6    1480
#define BUZZER_G6     1568
#define BUZZER_GS6    1661
#define BUZZER_A6     1760
#define BUZZER_AS6    1865
#define BUZZER_B6     1976
#define BUZZER_C7     2093
#define BUZZER_CS7    2217
#define BUZZER_D7     2349
#define BUZZER_DS7    2489
#define BUZZER_E7     2637
#define BUZZER_F7     2794
#define BUZZER_FS7    2960
#define BUZZER_G7     3136
#define BUZZER_GS7    3322
#define BUZZER_A7     3520
#define BUZZER_AS7    3729
#define BUZZER_B7     3951
#define BUZZER_C8     4186
#define BUZZER_CS8    4435
#define BUZZER_D8     4699
#define BUZZER_DS8    4978

Buzzer::Buzzer(uint8_t pin)
{
    this->_pin = pin;
}

void Buzzer::beep()
{
    tone(_pin, BUZZER_D8, BUZZER_BEEP_MILLIS);
}

void Buzzer::init()
{
    pinMode(_pin, OUTPUT);
}

void Buzzer::moveExecuting(MOVE move)
{
    beep();
}

void Buzzer::moveExecuted(MOVE move)
{
    beep();
}

void Buzzer::moveAdded(MOVE move)
{
    beep();
}

void Buzzer::programStarted(uint8_t total_moves)
{
    beep();
}

void Buzzer::programFinished()
{
    beep();
}

void Buzzer::programReset()
{
    beep();
}

void Buzzer::programAborted(uint8_t executed, uint8_t total)
{
    beep();
}
