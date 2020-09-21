/*******************************************************************************
 * @file thingpeak.cpp
 * @brief sends data to thingspeak
 * @author Eugene Mwangi
 * Copyright (C), Synnefa Green Ltd. All rights reserved.
 *******************************************************************************/


#include "thingspeak.h"
String apiKey = "apiKey";       // Enter your Write API key from ThingSpeak

const char* ssid = "ssid";           // Give your wifi network name
const char* pass  = "password";   // Give your wifi network password
const char* server = "api.thingspeak.com";  

WiFiClient client;

void thingspeakInit()
{
    Serial.print("hello");
}
void sendToThingspeak()
{
    //
}