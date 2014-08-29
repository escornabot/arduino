// Vacalourabot.h

#ifndef _VACALOURABOT_H
#define _VACALOURABOT_H

#include "Configuration.h"
#include "MoveProgram.h"
#include "Engine.h"
#include "ButtonSet.h"


// motor engine defined from configuration
#ifdef ENGINE_TYPE_L9110
    #include "EngineL9110.h"
    static const EngineL9110::Config ENGINE_CONFIG = {
        motor_left_a: L9110_MOTOR_LEFT_A,
        motor_left_b: L9110_MOTOR_LEFT_B,
        motor_right_a: L9110_MOTOR_RIGHT_A,
        motor_right_b: L9110_MOTOR_RIGHT_B,
        step_millis: L9110_STEP_MILLIS,
        turn_millis: L9110_TURN_MILLIS,
    };
    static EngineL9110 ENGINE_INSTANCE (&ENGINE_CONFIG);
#else
    // include new header file
    // declare ENGINE_INSTANCE
#endif


// EEPROM as persistent memory
#if USE_PERSISTENT_MEMORY
    #include "PersistentMemory.h"
#endif


// Digital button set
#ifdef BUTTONS_DIGITAL
    #include "ButtonSetDigital.h"
    static const ButtonSetDigital::Config BS_CONFIG = {
        pin_button_up: BS_DIGITAL_UP,
        pin_button_right: BS_DIGITAL_RIGHT,
        pin_button_down: BS_DIGITAL_DOWN,
        pin_button_left: BS_DIGITAL_LEFT,
        pin_button_go: BS_DIGITAL_GO,
        pin_button_reset: BS_DIGITAL_RESET,
    };
    static ButtonSetDigital BUTTONS_INSTANCE (&BS_CONFIG);
#else
    // include new header file
    // declare BUTTONS_INSTANCE
#endif

///// global vars

// engine
static Engine* ENGINE = (Engine*) &ENGINE_INSTANCE;

// button set
static ButtonSet* BUTTONS = (ButtonSet*) &BUTTONS_INSTANCE;

// program
static MoveProgram PROGRAM_INSTANCE;
static MoveProgram* PROGRAM = &PROGRAM_INSTANCE;


#endif // _VACALOURABOT_H

// EOF
