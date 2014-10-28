// Escornabot.ino
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

#include "Escornabot.h"

#define PIN_LED 13

#define FLASH_LED_MILLIS 300

void flash_led(uint16_t millis)
{
    digitalWrite(PIN_LED, HIGH);
    delay(millis);
    digitalWrite(PIN_LED, LOW);
}

void go()
{
    flash_led(FLASH_LED_MILLIS);

    // only with movements
    if (PROGRAM->getMoveCount() > 0)
    {
        #if USE_PERSISTENT_MEMORY

        // save the movement program in EEPROM
        PROGRAM->save();

        #endif

        // let user to release the 'go' button before the action
        delay(1000);

        ENGINE->executeProgram(PROGRAM);
    }
}


void storeMove(MOVE move)
{
    if (PROGRAM->getMoveCount() < MOVE_LIMIT)
    {
        PROGRAM->addMove(move);
        INDICATORS->indicateMoveAdded(move);
    }
    else
    {
        // memory is full
        go();
    }
}

void setup()
{
    pinMode(PIN_LED, OUTPUT);

    // init engine
    ENGINE->init();

    // init button set
    BUTTONS->init();

    // status indicators
    #if USE_BUZZER
    INDICATORS->add(&BUZZER);
    #endif

    // restore last program
    #if USE_PERSISTENT_MEMORY
    PROGRAM->load();
    #endif
}



void loop(){

    switch (BUTTONS->scanButtons()) {

        case ButtonSet::BUTTON_UP:
            storeMove(MOVE_FORWARD);
            flash_led(FLASH_LED_MILLIS);
            break;

        case ButtonSet::BUTTON_RIGHT:
            storeMove(MOVE_RIGHT);
            flash_led(FLASH_LED_MILLIS);
            break;

        case ButtonSet::BUTTON_DOWN:
            storeMove(MOVE_BACKWARD);
            flash_led(FLASH_LED_MILLIS);
            break;

        case ButtonSet::BUTTON_LEFT:
            storeMove(MOVE_LEFT);
            flash_led(FLASH_LED_MILLIS);
            break;

        case ButtonSet::BUTTON_GO:
            go();
            flash_led(FLASH_LED_MILLIS);
            break;

        case ButtonSet::BUTTON_RESET:
            PROGRAM->clear();
            flash_led(FLASH_LED_MILLIS);
            break;
    }

    delay(100);
}

// EOF

