#ifndef PUMP_H
#define PUMP_H

#include <wiringPi.h>

#define SPEED_OFF   0
#define SPEED_LOW   1
#define SPEED_MED   2
#define SPEED_MAX   3
class Pump 
{
private:
    int pwmPin;   // GPIO pin for PWM output
    int speed;    // Current pump speed: 0 (off), 1 (low), 2 (medium), 3 (max)
public:
    Pump(int pumpPin);
    void setSpeed(int desiredSpeed);    // Set the pump speed
    int getSpeed() const;               // Get the current pump speed
};

#endif // PUMP_H
