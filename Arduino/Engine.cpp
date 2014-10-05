// Engine.cpp
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

#include "Engine.h"

void Engine::executeProgram(MoveProgram* program)
{
    // move by move
    for (int m = 0; m < program->getMoveCount(); m++)
    {
        // which move
        switch (program->getMove(m))
        {
            case MOVE_RIGHT:
                turn90Degrees(1);
                break;
            case MOVE_LEFT:
                turn90Degrees(-1);
                break;
            case MOVE_FORWARD:
                moveStraight(1);
                break;
            case MOVE_BACKWARD:
                moveStraight(-1);
                break;
        }
    }
}

// EOF
