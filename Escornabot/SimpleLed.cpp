// SimpleLed.cpp
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
    pinMode(_pin, OUTPUT);
    digitalWrite(_pin, LOW);

    _status = false;
    _tenths_blink = 5;
    _next_blink = 0;

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

void SimpleLed::blink(bool active)
{
    if (active)
    {
        _next_blink = 1;
    }
    else
    {
        _next_blink = 0;
        setStatus(false);
    }
}

//////////////////////////////////////////////////////////////////////

bool SimpleLed::tick(uint32_t micros)
{
    if (_next_blink > 0)
    {
        micros /= 100000;
        micros %= 65536;

        if (micros >= _next_blink)
        {
            _next_blink = micros + SimpleLed::_tenths_blink;
            toggle();
        }
    }

    return false;
}

//////////////////////////////////////////////////////////////////////

// EOF
