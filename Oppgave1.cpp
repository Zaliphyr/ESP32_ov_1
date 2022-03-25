#include <Arduino.h>
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Hello World!");
  delay(1000);
}
/* 
 *  Hva er de sentrale forskjellene mellom en ESP32 og en Arduino Uno? Fordeler/ulemper?
 *  
 *   Hva er maks CPU-frekvens for ESP32 og hva er lavest anbefalte frekvens for WiFi bruk?
 *   
 *   Hva gjør «Upload Speed», som standard er satt til «921600» (test det gjerne ut)?
 *   
 *   Har «Port»/COMPORT et navn? Utenom «COM» etterfulgt av et tall? Har en Arduino Uno det? Hvorfor kan dette være viktig å være oppmerksom på?
 *   
 *   
 */