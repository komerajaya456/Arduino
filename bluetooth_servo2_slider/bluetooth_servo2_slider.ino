#include <SoftwareSerial.h>
#include <Servo.h>

Servo servo1;  // Create a Servo object for the first servo
Servo servo2;  // Create a Servo object for the second servo

// Define the pins for SoftwareSerial
const int rxPin = 10; // Receive pin
const int txPin = 11; // Transmit pin
int n = 0;

char text[20];  // Buffer to hold received characters

// Create a SoftwareSerial object
SoftwareSerial bluetooth(rxPin, txPin);

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);

  // Initialize SoftwareSerial for communication with Bluetooth module
  bluetooth.begin(9600);

  // servo1.attach(5);
  // servo2.attach(6);


  pinMode(3,OUTPUT);
  // Send a message to indicate readiness
  Serial.println("Bluetooth Slider Control");
}

void loop() {
  if (bluetooth.available()) {
    // Read the incoming byte from Bluetooth
    char receivedChar = bluetooth.read();
    Serial.print("Received: ");
    Serial.println(receivedChar);

    if (receivedChar == '/') {
      Serial.println("inside SLIDER");
      servo1.detach();
      servo2.detach();

      // Convert the accumulated text to a float
      float value = atof(text);
      if (value > 255) {
        value = 255;  // Limit the value to 1023 if higher
      }

      Serial.print("Value: ");
      Serial.println(value);
      analogWrite(3,value);
     
      n = 0;  // Reset index
      memset(text, 0, sizeof(text));  // Clear the text buffer
    }
    else if (receivedChar == '*') {
      Serial.print("inside SERVO :");
      
    
      servo1.attach(5);
      servo2.attach(6);

      // Convert the accumulated text to a float
      float value = atof(text);
      if (value > 90) {
        value = 90;  // Limit the value to 90 if higher
      }

      Serial.print("Value: ");
      Serial.println(value);

      servo1.write(value);
      servo2.write(value);
      delay(3000);  // Wait for servo to complete movement

      // Reset servo positions
      servo1.write(0);
      servo2.write(0);

      // Send "D" signal to indicate completion
      bluetooth.write("D");

      n = 0;  // Reset index
      memset(text, 0, sizeof(text));  // Clear the text buffer
    }
    else {
      text[n] = receivedChar;  // Store character in text buffer
      n = n + 1;
    }
  }
}