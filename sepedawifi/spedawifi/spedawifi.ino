#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include "index.h";

#ifndef APSSID
#define APSSID "Sepeda Astrea"
#define APPSK  "123123123"
#define LED D8  
#define RELAY1 D2
#define RELAY2 D3
#endif

/* Set these to your desired credentials. */
const char *ssid = APSSID;
const char *password = APPSK;

ESP8266WebServer server(80);

/* Just a little test message.  Go to http://192.168.4.1 in a web browser
   connected to this access point to see it.
*/
void handleRoot() {
 Serial.println("You called root page");
 String s = FPSTR(MAIN_PAGE); //Read HTML contents
 server.send(200, "text/html", s); //Send web page
}

void handleLEDon1() { 
  String s = FPSTR(MAIN_PAGE);
 Serial.println("LED on page");
 digitalWrite(LED,LOW); //LED is connected in reverse
 digitalWrite(RELAY1,LOW);
 server.send(200, "text/html", "Lampu 1 ON"); //Send ADC value only to client ajax request
// delay 20;
}

void handleLEDoff1() { 
  String s = FPSTR(MAIN_PAGE);
 Serial.println("LED off page");
 digitalWrite(LED,HIGH); //LED off
 digitalWrite(RELAY1,HIGH);
 server.send(200, "text/html", "Lampu 1 OFF"); //Send ADC value only to client ajax request
}

void handleLEDon2() { 
  String s = FPSTR(MAIN_PAGE);
 Serial.println("LED on page");
 digitalWrite(LED,LOW); //LED is connected in reverse
 digitalWrite(RELAY2,LOW);
 delay(2000);
 digitalWrite(RELAY2,HIGH);
 server.send(200, "text/html", "Lampu 2 ON"); //Send ADC value only to client ajax request
// delay 20;
}

void setup(void) {
   pinMode(LED,OUTPUT); 
  //Power on LED state off
  digitalWrite(LED,LOW);

  pinMode(RELAY1,OUTPUT);
  digitalWrite(RELAY1,HIGH);

  pinMode(RELAY2,OUTPUT);
  digitalWrite(RELAY2,HIGH);
  
  Serial.begin(115200);
  Serial.println();
  Serial.print("Configuring access point...");
  /* You can remove the password parameter if you want the AP to be open. */
  WiFi.softAP(ssid, password);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.on("/", handleRoot);
  server.on("/kuncion", handleLEDon1); //as Per  <a href="ledOn">, Subroutine to be called
  server.on("/kuncioff", handleLEDoff1);
  server.on("/start", handleLEDon2); 
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
