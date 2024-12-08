#include "Server.h"
#include <iostream>
#include <cstring>
#include <unistd.h>



#define PORT 65432
#define moisture_threshold 3000

Server::Server(DHT22  &c_DHT22,RainSensor &c_Rain,Pump &c_pump,SoilMoistureSensor &c_soil,Memento &c_memento,Caretaker &c_caretaker):
DHT22_sensor(c_DHT22) ,rainSensor(c_Rain),pump(c_pump) , soil(c_soil) , memento(c_memento),caretaker(c_caretaker)
{
    setupServer();
    // Start the sensor update thread
    sensorUpdateThread = std::thread(&Server::sensorUpdateLoop, this);
}

Server::~Server() {
    close(server_fd);
    if (sensorUpdateThread.joinable()) {
        sensorUpdateThread.join();  // Ensure the thread is properly joined before exiting
    }
}

void Server::setupServer() 
{
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0) 
    {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) 
    {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) 
    {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
}

void Server::processCommand(const std::string &command, int socket_fd) 
{
    std::string response;
    if (command == "pump_off") 
    {
        manualControlActive = true;
        pump.setSpeed(SPEED_OFF);
        response = "Pump turned OFF";
    } else if (command == "pump_low") {
        manualControlActive = true;
        pump.setSpeed(SPEED_LOW);
        response = "Pump set to LOW speed";
    } else if (command == "pump_med") {
        manualControlActive = true;
        pump.setSpeed(SPEED_MED);
        response = "Pump set to MEDIUM speed";
    } else if (command == "pump_max") {
        manualControlActive = true;
        pump.setSpeed(SPEED_MAX);
        response = "Pump set to MAX speed";
    } else if (command == "auto_control")
    {
        manualControlActive = false;  // Re-enable automatic control
        response = "Automatic control re-enabled";
    }else {
        response = "Unknown command received";
    }
    send(socket_fd, response.c_str(), response.length(), 0);
}

void Server::ReadSensors()
{
    soil.readMoistureData();
    DHT22_sensor.readSensor();
    rainSensor.begin();

    memento.setState(pump,rainSensor, DHT22_sensor,soil);
    caretaker.save(memento);
    memento.notifyObservers();
}

void Server::update(const Memento::SystemState& state)
{
    std::string response;
    std::ostringstream oss;
    oss << "\nHumidity: " << state.humidity << "%, Temperature: " << state.temperature << "°C"
        << "\nPump State: "<< state.pumpStatus
        << "\nSoil Moisture level: "<< state.moistureLevel
        << "\nRain state: "<< state.isRaining<< "\n";
    response = oss.str();
    send(new_socket, response.c_str(), response.length(), 0);
}

void Server::run() 
{
    char buffer[1024] = {0};
    std::cout << "Server is running and waiting for a connection..." << std::endl;

    while (true) 
    {
        new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
        if (new_socket < 0) 
        {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }
        std::cout << "Client connected." << std::endl;

        while (true) 
        {
            memset(buffer, 0, sizeof(buffer));
            int valread = read(new_socket, buffer, 1024);
            if (valread <= 0) {
                std::cout << "Client disconnected." << std::endl;
                break;
            }
            buffer[valread] = '\0'; // Ensure null-termination
            std::string command(buffer);
            if (command == "Quit") {
                std::cout << "Shutting down server." << std::endl;
                close(new_socket);
                return;
            }
            
            processCommand(command, new_socket);   
             
        }
        close(new_socket);
    }
}


void Server::sensorUpdateLoop()
{
    auto lastUpdateTime = std::chrono::steady_clock::now();
    auto lastControlCheckTime = std::chrono::steady_clock::now();

    while (true) 
    {
        // Check automatic control more frequently
        if (std::chrono::steady_clock::now() - lastControlCheckTime >= std::chrono::seconds(1)) 
        {
            checkAutomaticControl();  // Quick automatic pump control
            lastControlCheckTime = std::chrono::steady_clock::now();
        }
        // Read sensors and notify client less frequently
        if (std::chrono::steady_clock::now() - lastUpdateTime >= std::chrono::seconds(5)) 
        {
            ReadSensors();  // Sensor read and notify observer
            lastUpdateTime = std::chrono::steady_clock::now();
        }
        //ReadSensors();  // Read sensor data
        //checkAutomaticControl();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void Server::checkAutomaticControl()
{
    if (manualControlActive) return; // Ignore automatic control if manual control is active

    soil.readMoistureData();
    if ((soil.getMoisture()) > moisture_threshold)  // Moisture below thershold means we need to turn on the pump
    {
        if(rainSensor.isRaining()) //if it's raining turn OFF pump
        {
            pump.setSpeed(SPEED_OFF);
        }
        else
        {
            pump.setSpeed(SPEED_MAX);  // Turn ON  pump
        }
        
    }
    else // Moisture above thershold means turn OFF the pump
    {
        pump.setSpeed(SPEED_OFF);
    }
}
