// ---------------------------------------------------------------- //
// Arduino Ultrasoninc Sensor HC-SR04
// Re-writed by Arbi Abdul Jabbaar
// Using Arduino IDE 1.8.7
// Using HC-SR04 Module
// Tested on 17 September 2019
// ---------------------------------------------------------------- //
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>  

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);

#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04
#define relay 4

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
String meter;
void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0); 
  lcd.print("METERAN");
  
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  pinMode(relay, OUTPUT);//relay
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
//  delay(3000);
}
void loop() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  meter = String(distance);
  lcd.clear();
  lcd.setCursor(0, 0); 
  lcd.print("METERAN");
  lcd.setCursor(0,1);
  lcd.print(meter + " cm");
  Serial.println(" cm");
  
  if (distance > 10) digitalWrite(relay, HIGH);
  if (distance < 10) digitalWrite(relay, LOW);
  delay(100);
}
