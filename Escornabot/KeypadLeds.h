// KeypadLeds.h
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

#ifndef _KEYPAD_LEDS_H
#define _KEYPAD_LEDS_H

#include "EventListener.h"

#define BUTTON_PAUSE BUTTON_DOWN

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

    virtual void buttonPressed(BUTTON button)
        { setAllLed(false); setLed(button, true ); }
    virtual void buttonReleased(BUTTON button)
        { setLed(button, false); }
    virtual void buttonLongReleased(BUTTON button)
        { setLed(button, false); }

    virtual void moveExecuting(MOVE move)
        { _blinkPause(move == MOVE_PAUSE); setLed(_mov2btn(move), true); }
    virtual void moveExecuted(MOVE move)
        { _blinkPause(false); setLed(_mov2btn(move), false); }
    virtual void programAborted(uint8_t exe, uint8_t tot)
        { _blinkPause(false); setAllLed(false); }

    virtual void gameModeSelected(GAME_MODE mode)
        { setAllLed(false); setLed(mode + 1 , true); }

    virtual void tick(uint32_t micros);

private:

    const Config* _config;

    BUTTON _mov2btn(MOVE move);

    bool _isPause;
    void _blinkPause(bool enable)
        { _isPause = enable; setLed(BUTTON_PAUSE, enable); }
};

#endif // _KEYPAD_LEDS_H

// EOF
