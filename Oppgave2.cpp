#include <Arduino.h>

// Setup pins
const int ledPin = 32;

// Set delay time between changing light
const int delayTime = 500;

void setup() {
  // Open serial
  Serial.begin(9600);

  // Setup pin
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Print a short message
  Serial.println("Hello World!");

  // Turn light on and off
  digitalWrite(ledPin, HIGH);
  delay(delayTime);
  digitalWrite(ledPin, LOW);
  delay(delayTime);
}