// configuracion.h

#ifndef _CONFIGURACION_H
#define _CONFIGURACION_H

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
#define MOVEMENTOS_LIMITE 100

// punto de vista fixado cando se inicia a vacalourabot
#define PDV_INICIAL	PDV_VACALOURA

///// tipos enumerados

// punto de vista para executar os movementos
#define PDV byte
#define PDV_VACALOURA 0
#define PDV_NENO      1

// tipo e valores para os xiros a esquerda e dereita
#define XIRO byte
#define XIRO_ESQUERDA 1
#define XIRO_DEREITA  2

// tipo e valores para a dirección de sentido dos motores
#define SENTIDO byte
#define SENTIDO_ATRAS   1
#define SENTIDO_ADIANTE 2

// tipo e valores que toman os movementos na memoria
#define MOVEMENTO byte
#define MOVEMENTO_ADIANTE   1
#define MOVEMENTO_DEREITA   2
#define MOVEMENTO_ATRAS     3
#define MOVEMENTO_ESQUERDA  4

///// estruturas

typedef struct {
	uint8_t movementos_cantidade;
	MOVEMENTO movementos_lista[MOVEMENTOS_LIMITE];
} Programa;


#endif // _CONFIGURACION_H
