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

extern void thingspeakInit();
extern void sendToThingspeak();
extern void sendUpdate();

#endif // THINGSPEAK_H_