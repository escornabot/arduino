// MoveProgram.h

#ifndef _MOVE_PROGRAM_H
#define _MOVE_PROGRAM_H

#include <stdint.h>

#include "Configuration.h"

// movement commands
enum MOVE : uint8_t
{
	MOVE_NONE,
	MOVE_FORWARD,
	MOVE_RIGHT,
	MOVE_BACKWARD,
	MOVE_LEFT,
};



// point of view in order to execute the movements
enum POV : uint8_t
{
	POV_VACALOURA,
	POV_NENO,
};



typedef struct {
	uint8_t move_count;
	MOVE move_list[MOVE_LIMIT];
} ProgramFile;



class MoveProgram
{
private:

	ProgramFile _program_file;

	POV _point_of_view;

public:

	/**
	 * Constructor.
	 */
	MoveProgram();

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

	/**
	 * Saves the program in EEPROM.
	 */
	void save();

	/**
	 * Loads the program from EEPROM.
	 */
	void load();
};

#endif // _MOVE_PROGRAM_H
