#include "SoilMoisture.h"
#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <cstring>

SoilMoistureSensor::SoilMoistureSensor(const std::string& portname) : moisture(0.0f)
{
    configureUART(portname);
}

SoilMoistureSensor::~SoilMoistureSensor()
{
    close(serialPort);  // Close the serial port
}

void SoilMoistureSensor::configureUART(const std::string& portname)
{
    serialPort = open(portname.c_str(), O_RDWR | O_NOCTTY | O_SYNC);

    if (serialPort < 0) {
        std::cerr << "Error opening serial port!" << std::endl;
        return;
    }

    struct termios tty;
    memset(&tty, 0, sizeof tty);

    if (tcgetattr(serialPort, &tty) != 0)
    {
        std::cerr << "Error getting serial port attributes!" << std::endl;
        close(serialPort);
        return;
    }

    cfsetospeed(&tty, B115200);
    cfsetispeed(&tty, B115200);

    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8;
    tty.c_cflag &= ~PARENB;
    tty.c_cflag &= ~CSTOPB;
    tty.c_cflag |= CREAD | CLOCAL;

    tty.c_iflag &= ~(IXON | IXOFF | IXANY);
    tty.c_iflag &= ~(ICANON | ECHO | ECHOE | ISIG);
    tty.c_oflag &= ~OPOST;

    if (tcsetattr(serialPort, TCSANOW, &tty) != 0) 
    {
        std::cerr << "Error setting serial port attributes!" << std::endl;
        close(serialPort);
        return;
    }
    std::cout << "Serial port opened and configured successfully!" << std::endl;
}

int SoilMoistureSensor::getMoisture() const
{
    return moisture;
}

void SoilMoistureSensor::readMoistureData()
{
    char buf[256];
    memset(buf,0,sizeof(buf));

    int n = read(serialPort, buf, sizeof(buf)-1);

    if (n > 0) 
    {
        buf[n] = '\0';  // Null terminate the string
        moisture = std::atoi(buf);  // Convert string to integer
    } 
    else 
    {
        std::cerr << "Error reading moisture data!" << std::endl;
    }
    // Flush the serial buffer
    tcflush(serialPort, TCIFLUSH);
}
