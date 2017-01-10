// StateMachine.h
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

#ifndef _STATE_MACHINE_H
#define _STATE_MACHINE_H

#include <stdint.h>

/**
 * \brief Finite-state machine controller.
 * \author @caligari
 */
class StateMachine
{
public:

    enum { STATE_NONE = 0 };
    typedef uint8_t STATE;

    STATE getState() { return this->_state; }

    void changeState(STATE state_to);

protected:

    virtual void _changeStateBefore(STATE state_to) = 0;
    virtual void _changeStateAfter(STATE state_from) = 0;

private:

    STATE _state = STATE_NONE;
};


#endif // _STATE_MACHINE_H

// EOF

