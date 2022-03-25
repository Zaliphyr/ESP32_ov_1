#include <Arduino.h>

const int ledPin = 32;
const int buzPin = 33;
const int servoPin = 25;

int ledPower = 0;
int buzzfreq = 600;
int servoAngle = 500;
unsigned long lastTime = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(servoPin, OUTPUT);

  ledcSetup(0, 8000, 8);
  ledcAttachPin(ledPin, 0);

  ledcSetup(1, 8000, 8);
  ledcAttachPin(buzPin, 1);
}

void loop() {
  if (millis()-20 >= lastTime){
    digitalWrite(servoPin, HIGH);
    delayMicroseconds(servoAngle);
    digitalWrite(servoPin, LOW);
    lastTime = millis();

    ledcWrite(0, ledPower);
    ledcWriteTone(1, buzzfreq);

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
