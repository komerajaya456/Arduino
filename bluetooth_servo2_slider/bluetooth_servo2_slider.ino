#include <SoftwareSerial.h>

// Define the pins for SoftwareSerial
const int rxPin = 10; // Receive pin
const int txPin = 11; // Transmit pin

// Define pin for LED
const int ledPin = 12;

// Create a SoftwareSerial object
SoftwareSerial bluetooth(rxPin, txPin);

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);

  // Initialize SoftwareSerial for communication with Bluetooth module
  bluetooth.begin(9600);

  // Set the LED pin as an output
  pinMode(ledPin, OUTPUT);

  // Send a message to indicate readiness
  Serial.println("Bluetooth LED Control");
}

void loop() {
   
  // Check if data is available to read from Bluetooth
  if (bluetooth.available()) {
     Serial.println("Inside Bluetooth LED Control");
    // Read the incoming byte from Bluetooth
    char receivedChar = bluetooth.read();

    // Print the received byte for debugging
    Serial.println(receivedChar);

    // Check the received command
    if (receivedChar == '1') {
      // Turn on the LED
      digitalWrite(ledPin, HIGH);
      delay(1000);
        bluetooth.write('S'); // Send a single character, 'S', to indicate servo at 0 degrees
   
     
    } else if (receivedChar == '2') {
      // Turn off the LED
      digitalWrite(ledPin, LOW);
      bluetooth.println("LED turned off");
    }
  }
}
