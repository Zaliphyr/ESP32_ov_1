#include <Arduino.h>
void setup() {
  Serial.begin(9600);

}

void loop() {
  Serial.println("Hello World!");
  delay(1000);
}
/* 
 *  Hva er de sentrale forskjellene mellom en ESP32 og en Arduino Uno? Fordeler/ulemper?
 *    - En esp32 har innebygd wifi og bluetooth, mer prosessorkraft, er billigere, raskere og bedre egnet til iot, men den er lettere å ødelegge
 *  
 *   Hva er maks CPU-frekvens for ESP32 og hva er lavest anbefalte frekvens for WiFi bruk?
 *    - 240 MHz er laveste, og laveste for WiFi er 80 MHz
 *   
 *   Hva gjør «Upload Speed», som standard er satt til «921600» (test det gjerne ut)?
 *    - Upload speed setter hvor stor hastighet man har når man overfører data fra pc til ESP
 *   
 *   Har «Port»/COMPORT et navn? Utenom «COM» etterfulgt av et tall? Har en Arduino Uno det? Hvorfor kan dette være viktig å være oppmerksom på?
 *    - Serial? Det er viktig å være oppmerksom på dette tallet da dette er nummeret som pc'n gir til usb porten som enheten er koblet på, å dette kan variere, og pass spesielt på hvis man har mer enn en enhet tilkoblet.
 *   
 */