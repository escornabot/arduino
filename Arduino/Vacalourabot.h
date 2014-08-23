// Vacalourabot.h

#ifndef _VACALOURABOT_H
#define _VACALOURABOT_H

#include <stdint.h>

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

// capacidade da memoria en movementos (máximo 255, Arduino 1 ten 2 Kb de memoria SRAM total!)
#define MOVE_LIMIT 100

// punto de vista fixado cando se inicia a vacalourabot
#define POV_INICIAL	POV_VACALOURA

///// tipos enumerados

// punto de vista para executar os movementos
enum POV : uint8_t
{
	POV_VACALOURA,
	POV_NENO,
};

// tipo e valores para os xiros a esquerda e dereita
enum XIRO : uint8_t
{
	XIRO_ESQUERDA,
	XIRO_DEREITA,
};

// tipo e valores para a dirección de sentido dos motores
enum SENTIDO : uint8_t
{
	SENTIDO_ATRAS,
	SENTIDO_ADIANTE,
};

// movement commands
enum MOVE : uint8_t
{
	MOVE_FORWARD,
	MOVE_RIGHT,
	MOVE_BACKWARD,
	MOVE_LEFT,
};

///// structures

typedef struct {
	POV point_of_view;
	uint8_t move_count;
	MOVE move_list[MOVE_LIMIT];
} MoveProgram;

/////


#endif // _VACALOURABOT_H
