// tinkercad 
// https://www.tinkercad.com/things/15vFtFm4dPg

#include <LiquidCrystal.h>

int pin_SW_A = 6;
int pin_SW_B = 7;
int pin_SW_C = 8;

int pin_ledY = 9;
int pin_led_Y = 10;

int pin_led_A = 13;
int pin_led_B = 1;
int pin_led_C = 0;

int button_A, button_B, button_C;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  pinMode(pin_SW_A, INPUT_PULLUP);
  pinMode(pin_SW_B, INPUT_PULLUP);
  pinMode(pin_SW_C, INPUT_PULLUP);
  
  pinMode(pin_led_A, OUTPUT);
  pinMode(pin_led_B, OUTPUT);
  pinMode(pin_led_C, OUTPUT);
  
  pinMode(pin_ledY, OUTPUT);
  pinMode(pin_led_Y, OUTPUT);
}

void loop() {
  button_A = digitalRead(pin_SW_A);
  button_B = digitalRead(pin_SW_B);
  button_C = digitalRead(pin_SW_C);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("A");
  lcd.setCursor(3, 0);
  lcd.print("B");
  lcd.setCursor(6, 0);
  lcd.print("C");
  lcd.setCursor(11, 0);
  lcd.print("Y");
  lcd.setCursor(14, 0);
  lcd.print("-Y");
  
  lcd.setCursor(0, 1);
  lcd.print(!button_A);
  lcd.setCursor(3, 1);
  lcd.print(!button_B);
  lcd.setCursor(6, 1);
  lcd.print(!button_C);
  

  if(button_A == 0){
    digitalWrite(pin_led_A, HIGH);
  }
  else{
    digitalWrite(pin_led_A, LOW);
  }

  if(button_B == 0){
    digitalWrite(pin_led_B, HIGH);
  }
  else{
    digitalWrite(pin_led_B, LOW);
  }

  if(button_C == 0){
    digitalWrite(pin_led_C, HIGH);
  }
  else{
    digitalWrite(pin_led_C, LOW);
  }

  
  if(button_A==0 && button_B==0 && button_C==0){
    lcd.setCursor(11, 1);
    lcd.print("1");
    lcd.setCursor(15, 1);
    lcd.print("0");
    
    digitalWrite(pin_ledY, HIGH);
    digitalWrite(pin_led_Y, LOW);  
  }
  else{
    lcd.setCursor(11, 1);
    lcd.print("0");
    lcd.setCursor(15, 1);
    lcd.print("1");
    
    digitalWrite(pin_ledY, LOW);
    digitalWrite(pin_led_Y, HIGH);
  }
  delay(300);
}
