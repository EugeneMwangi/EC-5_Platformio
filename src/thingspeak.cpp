/*******************************************************************************
 * @file thingpeak.cpp
 * @brief sends data to thingspeak
 * @author Eugene Mwangi
 * Copyright (C), Synnefa Green Ltd. All rights reserved.
 *******************************************************************************/


#include "thingspeak.h"
#include "ec5.h"
#include "ds3231.h"
#include "config.h"
#include "sht1x.h"

String apiKey = "apikey";       // Enter your Write API key from ThingSpeak

const char* ssid = "ssid";           // Give your wifi network name
const char* pass  = "pass";   // Give your wifi network password
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
void sendToThingspeak(Sht1x &sht)
{
    #if EC5_ENABLED
    float vwcTSVal = ec5VWCReading();
    float rawAvg = ec5RawReading(); //Change this to ec5RawReading

    Serial.print("Volumetric Water Content: "); Serial.println(vwcTSVal);
    
    #if SHT1x_ENABLED
    float sht1xTempC = sht.readTemperatureC();
    Serial.print("SHT10 Temperature: "); Serial.println(sht1xTempC);
    #endif //SHT1x_ENABLED

    if (client.connect(server,80))   //   "184.106.153.149" or api.thingspeak.com
    {  
        String postStr = apiKey;
        postStr +="&field1=";
        postStr += String(vwcTSVal);
        postStr +="&field2=";
        postStr += String(rawAvg);
        #if SHT1x_ENABLED
        postStr +="&field3=";
        postStr +=String(sht1xTempC);
        #endif //SHT1x_ENABLED
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
    #endif // EC5_ENABLED  
}
/**
 * @brief Sends regular updates to thingspeak by calling sendToThingspeak()
*/
void sendUpdate(DS3231 &rtc, Sht1x &sht10)
{
    #if RTC_ENABLED
    static int count = 0;
    // Get data from the DS3231
    int second, minute, hour, dayOfWeek, day, month, year;
    // retrieve data from DS3231
    rtc.readDS3231Time(&second, &minute, &hour, &dayOfWeek, &day, &month, &year);
    rtc.displayTime();
    int rem = minute % 5;
    if (rem == 0 && count == 0) 
    {
        sendToThingspeak(sht10);
        count++;
    }
    else if (rem > 0)
    {
        count = 0;
    }
    #endif //RTC_ENABLED    
}