// Configuration.h
/*

Copyright (C) 2014-2019 Escornabot - http://escornabot.com

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

// button set to use (analog input, digital input)
#define BUTTONS_ANALOG
//#define BUTTONS_DIGITAL

// milliseconds after a button is considered as pressed
#define BUTTON_MIN_PRESSED 30

// milliseconds after a button is considered as long pressed
#define BUTTON_LONG_PRESSED 1000

// put to false to add movements to the program after its execution
#define PROGRAM_RESET_ALWAYS true

// store configuration and program within internal EEPROM
#define USE_PERSISTENT_MEMORY false

// memory capacity for program movements
#define MOVE_LIMIT 100

// milliseconds for the "pause" movement
#define PAUSE_MOVE_MILLIS 1000

// milliseconds delay before starting to move
#define DELAY_BEFORE_GO 500

// milliseconds to pause after every movement
#define AFTER_MOVEMENT_PAUSE 0

// point of view set when Vacalourabot is started
#define POV_INITIAL    POV_ESCORNABOT

// bluetooth serial
#define USE_BLUETOOTH true
#define BLUETOOTH_BAUDS 9600

// buzzer
#define USE_BUZZER true
#define BUZZER_PIN 10
#define PROGRAM_FINISHED_RTTL RTTL_FIDO
#define TONE_FREQ_UP 2637
#define TONE_FREQ_RIGHT 4434
#define TONE_FREQ_DOWN 3520
#define TONE_FREQ_LEFT 2217

// simple led
#define USE_SIMPLE_LED false
#define SIMPLE_LED_PIN 13

// keypad leds
#define USE_KEYPAD_LEDS true
#define KEYPAD_LED_PIN_UP A0
#define KEYPAD_LED_PIN_RIGHT A3
#define KEYPAD_LED_PIN_DOWN A2
#define KEYPAD_LED_PIN_LEFT A1
#define KEYPAD_LED_PIN_GO 13


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
#define STEPPERS_STEPS_PER_SECOND 1000
#define STEPPERS_LINE_STEPS 1738
#define STEPPERS_TURN_STEPS 1024

#endif



//////////////////////////////////////////////////////////////////////
///// Button set digital
//////////////////////////////////////////////////////////////////////

#ifdef BUTTONS_DIGITAL

// keypad pin setup (digital or analog inputs) (use 255 if key doesn't exist)
#define BS_DIGITAL_UP A0
#define BS_DIGITAL_RIGHT A1
#define BS_DIGITAL_DOWN A2
#define BS_DIGITAL_LEFT A3
#define BS_DIGITAL_GO A4
#define BS_DIGITAL_RESET 255

#endif // BUTTONS_DIGITAL



//////////////////////////////////////////////////////////////////////
///// Button set analog
//////////////////////////////////////////////////////////////////////

#ifdef BUTTONS_ANALOG

#define BS_ANALOG_WIRES 2
//#define BS_ANALOG_WIRES 3

// keypad pin setup (analog input)
#define BS_ANALOG_PIN A7

// input values for each key pressed (0 if key doesn't exist)
#define BS_ANALOG_VALUE_UP 512
#define BS_ANALOG_VALUE_RIGHT 860
#define BS_ANALOG_VALUE_DOWN 769
#define BS_ANALOG_VALUE_LEFT 683
#define BS_ANALOG_VALUE_GO 810
#define BS_ANALOG_VALUE_RESET 0

#endif // BUTTONS_ANALOG



//////////////////////////////////////////////////////////////////////
///// Button set Bluetooth
//////////////////////////////////////////////////////////////////////

#ifdef USE_BLUETOOTH

// Arduino serial port (default is Serial, use Serial1 with Arduino Micro)
//#define BLUETOOTH_SERIAL    Serial
//#define BLUETOOTH_SERIAL    Serial1
//#define BLUETOOTH_SERIAL    Serial2
//#define BLUETOOTH_SERIAL    Serial3

#endif // USE_BLUETOOTH




//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////


#endif // _CONFIGURATION_H

// EOF
