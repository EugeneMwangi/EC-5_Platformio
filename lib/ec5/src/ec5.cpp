/**
 * EC-5 Soil Moisture Sensor Library
 * 
 * Copyright 2020 Eugene Mwangi <eugene.mwangi@illuminumgreenhouses.com>
 * 
 * Manages communication with the EC-5 soil moisture sensor.
*/
#include "ec5.h"

ec5Pins inputPin;
ec5Pins pwrPin;

/**
 * @brief Function initializes the input pins of the EC-5 sensor
 * @param inputPin: analog pin connected to the ec-5's output.
 * @param pwrPin: digital pin connected to ec-5 pwr pin. If not connected, set to 0
*/
void ec5Init(ec5Pins input, ec5Pins pwr)
{
    inputPin = input;
    pwrPin = pwr;
    pinMode(inputPin, INPUT);
    if(pwrPin != 0)pinMode(pwrPin, OUTPUT);
}

/**
 * @brief  Function reads raw reading.
 * @retval average value of 10 raw readings from ec5 sensor.
 */
float ec5RawReading()
{
    if(pwrPin != 0)digitalWrite(pwrPin, HIGH);
    int array[10], sum=0;
    float avg;
    for(int i=0; i<10;i++)
    {
        delayMicroseconds(15000);
        array[i] = analogRead(inputPin);    
    }
    digitalWrite(pwrPin, LOW);
    for(int x:array)
    {
        // Serial.print("x: "); Serial.println(x);
        sum+=x;   
    }
    // Serial.print("sum: "); Serial.println(sum);
    avg = (float)sum / 10;
    // Serial.print("avg: "); Serial.println(avg); 
    return avg;   
}

  /**
   * @brief  Function converts rar voltage reading to volumetric water content(VWC) reading.
   * @retval Calculated volumetric water content value.
   */
  float ec5VWCReading()
  {
    float avg = ec5RawReading();  
    /*      
     * Using a 10 bit ADC, the formula used is:
     *      VWC = (0.0041 * avg) - 0.4895
     *      link: https://www.researchgate.net/publication/320668407_An_Arduino-Based_Wireless_Sensor_Network_for_Soil_Moisture_Monitoring_Using_Decagon_EC-5_Sensors
     */
    float vwcValue = (0.0041 * avg) - 0.4895;
    // Serial.print("VWC Value: "); Serial.println(vwcValue);
    return vwcValue;
  }