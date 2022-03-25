#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>

// Setup wifi information
const char* ssid = "xxx";
const char* pass = "xxx";

// Setup webserver
WebServer server(80);

// Setup pins
const int lightSensPin = 33;
const int potPin = 32;

// Predeclaring functions since i use cpp
void handle_root();
String makeHtml();

void setup() {
  Serial.begin(9600);
  Serial.println("Try connecting to ");
  Serial.println(ssid);

  // Start wifi
  WiFi.begin(ssid, pass);

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED){
    delay(1000);
    Serial.print(".");
  }

  // Print gotten IP
  Serial.println("");
  Serial.println("WIFI connected successfullt");
  Serial.print("Got IP: ");
  Serial.println(WiFi.localIP());

  // Setup what to return on client connection
  server.on("/", handle_root);

  server.begin();
  Serial.println("HTTP server started");
  delay(100);
}

void loop() {
  server.handleClient();
}

// Returns webpage with updated info
String makeHtml(){
  String HTMLdata =  "<!DOCTYPE html>"
              "<html>"
                "<head>"
                  "<title>Sensor display</title>"
                  "<meta http-equiv='refresh' content='0.5'>" // Makes it so it updates every 0.5s
                "</head>"
                "<body>"
                  "<h1>Sensordata:</h1>";
  
  // Input data from sensors in voltage
  HTMLdata += "<h2>Pot: ";
  HTMLdata += (analogRead(potPin)*3.3)/4095;
  HTMLdata += "</h2>";

  HTMLdata += "<h2>Light: ";
  HTMLdata += (analogRead(lightSensPin)*3.3)/4095;
  HTMLdata += "</h2>";

  HTMLdata +=   "</body>"
              "</html>";
  return HTMLdata;
}

// Function that sends data to client
void handle_root(){
  server.send(200, "text/html", makeHtml());
}
