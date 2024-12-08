#ifndef MEMENTO_H
#define MEMENTO_H

#include <vector>
#include <iostream>
#include "DHT22.h"
#include "RainSensor.h"
#include "Pump.h"
#include "SoilMoisture.h"
#include <algorithm> // for std::remove


class Memento
{
public:
    struct SystemState
    {
        int moistureLevel;        // Soil moisture reading
        bool isRaining;           // Rain sensor status
        int pumpStatus;          // true for ON, false for OFF
        float temperature;        // Temperature from DHT22
        float humidity;           // Humidity from DHT22
    };
private:
    std::vector<class Observer*> observers;
    SystemState state;
public:
    Memento() : state({0,false,SPEED_OFF,0,0}) {}

    void setState(const Pump& pump, const RainSensor& rainSensor, const DHT22& dhtSensor, const SoilMoistureSensor& soil);
    
    SystemState getState() const{ return state;}

    void addObserver(Observer* observer);       // Add an observer
    void removeObserver(Observer* observer);    // Remove an observer
    void notifyObservers();                     // Notify all observers about the state change

};



#endif // MEMENTO_H
