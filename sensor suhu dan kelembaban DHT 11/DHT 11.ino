#include <LiquidCrystal_I2C.h>
#include <DFRobot_DHT11.h>
DFRobot_DHT11 DHT;
LiquidCrystal_I2C lcd(0x27,16,2);

#define DHT11_PIN 10
void setup(){
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
  
}
void loop(){
  DHT.read(DHT11_PIN);
  lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("suhu: "+ String(DHT.temperature));
   lcd.setCursor(0,1);
   lcd.print("kelembaban: " + String(DHT.humidity));
  delay(500);
}
