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
 * \brief Listener of events and turning on/off a digital output.
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

    void flashOne(uint16_t millis);

    // turn on between movement pauses
    virtual bool moveExecuted(MOVE move)
        { setStatus(true); return false; }
    virtual bool moveExecuting(MOVE move)
        { setStatus(false); return false; }
    virtual bool programFinished()
        { setStatus(false); return false; }

    // turn on when button is pressed (200 milliseconds)
    virtual bool moveAdded(MOVE move)
        { flashOne(200); return false; }
    virtual bool programReset()
        { flashOne(200); return false; }
    virtual bool programStarted(uint8_t total_moves)
        { flashOne(200); return false; }

private:

    uint8_t _pin;

    bool _status;

};

#endif // _SIMPLE_LED_H

// EOF
