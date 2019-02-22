// MoveList.cpp
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

#include "Enums.h"
#include "MoveList.h"
#include "EventManager.h"

extern EventManager* EVENTS;


MoveList::MoveList()
{
    _move_count = 0;
    _degrees = 90;
    _alt_degrees = 45;
}



void MoveList::clear()
{
    _move_count = 0;
    EVENTS->indicateProgramReset();
}



uint8_t MoveList::getMoveCount()
{
    return _move_count;
}



void MoveList::addMove(MOVE move)
{
    _move_list[_move_count++] = move;
    EVENTS->indicateMoveAdded(move);
}



void MoveList::addProgram(const MOVE moves[])
{
    int m = 0;
    while (moves[m] != MOVE_NONE)
        _move_list[_move_count++] = moves[m++];
}



MOVE MoveList::getMove(uint8_t index)
{
    return _move_list[index];
}



#if USE_PERSISTENT_MEMORY

#include "PersistentMemory.h"

extern PersistentMemory* PERSISTENT_MEMORY;


void MoveList::save()
{
    // save only when there are movements to save
    if (_move_count > 0)
    {
        PERSISTENT_MEMORY->saveProgram(_move_list, _move_count);
    }
}


void MoveList::load()
{
    if (!PERSISTENT_MEMORY->loadProgram(_move_list, &_move_count)
        || _move_count > MOVE_LIMIT)
    {
      // invalidate the program (clear)
      _move_count = 0;
    }
}

#endif


// EOF
