// DistanceSensor.h
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

#ifndef _DISTANCE_SENSOR_H
#define _DISTANCE_SENSOR_H

#include <Arduino.h>
#include "EventListener.h"
#include "Engine.h"

// Distance in cm
#define DISTANCE_TO_STOP 3
#define DISTANCE_MAX_RANGE 20 

/**
 * \brief To use a distance sensor (HC-SR04)
 * \author @AntonioNav
 */
class DistanceSensor : public EventListener
{
public:

    /**
     * Constructor.
     */
    DistanceSensor();

    /**
     * Does the hardware initialization.
     */
    void init();

    /**
     * Get distance in cm
     */
    long getDistance();

    /**
     * Check if there is a object in range
     */
    bool isBlocked();

    /**
     * Runs the execution thread.
     */
    virtual void tick(uint32_t micros);

};

#endif // _DISTANCE_SENSOR_H

// EOF
