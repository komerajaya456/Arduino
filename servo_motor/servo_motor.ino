#include <Servo.h>

Servo myServo; // Create a Servo object to control the servo

void setup() {
  myServo.attach(9); // Attach the servo to pin 9
}

void loop() {
  myServo.write(0);   // Move to 0 degrees
  delay(1000);        // Wait for 1 second
  
  myServo.write(90);  // Move to 90 degrees
  delay(1000);        // Wait for 1 second
}
