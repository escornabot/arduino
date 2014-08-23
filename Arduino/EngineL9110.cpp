// EngineL9110.cpp

#include "EngineL9110.h"
#include <Arduino.h>


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


void activarMotor(int motor, SENTIDO direccion)
{
  if (motor == MOTOR_DEREITA)
  {
      // motor dereita
      digitalWrite(PIN_MOTOR_DEREITA_A, direccion ? HIGH : LOW);
      digitalWrite(PIN_MOTOR_DEREITA_B, direccion ? LOW : HIGH);
  }
  else
  {
      // motor esquerda
      digitalWrite(PIN_MOTOR_ESQUERDA_A, direccion ? HIGH : LOW);
      digitalWrite(PIN_MOTOR_ESQUERDA_B, direccion ? LOW : HIGH);
  }
}


void desactivarMotor(int motor)
{
  if (motor == MOTOR_DEREITA)
  {
      // motor dereita
      digitalWrite(PIN_MOTOR_DEREITA_A, LOW);
      digitalWrite(PIN_MOTOR_DEREITA_B, LOW);
  }
  else
  {
      // motor esquerda
      digitalWrite(PIN_MOTOR_ESQUERDA_A, LOW);
      digitalWrite(PIN_MOTOR_ESQUERDA_B, LOW);
  }
}


void avanzar(byte unidades, SENTIDO direccion)
{
    // activamos os dous motores
    activarMotor(MOTOR_DEREITA, direccion);
    activarMotor(MOTOR_ESQUERDA, direccion);

    delay(unidades * PASO_MILISEGUNDOS);

    // desactivamos os dous motores
    desactivarMotor(MOTOR_DEREITA);
    desactivarMotor(MOTOR_ESQUERDA);
}


void xirar(XIRO xiro, int milisegundos)
{
   if (xiro == XIRO_DEREITA)
   {
      // xiro en sentido reloxo
      activarMotor(MOTOR_ESQUERDA, SENTIDO_ADIANTE);
      activarMotor(MOTOR_DEREITA, SENTIDO_ATRAS);
   }
   else
   {
     // xiro en sentido anti-reloxo
      activarMotor(MOTOR_DEREITA, SENTIDO_ADIANTE);
      activarMotor(MOTOR_ESQUERDA, SENTIDO_ATRAS);
   }

   delay(milisegundos);

   desactivarMotor(MOTOR_ESQUERDA);
   desactivarMotor(MOTOR_DEREITA);
}


void xirar90(int veces)
{
  // non facer nada cando veces sexa 0
  if (veces != 0)
  {
    // cálculo do xiro e cantidade
    XIRO xiro;
    int cantidade;

    // tipo de xiro e cantidade en positivo
    if (veces > 0)
    {
      xiro = XIRO_DEREITA;
      cantidade = veces;
    }
    else
    {
      xiro = XIRO_ESQUERDA;
      cantidade = -veces;
    }

    // executar os xiros
    while (cantidade-- > 0)
    {
      xirar(xiro, ANGULO_90_MILISEGUNDOS);
    }
  }
}


void EngineL9110::init()
{
    pinMode(PIN_MOTOR_ESQUERDA_A, OUTPUT);
    pinMode(PIN_MOTOR_ESQUERDA_B, OUTPUT);
    pinMode(PIN_MOTOR_DEREITA_A, OUTPUT);
    pinMode(PIN_MOTOR_DEREITA_B, OUTPUT);
}


void EngineL9110::turn90Degrees(int8_t times)
{
	xirar90(times);
}


void EngineL9110::moveStraight(int8_t units)
{
	avanzar(abs(units), units < 0 ? SENTIDO_ATRAS : SENTIDO_ADIANTE);
}


// EOF
