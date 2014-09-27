// Vacalourabot.ino

#include "Vacalourabot.h"

#define PIN_LED 13
#define FLASH_LED_MILLIS 500

void flash_led(uint16_t millis)
{
    digitalWrite(PIN_LED, HIGH);
    delay(millis);
    digitalWrite(PIN_LED, LOW);
}

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
        delay(1000);
        flash_led(FLASH_LED_MILLIS);

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
    pinMode(PIN_LED, OUTPUT);

    // init engine
    ENGINE->init();

    // init button set
    BUTTONS->init();

    #if USE_PERSISTENT_MEMORY

    // restore last program
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

