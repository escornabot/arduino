// PersistentMemory.cpp
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

#include "PersistentMemory.h"

// only supported with atmelavr at the moment
#if defined(_AVR_IOXXX_H_)

#include <avr/eeprom.h>
//#include <avr/crc16.h>

#endif


static PersistentMemory PERSISTENT_MEMORY_INSTANCE;
PersistentMemory* PERSISTENT_MEMORY = &PERSISTENT_MEMORY_INSTANCE;


size_t PersistentMemory::_totalBytes()
{
#if defined(_AVR_IOXXX_H_)
    return E2END + 1;
#else
    return 0;
#endif
}


bool PersistentMemory::_save(size_t address, uint8_t* buffer, size_t length)
{
#if defined(_AVR_IOXXX_H_)
    eeprom_write_block(buffer, (uint8_t*) address, length);
    // ToDo: test CRC verification
    return true;
#else
    return false;
#endif
}


bool PersistentMemory::_load(size_t address, uint8_t* buffer, size_t length)
{
#if defined(_AVR_IOXXX_H_)
    eeprom_read_block(buffer, (uint8_t*)address, length);
    // ToDo test CRC verification
    return true;
#else
    return false;
#endif
}


void PersistentMemory::_clear()
{
#if defined(_AVR_IOXXX_H_)
    for (int a = 0; a < E2END; a++)
    {
        eeprom_write_byte((uint8_t*)a, 0);
    }
#endif
}


bool PersistentMemory::saveProgram(MOVE* move_list, uint8_t move_count)
{
    // move counter
    if (_save(EEPROM_ADDR_MOVE_LIST,
            &move_count,
            1))
        return false;

    // movements
    if (_save(EEPROM_ADDR_MOVE_LIST + 1,
            (uint8_t*)move_list,
            EEPROM_SIZE_MOVE_LIST - 1))
        return false;

    return true;
}


bool PersistentMemory::loadProgram(MOVE* move_list, uint8_t *move_count)
{
    // move counter
    if (_load(EEPROM_ADDR_MOVE_LIST,
            move_count,
            1))
        return false;

    // movements
    if (_load(EEPROM_ADDR_MOVE_LIST + 1,
            (uint8_t*)move_list,
            EEPROM_SIZE_MOVE_LIST - 1))
        return false;

    return true;
}


// EOF
