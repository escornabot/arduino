// Vacalourabot.ino

#include "Vacalourabot.h"

// variables globais

// memoria para os estados dos botóns
byte estado_boton_esquerda;
byte estado_boton_dereita;
byte estado_boton_adiante;
byte estado_boton_atras;
byte estado_boton_ir;
byte estado_boton_borrar;


/*
void irPdvNeno()
{
  // supoñer que se está detrás da vacalourabot
  byte direccion_anterior = MOVE_FORWARD;

  // por cada un dos movementos
  for (int m = 0; m < PROGRAM->move_count; m++)
  {
    // calcular o xiro dende o punto de vista actual
    int xiro = PROGRAM->move_list[m] - direccion_anterior;

    // axustar xiro para o lado máis curto
    if (abs(xiro) == 3) xiro /= -xiro;

    // executar o xiro
    xirar90(xiro);

    // avanzar un paso cara adiante
    avanzar(1, SENTIDO_ADIANTE);

    // actualizar dirección actual
    direccion_anterior = PROGRAM->move_list[m];
  }
}
*/

void irPdvVacaloura()
{
  // por cada un dos movementos
  for (int m = 0; m < PROGRAM->getMoveCount(); m++)
  {
    // evalúa o tipo e procede
    switch (PROGRAM->getMove(m))
    {
      case MOVE_RIGHT:
        ENGINE->turn90Degrees(1);
        break;
      case MOVE_LEFT:
        ENGINE->turn90Degrees(-1);
        break;
      case MOVE_FORWARD:
        ENGINE->moveStraight(1);
        break;
      case MOVE_BACKWARD:
        ENGINE->moveStraight(-1);
        break;
    }
  }
}

void ir()
{
  // só imos se hai movementos programados
  if (PROGRAM->getMoveCount() > 0)
  {
    // gardamos o programa de movementos na EEPROM
    PROGRAM->save();

    // pequena pausa para dar tempo a soltar o botón
    delay(1000);

    // evaluar o punto de vista para execución de movementos
    if (PROGRAM->getPointOfView() == POV_VACALOURA)
    {
      // punto de vista da vacaloura
      irPdvVacaloura();
    }
    else
    {
      // punto de vista do neno
//      irPdvNeno();
    }
  }
}


void memorizar(MOVE movemento)
{
  if (PROGRAM->getMoveCount() < MOVE_LIMIT)
  {
    PROGRAM->addMove(movemento);
  }
  else
  {
    ir();
  }
}

void setup()
{
    // init hardware
    ENGINE->init();

    // configurar botóns
    pinMode(PIN_BOTON_ESQUERDA, INPUT);
    pinMode(PIN_BOTON_DEREITA, INPUT);
    pinMode(PIN_BOTON_ADIANTE, INPUT);
    pinMode(PIN_BOTON_ATRAS, INPUT);
    pinMode(PIN_BOTON_IR, INPUT);
    pinMode(PIN_BOTON_BORRAR, INPUT);

    // inicializar os estados dos botóns
    estado_boton_esquerda = LOW;
    estado_boton_dereita = LOW;
    estado_boton_adiante = LOW;
    estado_boton_atras = LOW;
    estado_boton_ir = LOW;
    estado_boton_borrar = LOW;

    // cargar os movementos logo dun apagado
    PROGRAM->load();
}



void loop(){

  // leer os botóns
  if (digitalRead(PIN_BOTON_ESQUERDA) ^ estado_boton_esquerda)
  {
    estado_boton_esquerda = !estado_boton_esquerda;
    if (estado_boton_esquerda == HIGH)
    {
      memorizar(MOVE_LEFT);
    }
  }

  if (digitalRead(PIN_BOTON_DEREITA) ^ estado_boton_dereita)
  {
    estado_boton_dereita = !estado_boton_dereita;
    if (estado_boton_dereita == HIGH)
    {
      memorizar(MOVE_RIGHT);
    }
  }

  if (digitalRead(PIN_BOTON_ADIANTE) ^ estado_boton_adiante)
  {
    estado_boton_adiante = !estado_boton_adiante;
    if (estado_boton_adiante == HIGH)
    {
      memorizar(MOVE_FORWARD);
    }
  }

  if (digitalRead(PIN_BOTON_ATRAS) ^ estado_boton_atras)
  {
    estado_boton_atras = !estado_boton_atras;
    if (estado_boton_atras == HIGH)
    {
      memorizar(MOVE_BACKWARD);
    }
  }

  if (digitalRead(PIN_BOTON_BORRAR) ^ estado_boton_borrar)
  {
    estado_boton_borrar = !estado_boton_borrar;
    if (estado_boton_borrar == HIGH)
    {
      PROGRAM->clear();
    }
  }

  if (digitalRead(PIN_BOTON_IR) ^ estado_boton_ir)
  {
    estado_boton_ir = !estado_boton_ir;
    if (estado_boton_ir == HIGH)
    {
      // tempiño para que solten o botón antes de arrancar
      delay(500);

      // executa os movementos
      ir();
    }
  }

}

// EOF
