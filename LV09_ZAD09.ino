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
  if(digitalRead(pin_sw1)==0 && digitalRead(pin_sw2)==0){
    lcd.setCursor(0, 0);
    lcd.print("Resetting pos");
    pos = 90;
  }
  else if(!digitalRead(pin_sw1)){
    if(pos < 180 ){
      pos++;
      lcd.setCursor(0, 0);
      lcd.print("<--Moving Left");
    }
    if(pos == 180){
      lcd.setCursor(0, 0);
      lcd.print("Left limit");
    }
  }
  else if(!digitalRead(pin_sw2)){
    if(pos > 0){
      pos--;
      lcd.setCursor(0, 0);
      lcd.print("Moving Right-->");
    }
    if(pos == 0){
      lcd.setCursor(0, 0);
      lcd.print("Right limit");
    } 
  }
  
  if(pos == 90){
    lcd.setCursor(0, 0);
    lcd.print("Ready");
  }
  
  myservo.write(pos);
  lcd.setCursor(0, 1);
  lcd.print(pos);
  lcd.clear();
}
