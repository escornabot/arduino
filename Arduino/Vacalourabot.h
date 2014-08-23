// Vacalourabot.h

#ifndef _VACALOURABOT_H
#define _VACALOURABOT_H

#include <stdint.h>

#include "Configuration.h"
#include "MoveProgram.h"


///// tipos enumerados

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

/////


#endif // _VACALOURABOT_H
