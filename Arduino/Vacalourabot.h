// Vacalourabot.h

#ifndef _VACALOURABOT_H
#define _VACALOURABOT_H

#include "Configuration.h"
#include "MoveProgram.h"
#include "Engine.h"


// motor engine defined from configuration
#if defined(ENGINE_TYPE_L9110)

    #include "EngineL9110.h"
    #define ENGINE_CLASS EngineL9110

    static const EngineL9110::Config ENGINE_CONFIG = {
        motor_left_a: L9110_MOTOR_LEFT_A,
        motor_left_b: L9110_MOTOR_LEFT_B,
        motor_right_a: L9110_MOTOR_RIGHT_A,
        motor_right_b: L9110_MOTOR_RIGHT_B,
        step_millis: L9110_STEP_MILLIS,
        turn_millis: L9110_TURN_MILLIS,
    };

    static ENGINE_CLASS ENGINE_INSTANCE (&ENGINE_CONFIG);

#else
    // include new header file
    // define ENGINE_CLASS
    // declare ENGINE_INSTANCE
#endif


// EEPROM as persistent memory
#if USE_PERSISTENT_MEMORY
    #include "PersistentMemory.h"
#endif


///// global vars

// engine
static Engine* ENGINE = (Engine*) &ENGINE_INSTANCE;

// program
static MoveProgram PROGRAM_INSTANCE;
static MoveProgram* PROGRAM = &PROGRAM_INSTANCE;


#endif // _VACALOURABOT_H

// EOF
