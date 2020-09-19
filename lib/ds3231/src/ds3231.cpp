/**
 * DS3231 Library
 * 
 * Copyright 2020 Eugene Mwangi <eugene.mwangi@illuminumgreenhouses.com>
 * Based on previous work by:
 *      Basit Ayantunde: <http://lamarrr.github.io>
 * 
 * Manages communication with DS3231 timer.
*/

#include "ds3231.h"

/* ============================================== Public Methods ========================================================= */

/**
 * @brief Initializes the I2C pointer
*/
DS3231::DS3231(TwoWire *i2cAddr)
{
    _i2c = i2cAddr;
}
/**
 * @brief Sets i2c pointer to null
*/
DS3231::~DS3231()
{
    _i2c = nullptr;
}
/**
 * @brief Sets ds3231 time and date
*/
void DS3231::setDS3231Time(int sec, int min, int hr, int dayOfWeek, int day, int month, int year)
{
    _i2c->beginTransmission(DS3231_I2C_ADDRESS);
    _i2c->write(0); // set next input to start at the seconds register
    _i2c->write(decToBcd(sec)); // sets seconds
    _i2c->write(decToBcd(min)); // sets minutes
    _i2c->write(decToBcd(hr)); // sets hours
    _i2c->write(decToBcd(dayOfWeek)); // sets day of week(1=Sunday, 7=Saturday)
    _i2c->write(decToBcd(day)); // sets date(1 to 31)
    _i2c->write(decToBcd(month)); // set month
    _i2c->write(decToBcd(year)); // sets year (0 to 99)
    _i2c->endTransmission();
}
/**
 * @brief Reads time from the DS3231 timer
*/
void DS3231::readDS3231Time(int *sec, int *min, int *hr, int *dayOfWeek, int *day, int *month, int *year)
{
    _i2c->beginTransmission(DS3231_I2C_ADDRESS);
    _i2c->write(0); // sets DS3231 register pointer to 00h
    _i2c->endTransmission();
    _i2c->requestFrom(DS3231_I2C_ADDRESS, 7); //request 7 bytes of data from DS3231 starting from register 00h
    *sec = bcdToDec(_i2c->read() & 0x7f);
    *min = bcdToDec(_i2c->read());
    

}