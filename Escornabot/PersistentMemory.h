// PersistentMemory.h
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

#ifndef _PERSISTENT_MEMORY_H
#define _PERSISTENT_MEMORY_H

#include <stddef.h>
#include <stdint.h>
#include "Enums.h"
#include "MoveList.h"

// eeprom organization
#define EEPROM_ADDR_MOVE_LIST 0
#define EEPROM_SIZE_MOVE_LIST (MOVE_LIMIT + 1)

/**
 * \brief Provides convenient methods to use persistent memory (EEPROM).
 * \author @caligari
 */
class PersistentMemory
{
public:

    /**
     * Saves the list of movements in EEPROM.
     * @param move_list Array with the movements.
     * @param move_count Number of movements.
     * @return OK is true. Error is false.
     */
    bool saveProgram(MOVE* move_list, uint8_t move_count);

    /**
     * Loads a program of movements from EEPROM.
     * @param move_list Array with the movements.
     * @param move_count Number of movements.
     * @return OK is true. Error is false.
     */
    bool loadProgram(MOVE* move_list, uint8_t *move_count);

private:

    /**
     * Returns the size of persistent memory.
     *
     * @return Amount of memory in bytes.
     */
    size_t _totalBytes();

    /**
     * Saves a buffer to the persistent memory.
     *
     * @address Persistent memory address.
     * @buffer Main memory pointer with the data to save.
     * @size Length in bytes of the buffer to save.
     */
    bool _save(size_t address, uint8_t* buffer, size_t length);

    /**
     * Loads a buffer from the persistent memory.
     *
     * @address Persistent memory address.
     * @buffer Main memory pointer where the data will be loaded.
     * @size Length in bytes of the buffer to load.
     * @return OK is true. Error is false.
     */
    bool _load(size_t address, uint8_t* buffer, size_t length);

    /**
     * Fills the memory with zeroes.
     */
    void _clear();

};


#endif // _PERSISTENT_MEMORY_H

// EOF
