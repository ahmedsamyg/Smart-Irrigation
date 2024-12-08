#include "Pump.h"
#include <iostream>

// Constructor
Pump::Pump(int pin) : pwmPin(pin), speed(SPEED_OFF) 
{
    pinMode(pwmPin, PWM_OUTPUT);
    pwmWrite(pwmPin, 0); // Start with the pump off
}

// Set the pump speed
void Pump::setSpeed(int desiredSpeed) 
{
    if (desiredSpeed < SPEED_OFF || desiredSpeed > SPEED_MAX) 
    {
        std::cerr << "Invalid speed!" << std::endl;
        return;
    }
    speed = desiredSpeed;
    int pwmValue;

    // Map speed levels to PWM values (0-1024 for wiringPi PWM)
    switch (speed) 
    {
        case SPEED_OFF: pwmValue = 0;    break; // Off
        case SPEED_LOW: pwmValue = 333;  break; // Low
        case SPEED_MED: pwmValue = 666;  break; // Medium
        case SPEED_MAX: pwmValue = 1024; break; // Max
    }

    pwmWrite(pwmPin, pwmValue);
    //std::cout << "Pump speed set to " << speed << " (" << pwmValue << " PWM value)." << std::endl;
}

// Get the current pump speed
int Pump::getSpeed() const 
{
    return speed;
}
