// Vacalourabot.ino

#include "Vacalourabot.h"


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
        delay(500);

        // move by move
        for (int m = 0; m < PROGRAM->getMoveCount(); m++)
        {
            // which move
            switch (PROGRAM->getMove(m))
            {
                case MOVE_RIGHT:
                    ENGINE->turn90Degrees(1);
                    break;
                case MOVE_LEFT:
                    ENGINE->turn90Degrees(-1);
                    break;
                case MOVE_FORWARD:
                    ENGINE->moveStraight(1);
                    break;
                case MOVE_BACKWARD:
                    ENGINE->moveStraight(-1);
                    break;
            }
        }
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

    #if USE_PERSISTENT_MEMORY

    // restore last program
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

    delay(100);
}

// EOF

