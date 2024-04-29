
// Define the pin where the LED is connected
const int ledPin = 13;

void setup() {
  // Set the LED pin as an output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Turn the LED on
  digitalWrite(ledPin, HIGH);
  // Wait for 1 second
  delay(1000);
  // Turn the LED off
  digitalWrite(ledPin, LOW);
  // Wait for another second
  delay(1000);
}
