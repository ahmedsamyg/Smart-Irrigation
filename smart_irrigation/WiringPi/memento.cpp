#include "Memento.h"
#include "Observer.h"

void Memento::addObserver(Observer* observer) 
{
    observers.push_back(observer);
}

void Memento::removeObserver(Observer* observerToRemove) 
{
    observers.erase(std::remove(observers.begin(), observers.end(), observerToRemove), observers.end());
}

void Memento::setState(const Pump& pump, const RainSensor& rainSensor, const DHT22& dhtSensor, const SoilMoistureSensor& soil)
{
    state.moistureLevel = soil.getMoisture();
    state.isRaining = rainSensor.isRaining();
    state.pumpStatus = pump.getSpeed();
    state.temperature = dhtSensor.getTemperature();
    state.humidity  = dhtSensor.getHumidity();
}

void Memento::notifyObservers() 
{
    for (Observer* observer : observers) 
    {
        observer->update(state);  // Notify each observer with the updated state
    }
}
