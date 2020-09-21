/*******************************************************************************
 * @file thingpeak.h
 * @brief sends data to thingspeak
 * @author Eugene Mwangi
 * Copyright (C), Synnefa Green Ltd. All rights reserved.
 *******************************************************************************/

#ifndef THINGSPEAK_H_
#define THINGSPEAK_H_

#include <Arduino.h>
#include "ESP8266WiFi.h"

class DS3231;
class Sht1x;

void thingspeakInit();
void sendToThingspeak(Sht1x &sht);
void sendUpdate(DS3231 &rtc, Sht1x &sht);

#endif // THINGSPEAK_H_