// ButtonSetAnalog.h
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

#ifndef _BUTTON_SET_ANALOG_H
#define _BUTTON_SET_ANALOG_H

#include "ButtonSet.h"

/**
 * \brief Implementation of a button set connected to 1 analog input.
 * \author @caligari
 */
class ButtonSetAnalog : ButtonSet
{
public:

    typedef struct {
        uint8_t pin_button_set;
        bool pullup;
        int16_t value_button_up;
        int16_t value_button_right;
        int16_t value_button_down;
        int16_t value_button_left;
        int16_t value_button_go;
        int16_t value_button_reset;
    } Config;

    ButtonSetAnalog(const Config* config);

    /**
     * Does the hardware initialization.
     */
    virtual void init();

    /**
     * Reads the buttons
     */
    virtual void scanButtons();

private:

    const Config* _config;

    BUTTON _last_button;

};


#endif // _BUTTON_SET_ANALOG_H

// EOF
