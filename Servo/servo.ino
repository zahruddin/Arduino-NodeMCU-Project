#define servopin 2
#include <Servo.h>
 Servo servo;
void setup() {
  // put your setup code here, to run once:
 
  servo.attach(servopin);
  servo.write(0);
  delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  servo.write(90);
  delay(3000);
  servo.write(180);
}
