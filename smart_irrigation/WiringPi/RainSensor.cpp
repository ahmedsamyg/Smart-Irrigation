#include "RainSensor.h"
#include <wiringPi.h>
#include "iostream"

RainSensor::RainSensor(int pin) : pin(pin) {}

void RainSensor::begin() 
{
    pinMode(pin, INPUT);    // Set the pin as an input
}

bool RainSensor::isRaining() const
{
    int state = HIGH;
    state = digitalRead(pin);     // Read the sensor's digital output
    return (state == LOW);        // LOW indicates rain detected
}