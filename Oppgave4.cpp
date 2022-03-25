#include <Arduino.h>

// Setup pins
const int ledPin = 32;
const int buzPin = 33;
const int servoPin = 25;

// Setup values
int ledPower = 0;
int buzzfreq = 600;
int servoAngle = 500;

// Setup for timer
unsigned long lastTime = 0;

void setup() {
  // Start all IO needed
  pinMode(servoPin, OUTPUT);

  ledcSetup(0, 8000, 8);
  ledcAttachPin(ledPin, 0);

  ledcSetup(1, 8000, 8);
  ledcAttachPin(buzPin, 1);
}

void loop() {
  // Make loop run only every 20ms
  if (millis()-20 >= lastTime){
    
    // Update timer
    lastTime = millis();

    // Update servo position
    digitalWrite(servoPin, HIGH);
    delayMicroseconds(servoAngle);
    digitalWrite(servoPin, LOW);

    // Update led
    ledcWrite(0, ledPower);

    // Update buzzer
    ledcWriteTone(1, buzzfreq);

    // Reset values if they hit limit
    servoAngle += 10;
    if (servoAngle > 2500){
      servoAngle = 500;
    }

    buzzfreq += 5;
    if (buzzfreq > 1200){
      buzzfreq = 600;
    }

    ledPower += 1;
    if (ledPower > 255){
      ledPower = 0;
    }
  }
}
