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
///// engine L9110 setup
//////////////////////////////////////////////////////////////////////

#ifdef ENGINE_TYPE_L9110

// configuración dos pins do driver dos motores
#define PIN_MOTOR_ESQUERDA_A 10
#define PIN_MOTOR_ESQUERDA_B 11
#define PIN_MOTOR_DEREITA_A 12
#define PIN_MOTOR_DEREITA_B 13

// configuración dos pins dos botóns
#define PIN_BOTON_ESQUERDA 3
#define PIN_BOTON_DEREITA 5
#define PIN_BOTON_ADIANTE 6
#define PIN_BOTON_ATRAS 7
#define PIN_BOTON_IR 8
#define PIN_BOTON_BORRAR 9

// milisegundos que dura o paso
#define PASO_MILISEGUNDOS 1000

// cada un dous motores
#define MOTOR_DEREITA 0
#define MOTOR_ESQUERDA 1

// grado de xiro (calibrar o tempo que tarda en milisegundos segundo o tipo de motores)
#define ANGULO_90_MILISEGUNDOS 500 // milisegundos para 90 graos

#endif // ENGINE_TYPE_L9110

//////////////////////////////////////////////////////////////////////
/////
//////////////////////////////////////////////////////////////////////

#endif // _CONFIGURATION_H

// EOF
