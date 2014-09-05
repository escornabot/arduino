// PersistentMemory.cpp

#include "PersistentMemory.h"
#include <avr/eeprom.h>
#include <avr/crc16.h>


static PersistentMemory PERSISTENT_MEMORY_INSTANCE;
PersistentMemory* PERSISTENT_MEMORY = &PERSISTENT_MEMORY_INSTANCE;


size_t PersistentMemory::totalBytes()
{
    return E2END + 1;
}


bool PersistentMemory::save(size_t address, uint8_t* buffer, size_t length)
{
    eeprom_write_block(buffer, (uint8_t*) address, length);

    // ToDo: test CRC verification

    return true;
}


bool PersistentMemory::load(size_t address, uint8_t* buffer, size_t length)
{
    eeprom_read_block(buffer, (uint8_t*)address, length);

    // ToDo test CRC verification

    return true;
}


void PersistentMemory::clear()
{
	for (int a = 0; a < E2END; a++)
	{
		eeprom_write_byte((uint8_t*)a, 0);
	}
}


// EOF
