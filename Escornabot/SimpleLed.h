// SimpleLed.h
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

#ifndef _SIMPLE_LED_H
#define _SIMPLE_LED_H

#include <stdint.h>
#include "EventListener.h"


/**
 * \brief A simple LED controller with syncronous blinking feature.
 * \author @caligari
 */
class SimpleLed : public EventListener
{
public:

    SimpleLed(uint8_t pin);

    void init();

    bool getStatus() { return _status; }

    void setStatus(bool value);

    void toggle();

    void blink(bool active);

    void setBlinkTime(uint8_t tenths) { _tenths_blink = tenths; }

protected:

    virtual bool tick(uint32_t micros);

private:

    uint8_t _pin;

    bool _status;

    uint8_t _tenths_blink;

    uint16_t _next_blink;

};

#endif // _SIMPLE_LED_H

// EOF
