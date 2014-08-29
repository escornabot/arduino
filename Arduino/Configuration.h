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
#define ENGINE_TYPE_L9110

// used button set
//#define BUTTONS_DIGITAL
#define BUTTONS_ANALOG

// store configuration and program within internal EEPROM
#define USE_PERSISTENT_MEMORY true

//////////////////////////////////////////////////////////////////////
///// L9110 engine setup
//////////////////////////////////////////////////////////////////////

#ifdef ENGINE_TYPE_L9110

// L9110 pin setup (digital outputs)
#define L9110_MOTOR_LEFT_A 10
#define L9110_MOTOR_LEFT_B 11
#define L9110_MOTOR_RIGHT_A 12
#define L9110_MOTOR_RIGHT_B 13

// step unit long in milliseconds
#define L9110_STEP_MILLIS 1000

// 90 degrees turn long in milliseconds
#define L9110_TURN_MILLIS 500

#endif // ENGINE_TYPE_L9110

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

#define BS_ANALOG_PIN A0
#define BS_ANALOG_VALUE_UP 471
#define BS_ANALOG_VALUE_RIGHT 299
#define BS_ANALOG_VALUE_DOWN 211
#define BS_ANALOG_VALUE_LEFT 118
#define BS_ANALOG_VALUE_GO 158
#define BS_ANALOG_VALUE_RESET 76

#endif // BUTTONS_ANALOG

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

#endif // _CONFIGURATION_H

// EOF
