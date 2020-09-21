/**
 * Cofiguration file for the nodeMCU
 * 
*/

#ifndef CONFIG_H_
#define CONFIG_H_

#define RTC_ENABLED             1
#define EC5_ENABLED             1
#define SET_RTC_TIME_ENABLED    1
#define THINGSPEAK_ENABLED      1
#define THINGSPEAK_TEST         1

//Define the input pins of the EC-5 Soil Moisture Sensor
#define EC5_PWR_PIN      16 //This is GPIO16(D0)
#define EC5_INPUT        A0   

//Define the SDA & SCL Pins and the CLOCK Speed of the DS3231 
#define SDA_PIN          4
#define SCL_PIN          0
#define CLK_SPEED        400000L // sets I2C clock to 400kHz
#endif // CONFIG_H_