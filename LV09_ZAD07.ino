#include <Servo.h>
Servo myservo;
int pin_pot=A0;

void setup() {
  myservo.attach(3);
  pinMode(pin_pot, INPUT);
}

void loop() {
  int AD_value = analogRead(pin_pot);
  int nPosition = map(AD_value, 0, 1023, 0, 180); 
  myservo.write(nPosition);
}
