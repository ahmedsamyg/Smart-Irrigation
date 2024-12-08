// Pin Definitions
const int moisturePin = 36; // ADC pin
const int ledPin = 2;       // LED pin

// Configurable Threshold
int moistureThreshold = 3000;  // Adjust based on your sensor's range

void setup() {
  Serial.begin(115200);  // Start Serial communication for UART (communication with Raspberry Pi)
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW); // Ensure LED starts OFF  
}

void loop() 
{
  // Average multiple readings to reduce noise
  int moistureValue = 0;
  int numReadings = 10;  // Number of readings to average
  for (int i = 0; i < numReadings; i++) {
    moistureValue += analogRead(moisturePin);
    delay(100);  // Short delay between readings
  }
  moistureValue /= numReadings;  // Average the readings
  Serial.println(moistureValue);
  
// Check if moisture value is below or above the threshold to toggle on-board led
if (moistureValue < moistureThreshold) {
  digitalWrite(ledPin, LOW);
} else {
  digitalWrite(ledPin, HIGH);
}
  delay(1000); // Delay for 1 second
}
