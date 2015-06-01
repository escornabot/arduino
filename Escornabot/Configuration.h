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
//#define BUTTONS_DIGITAL
#define BUTTONS_ANALOG
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
#define STEPPERS_LINE_STEPS 2664
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
#define BS_ANALOG_PIN A4

// input values for each key pressed
#define BS_ANALOG_VALUE_UP 223
#define BS_ANALOG_VALUE_RIGHT 616
#define BS_ANALOG_VALUE_DOWN 520
#define BS_ANALOG_VALUE_LEFT 357
#define BS_ANALOG_VALUE_GO 573
#define BS_ANALOG_VALUE_RESET 450

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
