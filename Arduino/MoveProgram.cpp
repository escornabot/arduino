// MoveProgram.cpp
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

#include "Move.h"
#include "MoveProgram.h"
#include "StatusIndicatorManager.h"

extern StatusIndicatorManager* INDICATORS;


MoveProgram::MoveProgram(uint16_t pause_after_movement)
{
    _pause_after_movement = pause_after_movement;
	_program_file.move_count = 0;
	_point_of_view = POV_ESCORNABOT;
}



void MoveProgram::clear()
{
	_program_file.move_count = 0;
    INDICATORS->indicateProgramReset();
}



uint8_t MoveProgram::getMoveCount()
{
	return _program_file.move_count;
}



POV MoveProgram::getPointOfView()
{
	return _point_of_view;
}



void MoveProgram::setPointOfView(POV point_of_view)
{
	_point_of_view = point_of_view;
}



void MoveProgram::addMove(MOVE move)
{
	_program_file.move_list[_program_file.move_count++] = move;
    INDICATORS->indicateMoveAdded(move);
}



MOVE MoveProgram::getMove(uint8_t index)
{
	return _program_file.move_list[index];
}



#if USE_PERSISTENT_MEMORY

#include "PersistentMemory.h"

extern PersistentMemory* PERSISTENT_MEMORY;


void MoveProgram::save()
{
    // save only when there are movements to save
    if (_program_file.move_count > 0)
    {
        PERSISTENT_MEMORY->saveProgram(&_program_file);
    }
}


void MoveProgram::load()
{
    if (!PERSISTENT_MEMORY->loadProgram(&_program_file)
        || _program_file.move_count > MOVE_LIMIT)
    {
      // invalidate the program (clear)
      _program_file.move_count = 0;
    }
}

#endif


// EOF
