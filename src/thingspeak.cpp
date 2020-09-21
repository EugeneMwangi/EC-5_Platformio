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
    Serial.println("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, pass);

    while (WiFi.status() != WL_CONNECTED) 
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected");  
}

void sendToThingspeak()
{
    //
}