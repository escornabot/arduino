// PersistentMemory.h

#ifndef _PERSISTENT_MEMORY_H
#define _PERSISTENT_MEMORY_H

#include <stddef.h>
#include <stdint.h>
#include "MoveProgram.h"

#define EEPROM_ADDR_PROGRAM 0
#define EEPROM_SIZE_PROGRAM sizeof(ProgramFile)

/**
 * Provides convenient methods to use persistent memory (EEPROM) and be sure
 * that data is stored in the right memory positions.
 */
class PersistentMemory
{
private:

    /**
     * Returns the size of persistent memory.
     *
     * @return Amount of memory in bytes.
     */
    size_t totalBytes();

    /**
     * Saves a buffer to the persistent memory.
     *
     * @address Persistent memory address.
     * @buffer Main memory pointer with the data to save.
     * @size Length in bytes of the buffer to save.
     */
    bool save(size_t address, uint8_t* buffer, size_t length);

    /**
     * Loads a buffer from the persistent memory.
     *
     * @address Persistent memory address.
     * @buffer Main memory pointer where the data will be loaded.
     * @size Length in bytes of the buffer to load.
     * @return OK is true. Error is false.
     */
    bool load(size_t address, uint8_t* buffer, size_t length);

public:

    /**
     * Saves the program of movements in EEPROM.
     * @param program Pointer to the ProgramFile structure to save.
     * @return OK is true. Error is false.
     */
    inline bool saveProgram(ProgramFile* program)
    {
        return save(EEPROM_ADDR_PROGRAM, (uint8_t*)program, EEPROM_SIZE_PROGRAM);
    }

    /**
     * Loads a program of movements from EEPROM.
     * @param program Pointer to the ProgramFile structure to load.
     * @return OK is true. Error is false.
     */
    inline bool loadProgram(ProgramFile* program)
    {
        return load(EEPROM_ADDR_PROGRAM, (uint8_t*)program, EEPROM_SIZE_PROGRAM);
    }
};



#endif

// EOF
