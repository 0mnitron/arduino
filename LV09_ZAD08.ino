#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

Servo myservo;
int pin_pot=A0;
int pin_sw1 = 5;
int pin_sw2 = 6;
int pos = 0;  

void setup() {
  myservo.attach(3);
  pinMode(pin_pot, INPUT);
  pinMode(pin_sw1, INPUT_PULLUP);
  pinMode(pin_sw2, INPUT_PULLUP);
  lcd.begin();
  lcd.backlight();
}

void loop() {
  lcd.setCursor(0, 0);
  
  if(!digitalRead(pin_sw1)){
    if(pos < 180 ){
      pos++;
      lcd.print("<--Moving Left");
    }
  }
  else if(!digitalRead(pin_sw2)){
    if(pos > 0){
      pos--;
      lcd.setCursor(0, 0);
      lcd.print("Moving Right-->");
    }
  }
  else{
    lcd.print("Ready");
  }
  myservo.write(pos);
  lcd.clear();
}
