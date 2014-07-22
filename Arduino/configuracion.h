// configuracion.h

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
#define PASO_MILLISEGUNDOS 1000

// cada un dous motores
#define MOTOR_DEREITA 0
#define MOTOR_ESQUERDA 1

// grado de xiro (calibrar o tempo que tarda en milisegundos segundo o tipo de motores)
#define ANGULO_90 500 // milisegundos para 90 graos

// capacidade da memoria en movementos (máximo 255, Arduino 1 ten 2 Kb de memoria SRAM total!)
#define MOVEMENTOS_LIMITE 100
