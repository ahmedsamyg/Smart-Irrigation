#ifndef SOIL_MOISTURE_SENSOR_H
#define SOIL_MOISTURE_SENSOR_H

#include <string>
class SoilMoistureSensor
{
private:
    int serialPort;
    int moisture;
    void configureUART(const std::string& portname);    // Configure the UART communication with the ESP32
public:
    SoilMoistureSensor(const std::string& portname);
    ~SoilMoistureSensor();
    int getMoisture() const;
    void readMoistureData();
};
#endif // SOIL_MOISTURE_SENSOR_H
