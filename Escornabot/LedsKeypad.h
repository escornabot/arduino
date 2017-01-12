// LedsKeypad.h
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

#ifndef _LEDS_KEYPAD_H
#define _LEDS_KEYPAD_H

#include "SimpleLed.h"
#include "EventListener.h"

/**
 * \brief Manage keypad events to turn on/off keypad leds.
 * \author @caligari
 */
class LedsKeypad : public EventListener
{
public:

    typedef struct {
        uint8_t pin_led_up;
        uint8_t pin_led_right;
        uint8_t pin_led_down;
        uint8_t pin_led_left;
        uint8_t pin_led_go;
    } Config;

    LedsKeypad(const Config* config);

    void init();

    SimpleLed* getLed(BUTTON button)
        { return &(_leds[button - 1]); }

    void setStatus(uint8_t BUTTON, bool light);
    void setStatusAll(bool light);

    virtual bool buttonPressed(BUTTON button)
        { setStatus(button, true ); return false; }
    virtual bool buttonReleased(BUTTON button)
        { setStatus(button, false); return false; }
    virtual bool buttonLongReleased(BUTTON button)
        { setStatus(button, false); return false; }

    virtual bool moveExecuting(MOVE move)
        { setStatus(_mov2btn(move), true); return false; }
    virtual bool moveExecuted(MOVE move)
        { setStatus(_mov2btn(move), false); return false; }
    virtual bool programAborted(uint8_t exe, uint8_t tot)
        { setStatusAll(false); return false; }

private:

    SimpleLed _leds[5];

    BUTTON _mov2btn(MOVE move);

};

#endif // _LEDS_KEYPAD_H

// EOF
