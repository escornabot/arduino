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
/////
//////////////////////////////////////////////////////////////////////

// configuración dos pins dos botóns
#define PIN_BOTON_ESQUERDA 3
#define PIN_BOTON_DEREITA 5
#define PIN_BOTON_ADIANTE 6
#define PIN_BOTON_ATRAS 7
#define PIN_BOTON_IR 8
#define PIN_BOTON_BORRAR 9

#endif // _CONFIGURATION_H

// EOF
