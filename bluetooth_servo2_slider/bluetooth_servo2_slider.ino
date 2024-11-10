#include <SoftwareSerial.h>
#include <Servo.h>

Servo servo1;  // Create a Servo object for the first servo
Servo servo2;  // Create a Servo object for the second servo

Servo servo3;  // Create a Servo object for the first servo
Servo servo4;  // Create a Servo object for the second servo

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

  servo1.attach(5);
  servo2.attach(6);
  servo3.attach(3);
  servo4.attach(9);


  // Set the LED pin as an output
  // pinMode(ledPin, OUTPUT);
 
  // Send a message to indicate readiness
  Serial.println("Bluetooth Slider Control");
}

void loop() {

  if (bluetooth.available()) {
    // Read the incoming byte from Bluetooth
    char receivedChar = bluetooth.read();
      
   if ((receivedChar >= '0' && receivedChar <= '9') || receivedChar == '.' || receivedChar == '/') {
    
          servo1.detach();  
          servo2.detach();  
    if (receivedChar == '/') {
      Serial.println(text);
      float value = atof(text);
      if (value>1023){
        value=1023;
      }

      Serial.println(value);
      
      n=0;}
    else{
      text[n]=receivedChar;
      n=n+1;}
      }


  else if (receivedChar == 'S') {
        // Notify the app that servos are busy
      // bluetooth.write('P');  // Send 'p' for busy
      Serial.println("P sent");
      
      


      servo1.write(90);
      servo2.write(90);
      servo3.write(90);
      servo4.write(90);
      delay(3000);
      servo1.write(0);
      servo2.write(0);
      servo3.write(0);
      servo4.write(0);
      
    }


  }
}

