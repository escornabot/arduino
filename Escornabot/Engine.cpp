// Engine.cpp
/*

Copyright (C) 2014-2017 Escornabot - http://escornabot.com

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
#include "EventManager.h"
#include <Arduino.h>

//////////////////////////////////////////////////////////////////////

extern EventManager* EVENTS;

//////////////////////////////////////////////////////////////////////

Engine::Engine()
{
    _degrees = 90;
    _program = NULL;
    _program_index = 0;
    _is_cancelling = false;
}

//////////////////////////////////////////////////////////////////////

void Engine::execute(MoveList* program, uint16_t pause, POV pov)
{
    if (program->getMoveCount() == 0) return;

    _program_index = 0;
    _is_cancelling = false;
    _program = program;

    EVENTS->indicateProgramStarted(program->getMoveCount());
    _prepareMove();
}

//////////////////////////////////////////////////////////////////////

void Engine::_prepareMove()
{
    if (_is_cancelling)
    {
        // program is cancelled
        EVENTS->indicateProgramAborted(_program_index, _program->getMoveCount());
        _program = NULL;
        return;
    }

    if (_program_index == _program->getMoveCount())
    {
        // program is finished
        _program = NULL;
        EVENTS->indicateProgramFinished();
        return;
    }

    MOVE move = _getCurrentMove();
    EVENTS->indicateMoveExecuting(move);

    switch (move)
    {
        case MOVE_RIGHT:
            turnRight();
            break;

        case MOVE_LEFT:
            turnLeft();
            break;

        case MOVE_FORWARD:
            moveStraight(1);
            break;

        case MOVE_BACKWARD:
            moveStraight(-1);
            break;
/*
        case MOVE_PAUSE:
            delay(PAUSE_MOVE_MILLIS);
            break;
*/
    }
}

//////////////////////////////////////////////////////////////////////

// EOF
