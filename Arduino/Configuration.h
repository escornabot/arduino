// Configuration.h

#ifndef _CONFIGURATION_H
#define _CONFIGURATION_H

//////////////////////////////////////////////////////////////////////
///// general configuration
//////////////////////////////////////////////////////////////////////

// engine to use
#define ENGINE_TYPE_STEPPERS
//#define ENGINE_TYPE_HBRIDGE

// button set to use
//#define BUTTONS_DIGITAL
#define BUTTONS_ANALOG

// store configuration and program within internal EEPROM
#define USE_PERSISTENT_MEMORY true

// memory capacity for program movements
#define MOVE_LIMIT 100

// point of view set when Vacalourabot is started
#define POV_INITIAL	POV_VACALOURA

//////////////////////////////////////////////////////////////////////
///// HBRIDGE engine setup
//////////////////////////////////////////////////////////////////////

#ifdef ENGINE_TYPE_HBRIDGE

// HBRIDGE pin setup (outputs)
#define HBRIDGE_MOTOR_LEFT_A 6
#define HBRIDGE_MOTOR_LEFT_B 7
#define HBRIDGE_MOTOR_RIGHT_A 8
#define HBRIDGE_MOTOR_RIGHT_B 9

// HBRIDGE pin setup (outputs PWM, usually 3, 5, 6, 9, 10, and 11)
#define HBRIDGE_MOTOR_LEFT_EN 10
#define HBRIDGE_MOTOR_RIGHT_EN 11

// step unit long in milliseconds
#define HBRIDGE_STEP_MILLIS 500

// 90 degrees turn long in milliseconds
#define HBRIDGE_TURN_MILLIS 350

#endif // ENGINE_TYPE_HBRIDGE

//////////////////////////////////////////////////////////////////////
///// Steppers engine setup
//////////////////////////////////////////////////////////////////////

#ifdef ENGINE_TYPE_STEPPERS

// stepper pin setup (digital outputs)
#define STEPPERS_MOTOR_LEFT_IN1	2
#define STEPPERS_MOTOR_LEFT_IN2	3
#define STEPPERS_MOTOR_LEFT_IN3	4
#define STEPPERS_MOTOR_LEFT_IN4	5
#define STEPPERS_MOTOR_RIGHT_IN1 6
#define STEPPERS_MOTOR_RIGHT_IN2 7
#define STEPPERS_MOTOR_RIGHT_IN3 8
#define STEPPERS_MOTOR_RIGHT_IN4 9

// step calibration
#define STEPPERS_STEPS_PER_SECOND 1000
#define STEPPERS_LINE_STEPS 2000
#define STEPPERS_TURN_STEPS 1512

#endif

//////////////////////////////////////////////////////////////////////
///// Button set digital
//////////////////////////////////////////////////////////////////////

#ifdef BUTTONS_DIGITAL

// Button set pin setup (digital or analog inputs)
#define BS_DIGITAL_UP A0
#define BS_DIGITAL_RIGHT A1
#define BS_DIGITAL_DOWN A2
#define BS_DIGITAL_LEFT A3
#define BS_DIGITAL_GO A4
#define BS_DIGITAL_RESET A5

#endif // BUTTONS_DIGITAL

//////////////////////////////////////////////////////////////////////
///// Button set analog
//////////////////////////////////////////////////////////////////////

#ifdef BUTTONS_ANALOG

// Button set pin setup (analog input)
#define BS_ANALOG_PIN A0

// input values for each key pressed
#define BS_ANALOG_VALUE_UP 471
#define BS_ANALOG_VALUE_RIGHT 299
#define BS_ANALOG_VALUE_DOWN 211
#define BS_ANALOG_VALUE_LEFT 118
#define BS_ANALOG_VALUE_GO 158
#define BS_ANALOG_VALUE_RESET 82

#endif // BUTTONS_ANALOG

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

#ifdef BUTTONS_BLUETOOTH

// Arduino serial port
#define BS_BLUETOOTH_SERIAL	Serial
//#define BS_BLUETOOTH_SERIAL	Serial1
//#define BS_BLUETOOTH_SERIAL	Serial2
//#define BS_BLUETOOTH_SERIAL	Serial3

#endif // BUTTONS_BLUETOOTH

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

#endif // _CONFIGURATION_H

// EOF
