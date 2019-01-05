// ButtonSet.h
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

#ifndef _BUTTON_SET_H
#define _BUTTON_SET_H

#include <stdint.h>
#include "Enums.h"
#include "EventListener.h"


/**
 * \brief Interface to different Escornabot button sets.
 * \author @caligari
 */
class ButtonSet : public EventListener
{
public:

    /**
     * Constructor.
     */
    ButtonSet();

    /**
     * Does the hardware initialization.
     */
    virtual void init();

    /**
     * Scans the button input to test if anyone is pressed.
     * @return The button being pressed.
     */
    virtual void scanButtons() = 0;

    /**
     * Runs the execution thread.
     */
    virtual void tick(uint32_t micros);

protected:

    void pressed(BUTTON button);

    void released(BUTTON button);

    bool isPressed(BUTTON button)
            { return _button_statuses[button - 1] != 0; }

private:

    uint32_t _button_statuses[6];

    uint32_t _current_millis;

};


#endif // _BUTTON_SET_H

// EOF
