// Vacalourabot.h

#ifndef _VACALOURABOT_H
#define _VACALOURABOT_H

#include "Configuration.h"
#include "MoveProgram.h"
#include "Engine.h"


// motor engine defined from configuration
#if defined(ENGINE_TYPE_L9110)
	#include "EngineL9110.h"
	#define ENGINE_CLASS EngineL9110
#else
	// include new header file and define ENGINE_CLASS here...
#endif


// EEPROM as persistent memory
#if USE_PERSISTENT_MEMORY
	#include "PersistentMemory.h"
#endif


///// global vars

// engine
static ENGINE_CLASS ENGINE_INSTANCE;
static Engine* ENGINE = (Engine*) &ENGINE_INSTANCE;

// program
static MoveProgram PROGRAM_INSTANCE;
static MoveProgram* PROGRAM = &PROGRAM_INSTANCE;


#endif // _VACALOURABOT_H

// EOF
