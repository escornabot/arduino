// Setup.h
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

#ifndef _SETUP_H
#define _SETUP_H

#include "EventListener.h"
#include "StateMachine.h"
#include "Enums.h"

/**
 * \brief Setup controller.
 * \author @caligari
 */
class Setup : public EventListener, StateMachine
{
public:

    void init();

    ////////////////////////////////////////////////////////////
    // EventListener interface
    ////////////////////////////////////////////////////////////

    virtual bool buttonLongReleased(BUTTON button);
    virtual bool tick(uint32_t micros);

private:

    ////////////////////////////////////////////////////////////
    // StateMachine interface
    ////////////////////////////////////////////////////////////

    virtual void _changeStateBefore(STATE state_to);
    virtual void _changeStateAfter(STATE state_from);
};


#endif // _SETUP_H

// EOF
