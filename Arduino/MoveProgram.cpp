// MoveProgram.cpp

#include "MoveProgram.h"


MoveProgram::MoveProgram()
{
	_program_file.move_count = 0;
	_point_of_view = POV_INICIAL;
}



void MoveProgram::clear()
{
	_program_file.move_count = 0;
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
