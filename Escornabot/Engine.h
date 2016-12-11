// Engine.h
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

#ifndef _ENGINE_H
#define _ENGINE_H

#include <stddef.h>
#include "MoveList.h"


/**
 * \brief Interface to different Escornabot engines.
 * \author @caligari
 */
class Engine
{
public:

    /**
     * Constructor.
     */
    Engine();

    /**
     * Does the hardware initialization.
     */
    virtual void init() = 0;

    /**
     * Sets the default degrees value to use with turnRight() and turnLeft().
     */
    void setTurnDegrees(int16_t degrees) { _degrees = degrees; }

    /**
     * Turns left or right an angle specified in degrees (from Escornabot's POV).
     * @param degrees Amount of degrees to turn. Positive is clockwise,
     *     negative is counter-clockwise.
     */
    virtual void turn(int16_t degrees) = 0;

    /**
     * Turns right the configured amount of degrees.
     */
    void turnRight() { turn(_degrees); }

    /**
     * Turns left the configured amount of degrees.
     */
    void turnLeft() { turn(-_degrees); }

    /**
     * Moves forward or backward direction (from Escornabot's POV).
     * @param units Amount of units to move. Positive is forwards, negative
     *     is backwards.
     */
    virtual void moveStraight(int8_t units) = 0;

    /**
     * Executes the movement program.
     * @param program Movements to execute.
     * @param pause Milliseconds waiting between movements.
     * @param pov Point of view of movements (POV_ESCORNABOT or POV_CHILD).
     */
    void execute(MoveList* program, uint16_t pause, POV pov);

    void cancelExecution() { _is_cancelling = true; }

    bool isExecuting() { return _program != NULL; }


protected:

    int16_t _degrees;

    MoveList* _program;
    uint8_t _program_index;
    MOVE _getCurrentMove() { return _program->getMove(_program_index); }

    bool _is_cancelling;

    void _prepareMove();

};


#endif // _ENGINE_H

// EOF
