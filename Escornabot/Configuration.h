// Configuration.h
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

#ifndef _CONFIGURATION_H
#define _CONFIGURATION_H


//////////////////////////////////////////////////////////////////////
///// general configuration
//////////////////////////////////////////////////////////////////////

// engine to use
#define ENGINE_TYPE_STEPPERS

// button set to use
#define BUTTONS_ANALOG
//#define BUTTONS_DIGITAL
//#define BUTTONS_BLUETOOTH

// milliseconds after a button is considered as pressed
#define BUTTON_MIN_PRESSED 30

// milliseconds after a button is considered as long pressed
#define BUTTON_LONG_PRESSED 1000

// put to false to add movements to the program after its execution
#define PROGRAM_RESET_ALWAYS true

// store configuration and program within internal EEPROM
#define USE_PERSISTENT_MEMORY true

// memory capacity for program movements
#define MOVE_LIMIT 100

// milliseconds for the "pause" movement
#define PAUSE_MOVE_MILLIS 1000

// milliseconds delay before starting to move
#define DELAY_BEFORE_GO 500

// milliseconds to pause after every movement
#define AFTER_MOVEMENT_PAUSE 0

// point of view set when Vacalourabot is started
#define POV_INITIAL	POV_ESCORNABOT

// buzzer
#define USE_BUZZER false
#define BUZZER_PIN 10
#define PROGRAM_FINISHED_RTTL RTTL_FIDO

// simple led
#define USE_SIMPLE_LED true
#define SIMPLE_LED_PIN 13



//////////////////////////////////////////////////////////////////////
///// Steppers engine setup
//////////////////////////////////////////////////////////////////////

#ifdef ENGINE_TYPE_STEPPERS

// stepper pin setup (digital outputs)
#define STEPPERS_MOTOR_RIGHT_IN1 5
#define STEPPERS_MOTOR_RIGHT_IN2 4
#define STEPPERS_MOTOR_RIGHT_IN3 3
#define STEPPERS_MOTOR_RIGHT_IN4 2
#define STEPPERS_MOTOR_LEFT_IN1 9
#define STEPPERS_MOTOR_LEFT_IN2 8
#define STEPPERS_MOTOR_LEFT_IN3 7
#define STEPPERS_MOTOR_LEFT_IN4 6

// step calibration
#define STEPPERS_STEPS_PER_SECOND 1000 //Starting speed
#define STEPPERS_LINE_STEPS 1738
#define STEPPERS_TURN_STEPS 1024
#define STEPPERS_ACCELERATION_STEPS 350
#define STEPPERS_MAX_DELTA_STEPS_PER_SECOND 1200 // Additional steps above STEPPERS_STEPS_PER_SECOND

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

#define BS_ANALOG_WIRES 2
//#define BS_ANALOG_WIRES 3

// Button set pin setup (analog input)
#define BS_ANALOG_PIN A4

// input values for each key pressed (0 if key doesn't exist)
#define BS_ANALOG_VALUE_UP 221
#define BS_ANALOG_VALUE_RIGHT 618
#define BS_ANALOG_VALUE_DOWN 518
#define BS_ANALOG_VALUE_LEFT 354
#define BS_ANALOG_VALUE_GO 574
#define BS_ANALOG_VALUE_RESET 448

// input values for each key pressed (0 if key doesn't exist)
// The following values have been tested with Brivoi in two-wire configuration
//#define BS_ANALOG_VALUE_UP 769
//#define BS_ANALOG_VALUE_RIGHT 330
//#define BS_ANALOG_VALUE_DOWN 515
//#define BS_ANALOG_VALUE_LEFT 654
//#define BS_ANALOG_VALUE_GO 881
//#define BS_ANALOG_VALUE_RESET 0


#endif // BUTTONS_ANALOG



//////////////////////////////////////////////////////////////////////
///// Button set Bluetooth
//////////////////////////////////////////////////////////////////////

#ifdef BUTTONS_BLUETOOTH

// Arduino serial port
#define BS_BLUETOOTH_SERIAL	Serial
//#define BS_BLUETOOTH_SERIAL	Serial1
//#define BS_BLUETOOTH_SERIAL	Serial2
//#define BS_BLUETOOTH_SERIAL	Serial3

#define BS_BLUETOOTH_BAUDS 9600

#endif // BUTTONS_BLUETOOTH




//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////


#endif // _CONFIGURATION_H

// EOF
