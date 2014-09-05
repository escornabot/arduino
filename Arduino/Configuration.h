// Configuration.h

#ifndef _CONFIGURATION_H
#define _CONFIGURATION_H

//////////////////////////////////////////////////////////////////////
///// general configuration
//////////////////////////////////////////////////////////////////////

// memory capacity for program movements
#define MOVE_LIMIT 100

// point of view set when Vacalourabot is started
#define POV_INITIAL	POV_VACALOURA

// used engine
#define ENGINE_TYPE_HBRIDGE

// used button set
//#define BUTTONS_DIGITAL
#define BUTTONS_ANALOG

// store configuration and program within internal EEPROM
#define USE_PERSISTENT_MEMORY true

//////////////////////////////////////////////////////////////////////
///// HBRIDGE engine setup
//////////////////////////////////////////////////////////////////////

#ifdef ENGINE_TYPE_HBRIDGE

// HBRIDGE pin setup (digital outputs)
#define HBRIDGE_MOTOR_LEFT_A 7
#define HBRIDGE_MOTOR_LEFT_B 8
#define HBRIDGE_MOTOR_LEFT_EN 9
#define HBRIDGE_MOTOR_RIGHT_A 10
#define HBRIDGE_MOTOR_RIGHT_B 11
#define HBRIDGE_MOTOR_RIGHT_EN 12

// step unit long in milliseconds
#define HBRIDGE_STEP_MILLIS 500

// 90 degrees turn long in milliseconds
#define HBRIDGE_TURN_MILLIS 350

#endif // ENGINE_TYPE_HBRIDGE

//////////////////////////////////////////////////////////////////////
///// Button set digital
//////////////////////////////////////////////////////////////////////

#ifdef BUTTONS_DIGITAL

// Button set pin setup (digital inputs)
#define BS_DIGITAL_UP 6
#define BS_DIGITAL_RIGHT 5
#define BS_DIGITAL_DOWN 7
#define BS_DIGITAL_LEFT 4
#define BS_DIGITAL_GO 8
#define BS_DIGITAL_RESET 9

#endif // BUTTONS_DIGITAL

//////////////////////////////////////////////////////////////////////
///// Button set analog
//////////////////////////////////////////////////////////////////////

#ifdef BUTTONS_ANALOG

#define BS_ANALOG_PIN A3
#define BS_ANALOG_VALUE_UP 471
#define BS_ANALOG_VALUE_RIGHT 299
#define BS_ANALOG_VALUE_DOWN 211
#define BS_ANALOG_VALUE_LEFT 118
#define BS_ANALOG_VALUE_GO 158
#define BS_ANALOG_VALUE_RESET 77

#endif // BUTTONS_ANALOG

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

#endif // _CONFIGURATION_H

// EOF
