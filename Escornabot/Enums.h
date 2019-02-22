// Enums.h
/*

Copyright (C) 2014-2019 Escornabot - http://escornabot.com

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

#ifndef _ENUMS_H
#define _ENUMS_H

#include <stdint.h>

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

// movement commands
enum
{
    MOVE_NONE = 0,
    MOVE_FORWARD = 1,
    MOVE_RIGHT = 2,
    MOVE_BACKWARD = 3,
    MOVE_LEFT = 4,
    MOVE_PAUSE = 5,
    MOVE_ALT_RIGHT = 6,
    MOVE_ALT_LEFT = 7,
};
typedef uint8_t MOVE;

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

// point of view in order to execute the movements
enum
{
    POV_ESCORNABOT = 1,
    POV_CHILD = 2,
};
typedef uint8_t POV;

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

// buttons
enum
{
    BUTTON_NONE = 0,
    BUTTON_UP = 1,
    BUTTON_RIGHT = 2,
    BUTTON_DOWN = 3,
    BUTTON_LEFT = 4,
    BUTTON_GO = 5,
    BUTTON_RESET = 6,
};
typedef uint8_t BUTTON;

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

// game modes
enum
{
    GAME_MODE_GRID_90 = 0, // squared grid (classical mode)
    GAME_MODE_GRID_60 = 1, // triangled grid
};
typedef uint8_t GAME_MODE;

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

#endif // _ENUMS_H

// EOF
