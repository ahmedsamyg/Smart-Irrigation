#include "DHT22.h"

// Constructor
DHT22::DHT22(int pin) : pin(pin), temperature(0), humidity(0) 
{

}

bool DHT22::readSensor() 
{
    uint8_t data[5] = {0};
    unsigned int lastState = HIGH;
    unsigned int count = 0;
    unsigned int j = 0;

    // Send start signal
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
    delay(20); // At least 18ms
    digitalWrite(pin, HIGH);
    delayMicroseconds(40);
    pinMode(pin, INPUT);

    // Read data
    for (int i = 0; i < 85; i++) {
        count = 0;
        while (digitalRead(pin) == lastState) 
        {
            count++;
            delayMicroseconds(1);
            if (count == 255) break;
        }
        lastState = digitalRead(pin);
        if (count == 255) break;
        // Skip the first 3 transitions
        if ((i >= 4) && (i % 2 == 0)) 
        {
            data[j / 8] <<= 1;
            if (count > 16) data[j / 8] |= 1;
            j++;
        }
    }

    // Check if 40 bits (5 bytes) were received
    if ((j >= 40) && (data[4] == ((data[0] + data[1] + data[2] + data[3]) & 0xFF))) 
    {
        // Convert the data
        humidity = ((data[0] << 8) + data[1]) / 10.0;
        temperature = (((data[2] & 0x7F) << 8) + data[3]) / 10.0;
        if (data[2] & 0x80) temperature = -temperature; // Negative temperature
        return true;
    } 
    else 
    {
        return false;
    }
}

// Get the last temperature reading
float DHT22::getTemperature() const 
{
    return temperature;
}

// Get the last humidity reading
float DHT22::getHumidity() const 
{
    return humidity;
}
