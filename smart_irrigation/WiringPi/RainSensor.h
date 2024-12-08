#ifndef RAIN_SENSOR_H
#define RAIN_SENSOR_H

class RainSensor 
{
private:
    int pin;
public:
    RainSensor(int pin);
    void begin();
    bool isRaining() const;
};

#endif // RAIN_SENSOR_H