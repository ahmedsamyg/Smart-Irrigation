#ifndef DHT22_H
#define DHT22_H

#include <wiringPi.h>
#include <iostream>

class DHT22 
{
public:
    DHT22(int pin);
    bool readSensor();      // Read the sensor and update temperature and humidity
    float getTemperature() const;
    float getHumidity() const;

private:
    int pin;                // GPIO pin for the sensor
    float temperature;      // Last read temperature
    float humidity;         // Last read humidity
};

#endif // DHT22_H
