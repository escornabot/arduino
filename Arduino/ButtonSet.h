// ButtonSet.h
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

#ifndef _BUTTON_SET_H
#define _BUTTON_SET_H

#include <stdint.h>

/**
 * Interface to different Vacaloura engines.
 */
class ButtonSet
{
public:

	enum
	{
		BUTTON_NONE,
		BUTTON_UP,
		BUTTON_RIGHT,
		BUTTON_DOWN,
		BUTTON_LEFT,
		BUTTON_GO,
		BUTTON_RESET,
	};
        typedef uint8_t BUTTON;

	/**
	 * Does the hardware initialization.
	 */
	virtual void init() = 0;

	/**
	 * Scans the button input to test if anyone is pressed.
	 * @return The button being pressed.
	 */
	virtual BUTTON scanButtons() = 0;

};


#endif // _BUTTON_SET_H

// EOF
