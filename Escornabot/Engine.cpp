// Engine.cpp
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

#include "Engine.h"
#include "EventManager.h"
#include <Arduino.h>

#define SQUARE_ROOT_2 1.414213562f

//////////////////////////////////////////////////////////////////////

extern EventManager* EVENTS;

//////////////////////////////////////////////////////////////////////

Engine::Engine()
{
    _current_degrees = 0;
    _square_diagonals = true;
    _program = NULL;
    _program_index = 0;
    _is_cancelling = false;
    _pauseTimeout = 0;
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

    uint16_t delta_degrees = 0;

    switch (move)
    {
        case MOVE_RIGHT:
            delta_degrees = +(_program->getTurnDegrees());
            turn(delta_degrees);
            break;

        case MOVE_LEFT:
            delta_degrees = -(_program->getTurnDegrees());
            turn(delta_degrees);
            break;

        case MOVE_FORWARD:
            moveStraight(_calculateAdvanceUnits());
            break;

        case MOVE_BACKWARD:
            moveStraight(-_calculateAdvanceUnits());
            break;

        case MOVE_PAUSE:
            _pauseTimeout = millis() + PAUSE_MOVE_MILLIS;
            break;

        case MOVE_ALT_RIGHT:
            delta_degrees = +(_program->getAltTurnDegrees());
            turn(delta_degrees);
            break;

        case MOVE_ALT_LEFT:
            delta_degrees = -(_program->getAltTurnDegrees());
            turn(delta_degrees);
            break;

    }

    _current_degrees += delta_degrees;
}

//////////////////////////////////////////////////////////////////////

float Engine::_calculateAdvanceUnits()
{
    float advance = 1.0f;

    if (_square_diagonals)
    {
        if (isAligned(45) && !isAligned(90))
        {
            advance = SQUARE_ROOT_2;
        }
    }

    return advance;
}

//////////////////////////////////////////////////////////////////////

bool Engine::_inPauseMove()
{
    if (_pauseTimeout > 0)
    {
        // in pause yet
        if (millis() < _pauseTimeout) return true;

        // pause is finished
        _pauseTimeout = 0;
    }

    return false;
}

//////////////////////////////////////////////////////////////////////

// EOF
