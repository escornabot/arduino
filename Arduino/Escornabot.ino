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

void go()
{
    // only with movements
    if (PROGRAM->getMoveCount() > 0)
    {
        #if USE_PERSISTENT_MEMORY

        // save the movement program in EEPROM
        PROGRAM->save();

        #endif

        // let user to release the 'go' button before the action
        delay(DELAY_BEFORE_GO);

        ENGINE->executeProgram(PROGRAM);
    }
}


void storeMove(MOVE move)
{
    if (PROGRAM->getMoveCount() < MOVE_LIMIT)
    {
        PROGRAM->addMove(move);
    }
    else
    {
        // memory is full
        go();
    }
}

void setup()
{
    // init engine
    ENGINE->init();

    // init button set
    BUTTONS->init();

    // init buzzer
    #if USE_BUZZER
    BUZZER.init();
    INDICATORS->add(&BUZZER);
    #endif

    #if USE_SIMPLE_LED
    SIMPLE_LED.init();
    INDICATORS->add(&SIMPLE_LED);
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
            break;

        case ButtonSet::BUTTON_RIGHT:
            storeMove(MOVE_RIGHT);
            break;

        case ButtonSet::BUTTON_DOWN:
            storeMove(MOVE_BACKWARD);
            break;

        case ButtonSet::BUTTON_LEFT:
            storeMove(MOVE_LEFT);
            break;

        case ButtonSet::BUTTON_GO:
            go();
            break;

        case ButtonSet::BUTTON_RESET:
            PROGRAM->clear();
            break;
    }

    delay(50);
}

// EOF

