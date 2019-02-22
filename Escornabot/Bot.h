// Bot.h
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

#ifndef _BOT_H
#define _BOT_H

#include "EventListener.h"
#include "Enums.h"

/**
 * \brief Object instance in order to register as an event listener.
 * \author @caligari
 */
class Bot : public EventListener
{
public:

    void init();

    void loop();

    ////////////////////////////////////////////////////////////
    // EventListener interface
    ////////////////////////////////////////////////////////////

    virtual void programFinished();

    virtual void programAborted(uint8_t executed, uint8_t total);

    virtual void buttonPressed(BUTTON button);

    virtual void buttonReleased(BUTTON button);

    virtual void buttonLongReleased(BUTTON button);

private:

    void _go();

    void _storeMove(MOVE move);

    uint16_t _total_programs = 0;

    GAME_MODE _game_mode = GAME_MODE_GRID_90;

    void _next_game_mode();

};

#endif // _BOT_H

// EOF
