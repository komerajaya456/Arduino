#include <SoftwareSerial.h>

// Define the pins for SoftwareSerial
const int rxPin = 10; // Receive pin
const int txPin = 11; // Transmit pin

// Create a SoftwareSerial object
SoftwareSerial bluetooth(rxPin, txPin);

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);

  // Initialize SoftwareSerial for communication with Bluetooth module
  bluetooth.begin(9600);
 
}

void loop() {

  if (bluetooth.available()) {
    // Read the incoming byte from Bluetooth
    int receivedChar = bluetooth.read();
    
    
  Serial.print("received char:");
  
  Serial.println(receivedChar);
 
   
  }
}

