
# Smart Irrigation System with Raspberry Pi and Qt Desktop Application

## Project Overview

This project is a **Smart Irrigation System** powered by a **Raspberry Pi**, designed to automate watering based on environmental conditions such as soil moisture, temperature, humidity, and rain detection. The system integrates with a **Qt desktop application** for real-time monitoring and manual pump control.

## Features

- **Automatic Pump Control**: Activates based on soil moisture levels and rain detection.
- **Manual Override**: Qt desktop application allows manual pump control (Off, Low, Medium, Max).
- **Real-Time Monitoring**: Displays sensor data (temperature, humidity, soil moisture, rain status, and pump state) in the Qt application.


## System Architecture

### Components

1. **Raspberry Pi** (Server):
   - Monitors sensors: **DHT22** (temperature & humidity), **soil moisture sensor** (via ESP32), and **rain sensor**.
   - Controls the water pump using **PWM** via a **2N2222 transistor**.
   - Communicates with the Qt application over a **TCP socket**.
   
2. **ESP32**:
   - Reads soil moisture analog values and transmits data to the Raspberry Pi over **UART**.
   
3. **Qt Desktop Application** (Client):
   - Provides a graphical interface for manual control and real-time monitoring.

## Hardware Requirements

- Raspberry Pi 5
- ESP32 microcontroller
- DHT22 Temperature & Humidity Sensor
- Soil Moisture Sensor
- Rain Sensor
- Submersible Water Pump (5V)
- 2N2222 NPN Transistor
- Power supply, resistor, and wiring

## Software Requirements

- **Raspberry Pi OS** (or any Linux-based OS)
- **Qt** (for the desktop client)
- **C++17** or later (for server code)
- **WiringPi** (for GPIO control)


## Installation & Setup

### 1. WiringPi Setup (Raspberry Pi)

```bash
sudo apt-get update
sudo apt-get install wiringpi
```

### 2. Build the Server Application

Run the server:
```bash
sudo ./smart_irrigation
```

### 3. Run the Qt Desktop Application

1. Open the Qt project in **Qt Creator**.
2. Build and run the Qt application.

## How to Use

### Automatic Control

- The system reads sensor data.
- It activates the pump if the soil moisture level falls below `3000` (adjustable in `Server.cpp`).
- If it is raining, the pump turns off.

### Manual Override

1. Use the Qt desktop application to send commands:
   - `pump_off` – Turn off the pump.
   - `pump_low` – Set the pump to low speed.
   - `pump_med` – Set the pump to medium speed.
   - `pump_max` – Set the pump to maximum speed.
   - `auto_control` – Re-enable automatic control.

## Class Overview

### `Server`

- Manages sensor readings and pump control.
- Handles communication between Raspberry Pi and the Qt application.
- Implements **automatic control** and **manual override** logic.

### `Memento` & `Caretaker`

- Stores system states, enabling undo/redo functionality.
- Notifies observers (e.g., Qt app) when state changes occur.

### `DHT22`, `RainSensor`, `Pump`, `SoilMoistureSensor`

- Interfaces with the respective sensors and actuators.
- Provides methods to initialize and read sensor data.

## Future Enhancements

- **Weather Forecast Integration**: Incorporate online weather data for predictive control.
- **Data Visualization**: Enhance the Qt application with charts and historical data.
- **Mobile APP Support: Extend control and monitoring to mobile devices.
