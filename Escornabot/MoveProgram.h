// MoveProgram.h
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

#ifndef _MOVE_PROGRAM_H
#define _MOVE_PROGRAM_H

#include <stdint.h>

#include "Configuration.h"
#include "Move.h"


class MoveProgram
{
private:

	ProgramFile _program_file;

	POV _point_of_view;

	uint16_t _pause_after_movement;

public:

	/**
	 * Constructor.
	 */
	MoveProgram(uint16_t pause_after_movement);

	/**
	 * Removes all movements from program.
	 */
	void clear();

	/**
	 * Returns the amount of movements in program.
	 * @return Amount of movements.
	 */
	uint8_t getMoveCount();

	/**
	 * Returns the current point of view to execute the movements.
	 * @return The point of view.
	 */
	POV getPointOfView();

	/**
	 * Sets the current point of view to execute the movements.
	 * @param point_of_view The point of view.
	 */
	void setPointOfView(POV point_of_view);

	uint16_t getPauseAfterMovement() { return _pause_after_movement; }

	/**
	 * Adds a new movement at the end of the program.
	 * @param move The movement to add.
	 */
	void addMove(MOVE move);

	/**
	 * Gets the movement from program at specified position.
	 * @param index Position index (zero-based).
	 */
	MOVE getMove(uint8_t index);

	#if USE_PERSISTENT_MEMORY

	/**
	 * Saves the program in EEPROM.
	 */
	void save();

	/**
	 * Loads the program from EEPROM.
	 */
	void load();

	#endif
};

#endif // _MOVE_PROGRAM_H

// EOF
