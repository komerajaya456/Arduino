#include <SoftwareSerial.h>

// Define the pins for SoftwareSerial
const int rxPin = 10; // Receive pin
const int txPin = 11; // Transmit pin
int n=0;
char text[20];
// Define pin for LED
// const int ledPin = 12;

// Create a SoftwareSerial object
SoftwareSerial bluetooth(rxPin, txPin);

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);

  // Initialize SoftwareSerial for communication with Bluetooth module
  bluetooth.begin(9600);

  // Set the LED pin as an output
  // pinMode(ledPin, OUTPUT);
 
  // Send a message to indicate readiness
  Serial.println("Bluetooth Slider Control");
}

void loop() {

  if (bluetooth.available()) {
    // Read the incoming byte from Bluetooth
    char receivedChar = bluetooth.read();
    
   
   
    if (receivedChar == '/') {
      Serial.println(text);
      float value = atof(text);
      Serial.println(value);
      
      n=0;}
    else{
      text[n]=receivedChar;
      n=n+1;}
   
  }
}

