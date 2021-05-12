// DistanceSensor.cpp
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

#include "DistanceSensor.h"
#include "Configuration.h"
#include "EventManager.h"


//////////////////////////////////////////////////////////////////////

extern EventManager* EVENTS;
extern Engine* ENGINE;

//////////////////////////////////////////////////////////////////////

DistanceSensor::DistanceSensor(){};

void DistanceSensor::init()
{
    pinMode(DISTANCE_ECHO, INPUT);
    pinMode(DISTANCE_TRIGGER, OUTPUT);
    pinMode(DISTANCE_LED_INDICATOR, OUTPUT);
    EVENTS->add(this);
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

long DistanceSensor::getDistance()
{
    float distance = 0;

    digitalWrite(DISTANCE_TRIGGER, LOW);    // set trig port low level for 2μs                     
    delayMicroseconds(2);                                                              
    digitalWrite(DISTANCE_TRIGGER, HIGH);  // set trig port high level for 10μs(at least 10μs)     
    delayMicroseconds(10);                                                             
    digitalWrite(DISTANCE_TRIGGER, LOW);    // set trig port low level                             
    
    // Read echo port high level time(μs)
    distance = pulseIn(DISTANCE_ECHO, HIGH, (DISTANCE_MAX_RANGE * 58));

    if (distance == 0)
    {
        return 999;
    } else {
        // Distance(m) =(time(s) * 344(m/s)) / 2
        // ==> 2*Distance(cm) = time(μs) * 0.0344 (cm/μs)
        // ==> Distance(cm) = time(μs) * 0.0172 (cm/μs)
        return distance/58;
    }
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

bool DistanceSensor::isBlocked()
{
    long distance = this->getDistance();

    if (distance <= DISTANCE_TO_STOP)
    {
        digitalWrite(DISTANCE_LED_INDICATOR, HIGH);
        return true;
    } else {
        digitalWrite(DISTANCE_LED_INDICATOR, LOW);
        return false;
    }
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

void DistanceSensor::tick(uint32_t micros)
{
    if (this->isBlocked() && ENGINE->isForwardCurrentMove()) ENGINE->finishActualMove();
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

// EOF
