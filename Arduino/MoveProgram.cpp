// MoveProgram.cpp

#include "MoveProgram.h"

#include <EEPROM.h>


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



void MoveProgram::save()
{
  // gardamos na EEPROM cando haxa movementos que gardar
  if (_program_file.move_count > 0)
  {
    // o primeiro dato é o número de movementos
    EEPROM.write(0, _program_file.move_count);

    // e de seguido os movementos almacenados
    for (int m = 0; m < _program_file.move_count; m++)
    {
      EEPROM.write(m + 1, _program_file.move_list[m]);
    }
  }
}



void MoveProgram::load()
{
  // o primeiro dato é o número de movementos
  _program_file.move_count = EEPROM.read(0);

  if (_program_file.move_count > MOVE_LIMIT)
  {
    // a memoria EEPROM está corrupta
    _program_file.move_count = 0;
    return;
  }

  // e de seguido os movementos
  for (int m = 0; m < _program_file.move_count; m++)
  {
    _program_file.move_list[m] = (MOVE)EEPROM.read(m + 1);
  }
}


// eof
