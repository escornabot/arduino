// Vacalourabot.h

#ifndef _VACALOURABOT_H
#define _VACALOURABOT_H

#include "Configuration.h"
#include "MoveProgram.h"
#include "Engine.h"
#include "ButtonSet.h"


// motor engine defined from configuration
#ifdef ENGINE_TYPE_HBRIDGE
    #include "EngineHBridge.h"
    static const EngineHBridge::Config ENGINE_CONFIG = {
        motor_left_a: HBRIDGE_MOTOR_LEFT_A,
        motor_left_b: HBRIDGE_MOTOR_LEFT_B,
        motor_right_a: HBRIDGE_MOTOR_RIGHT_A,
        motor_right_b: HBRIDGE_MOTOR_RIGHT_B,
        step_millis: HBRIDGE_STEP_MILLIS,
        turn_millis: HBRIDGE_TURN_MILLIS,
    };
    static EngineHBridge ENGINE_INSTANCE (&ENGINE_CONFIG);
#else
    // include new header file
    // declare ENGINE_INSTANCE
#endif


// EEPROM as persistent memory
#if USE_PERSISTENT_MEMORY
    #include "PersistentMemory.h"
#endif


// Digital button set
#if defined(BUTTONS_DIGITAL)

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

#elif defined(BUTTONS_ANALOG)

    #include "ButtonSetAnalog.h"
    static const ButtonSetAnalog::Config BS_CONFIG = {
        pin_button_set: BS_ANALOG_PIN,
        value_button_up: BS_ANALOG_VALUE_UP,
        value_button_right: BS_ANALOG_VALUE_RIGHT,
        value_button_down: BS_ANALOG_VALUE_DOWN,
        value_button_left: BS_ANALOG_VALUE_LEFT,
        value_button_go: BS_ANALOG_VALUE_GO,
        value_button_reset: BS_ANALOG_VALUE_RESET,
    };
    static ButtonSetAnalog BUTTONS_INSTANCE (&BS_CONFIG);

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
