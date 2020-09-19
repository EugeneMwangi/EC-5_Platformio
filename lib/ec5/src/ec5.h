/**
 * EC-5 Soil Moisture Sensor Library
 * 
 * Copyright 2020 Eugene Mwangi <eugene.mwangi@illuminumgreenhouses.com>
 * 
 * Manages communication with the EC-5 soil moisture sensor.
*/


#ifndef EC_5_H_
#define EC_5_H_

#include <Arduino.h>

typedef int ec5Pins;

void ec5Init(ec5Pins input,  ec5Pins pwr=0);
float ec5VoltageReading();
float ec5VWCReading();
#endif // EC_5_H_