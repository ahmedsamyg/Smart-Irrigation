#include <iostream>
#include "Server.h"
#include "Memento.h"
#include "caretaker.h"
#include "Observer.h"



#define DHT_pin     0
#define Pump_pin    1
#define Rain_pin    24


int main()
{
    wiringPiSetup(); // Initialize WiringPi

    DHT22 DHT22_sensor(DHT_pin);
    RainSensor rainSensor(Rain_pin);
    Pump pump(Pump_pin);
    SoilMoistureSensor soil("/dev/ttyUSB0");
    
    Memento memento;
    Caretaker caretaker;
    Server server(DHT22_sensor,rainSensor,pump,soil,memento,caretaker);
    memento.addObserver(&server);
    server.run();


    return 0;
}