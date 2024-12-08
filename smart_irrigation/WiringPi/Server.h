#ifndef SERVER_H
#define SERVER_H

#include "DHT22.h"
#include "Pump.h"
#include "RainSensor.h"
#include "SoilMoisture.h"
#include "Observer.h"
#include "caretaker.h"

#include <string>
#include <netinet/in.h>
#include <sstream>
#include <algorithm>
#include <thread>
#include <chrono>


class Server : public Observer
{
private:
    int server_fd,new_socket;
    struct sockaddr_in address;    
    int addrlen = sizeof(address);
    bool manualControlActive;

    DHT22& DHT22_sensor;
    RainSensor& rainSensor;
    Pump& pump;
    SoilMoistureSensor& soil;
    Memento& memento;
    Caretaker& caretaker;

    std::thread sensorUpdateThread;  // Thread for updating sensors

    void setupServer();
    void processCommand(const std::string &command, int socket_fd);
    void ReadSensors();
    void update(const Memento::SystemState& state) override;

public:
    Server(DHT22  &c_DHT22,RainSensor &c_Rain,Pump &c_pump,SoilMoistureSensor &c_soil,Memento &c_memento,Caretaker &c_caretaker);
    ~Server();
    void run();
    void sensorUpdateLoop();
    void checkAutomaticControl();
};

#endif // SERVER_H
