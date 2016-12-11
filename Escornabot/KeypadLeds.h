// KeypadLeds.h
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

#ifndef _KEYPAD_LEDS_H
#define _KEYPAD_LEDS_H

#include "EventListener.h"

/**
 * \brief Manage keypad events to turn on/off keypad leds.
 * \author @caligari
 */
class KeypadLeds : public EventListener {

public:

    typedef struct {
        uint8_t pin_led_up;
        uint8_t pin_led_right;
        uint8_t pin_led_down;
        uint8_t pin_led_left;
        uint8_t pin_led_go;
    } Config;

    KeypadLeds(const Config* config);

    void init();

    void setLed(uint8_t BUTTON, bool light);
    void setAllLed(bool light);

    virtual void buttonPressed(BUTTON button) { setLed(button, true ); }
    virtual void buttonReleased(BUTTON button) { setLed(button, false); }
    virtual void buttonLongReleased(BUTTON button) { setLed(button, false); }

    virtual void moveExecuting(MOVE move) { setLed(_mov2btn(move), true); }
    virtual void moveExecuted(MOVE move) { setLed(_mov2btn(move), false); }
    virtual void programAborted(uint8_t exe, uint8_t tot) { setAllLed(false); }

private:

    const Config* _config;

    BUTTON _mov2btn(MOVE move);

};

#endif // _KEYPAD_LEDS_H

// EOF
