// SimpleLed.cpp
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

#include "SimpleLed.h"
#include "EventManager.h"
#include <Arduino.h>

//////////////////////////////////////////////////////////////////////

extern EventManager* EVENTS;

//////////////////////////////////////////////////////////////////////

SimpleLed::SimpleLed(uint8_t pin)
{
    this->_pin = pin;
}

//////////////////////////////////////////////////////////////////////

void SimpleLed::init()
{
    _status = false;

    pinMode(_pin, OUTPUT);

    EVENTS->add(this);
}

//////////////////////////////////////////////////////////////////////

void SimpleLed::setStatus(bool value)
{
    this->_status = value;
    digitalWrite(_pin, _status ? HIGH : LOW);
}

//////////////////////////////////////////////////////////////////////

void SimpleLed::toggle()
{
    _status = !_status;
    digitalWrite(_pin, _status ? HIGH : LOW);
}

//////////////////////////////////////////////////////////////////////

void SimpleLed::flashOne(uint16_t millis)
{
    setStatus(true);
    delay(millis);
    setStatus(false);
}

//////////////////////////////////////////////////////////////////////

// EOF
