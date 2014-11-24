// Move.h
/*

Copyright (C) 2014 Bricolabs - http://bricolabs.cc

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301,
USA.

See LICENSE.txt for details

*/

#ifndef _MOVE_H
#define _MOVE_H

#include "Configuration.h"
#include <stdint.h>

// movement commands
enum
{
	MOVE_NONE,
	MOVE_FORWARD,
	MOVE_RIGHT,
	MOVE_BACKWARD,
	MOVE_LEFT,
};
typedef uint8_t MOVE;


// point of view in order to execute the movements
enum
{
	POV_ESCORNABOT,
	POV_CHILD,
};
typedef uint8_t POV;


// program file
typedef struct {
	uint8_t move_count;
	MOVE move_list[MOVE_LIMIT];
} ProgramFile;


#endif // _MOVE_H

// EOF

