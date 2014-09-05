// Vacalourabot.ino

#include "Vacalourabot.h"


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
        #if USE_PERSISTENT_MEMORY

        // gardamos o programa de movementos na EEPROM
        PROGRAM->save();

        #endif

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

    // init button set
    BUTTONS->init();

    #if USE_PERSISTENT_MEMORY

    // cargar os movementos logo dun apagado
    PROGRAM->load();

    #endif
}



void loop(){

    switch (BUTTONS->scanButtons()) {

        case ButtonSet::BUTTON_UP:
            memorizar(MOVE_FORWARD);
            break;

        case ButtonSet::BUTTON_RIGHT:
            memorizar(MOVE_RIGHT);
            break;

        case ButtonSet::BUTTON_DOWN:
            memorizar(MOVE_BACKWARD);
            break;

        case ButtonSet::BUTTON_LEFT:
            memorizar(MOVE_LEFT);
            break;

        case ButtonSet::BUTTON_GO:
            ir();
            break;

        case ButtonSet::BUTTON_RESET:
            PROGRAM->clear();
            break;
    }

    delay(100);
}

// EOF

