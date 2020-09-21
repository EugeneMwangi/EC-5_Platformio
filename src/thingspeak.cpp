/*******************************************************************************
 * @file thingpeak.cpp
 * @brief sends data to thingspeak
 * @author Eugene Mwangi
 * Copyright (C), Synnefa Green Ltd. All rights reserved.
 *******************************************************************************/


#include "thingspeak.h"
#include "ec5.h"

String apiKey = "apiKey";       // Enter your Write API key from ThingSpeak

const char* ssid = "ssid";           // Give your wifi network name
const char* pass  = "password";   // Give your wifi network password
const char* server = "api.thingspeak.com";  

WiFiClient client;

/**
 * @brief Initializes Wifi communication
*/

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
/**
 * @brief Sends values to ThingSpeak
*/
void sendToThingspeak()
{
    float vwcTSVal = ec5VWCReading();
    float rawAvg = ec5VoltageReading(); //Change this to ec5RawReading

    if (client.connect(server,80))   //   "184.106.153.149" or api.thingspeak.com
    {  
        String postStr = apiKey;
        postStr +="&field1=";
        postStr += String(vwcTSVal);
        postStr +="&field2=";
        postStr += String(rawAvg);
        postStr += "\r\n\r\n";

        client.print("POST /update HTTP/1.1\n");
        client.print("Host: api.thingspeak.com\n");
        client.print("Connection: close\n");
        client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
        client.print("Content-Type: application/x-www-form-urlencoded\n");
        client.print("Content-Length: ");
        client.print(postStr.length());
        client.print("\n\n");
        client.print(postStr);
        }
        client.stop();

        Serial.println("Waiting...");     
        // thingspeak needs minimum 15 sec delay between updates
        delay(1000);      
}