/*******************************************************************************
 * @file thingpeak.h
 * @brief sends data to thingspeak
 * @author Eugene Mwangi
 * Copyright (C), Synnefa Green Ltd. All rights reserved.
 *******************************************************************************/

#ifndef THINGSPEAK_H_
#define THINGSPEAK_H_

#include <Arduino.h>

String apiKey = "apiKey";       // Enter your Write API key from ThingSpeak

const char* ssid = "ssid";           // Give your wifi network name
const char* pass  = "password";   // Give your wifi network password
const char* server = "api.thingspeak.com";  

void thingspeakInit();
void sendToThingspeak();
void sendUpdate();

#endif // THINGSPEAK_H_