#include <Arduino.h>
#include "ds3231.h"
#include "ec5.h"
#include "config.h"
#include "thingspeak.h"

#if RTC_ENABLED
  DS3231* rtc = new DS3231(&Wire);
#endif // RTC_ENABLED

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  #if RTC_ENABLED
    Wire.begin(SDA_PIN, SCL_PIN);
    Wire.setClock(CLK_SPEED);
    #if SET_RTC_TIME_ENABLED
    //sec, min, hr, dayOfWeek(1=Sunday, 7=Saturday), dayOfMonth(1-31), month year(0-99)
      rtc->setDS3231Time(28, 05, 12, 7, 19, 9, 20);
    #endif // SET_RTC_TIME_ENABLED
  #endif // RTC_ENABLED
  #if EC5_ENABLED
    ec5Init(EC5_INPUT, EC5_PWR_PIN);
  #endif // EC5_ENABLED
  #if THINGSPEAK_ENABLED
    thingspeakInit();
  #endif // THINGSPEAK_ENABLED
}

void loop() {
  // put your main code here, to run repeatedly:
  #if THINGSPEAK_ENABLED
    #if THINGSPEAK_TEST
      sendToThingspeak();
      delay(30000);
    #endif //THINGSPEAK_TEST
    sendUpdate(* rtc);
  #endif // THINGSPEAK_ENABLED

}