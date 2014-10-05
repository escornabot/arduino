// BluetoothInterface.cpp
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

#include "BluetoothInterface.h"
#include <string.h>

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

BluetoothInterface::BluetoothInterface(const Config* cfg)
{
	_config = cfg;
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

void BluetoothInterface::init()
{
	_config->serial->begin(_config->bauds, SERIAL_8N1);
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

ButtonSet::BUTTON BluetoothInterface::scanButtons()
{
	while (readLine())
	{
		// one-char commands
		if (strlen(command) == 1)
		{
			char* found = strchr(BUTTONS_RELEASED, command[0]);
			if (found)
			{
				return (BUTTON)((found - BUTTONS_RELEASED) + 1);
			}
		}
	}

	return BUTTON_NONE;
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

bool BluetoothInterface::readLine()
{
	while (_config->serial->available())
	{
		char key = _config->serial->read();

		if (key == '\n')
		{
			command[command_idx] = '\0';
			command_idx = 0;
			return true;
		}

		command[command_idx++] = key;
	}
	return false;
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

// EOF
