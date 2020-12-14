// LCD
// Vcc = 5V
// SDA = A4
// SCL = A5

// potenciometar
// 1-5V 2-A0  3-GND


#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // ili 0x3F

int pin_SW_A = 2;
int pin_SW_B = 13;
int pin_SW_C = 4;

int pin_ledY = 10;
int pin_led_Y = 9;

int pin_led_A = 5;
int pin_led_B = 6;
int pin_led_C = 11;

int button_A, button_B, button_C;

int pin_pot = A0;
int AD_value = 0;

void setup() {
  lcd.begin();
  lcd.backlight();
  
  pinMode(pin_SW_A, INPUT_PULLUP);
  pinMode(pin_SW_B, INPUT_PULLUP);
  pinMode(pin_SW_C, INPUT_PULLUP);
  
  pinMode(pin_led_A, OUTPUT);
  pinMode(pin_led_B, OUTPUT);
  pinMode(pin_led_C, OUTPUT);
  
  pinMode(pin_ledY, OUTPUT);
  pinMode(pin_led_Y, OUTPUT);

  pinMode(pin_pot, INPUT);
}

void loop() {
  button_A = digitalRead(pin_SW_A);
  button_B = digitalRead(pin_SW_B);
  button_C = digitalRead(pin_SW_C);

  AD_value = analogRead(pin_pot);
  int nBright = map(AD_value, 0, 1023, 0, 255);
  
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
    analogWrite(pin_led_A, nBright);
  }
  else{
    digitalWrite(pin_led_A, LOW);
  }

  if(button_B == 0){
    analogWrite(pin_led_B, nBright);
  }
  else{
    digitalWrite(pin_led_B, LOW);
  }

  if(button_C == 0){
    analogWrite(pin_led_C, nBright);
  }
  else{
    digitalWrite(pin_led_C, LOW);
  }

  
  if(button_A==0 && button_B==0 && button_C==0){
    lcd.setCursor(11, 1);
    lcd.print("1");
    lcd.setCursor(15, 1);
    lcd.print("0");
    
    analogWrite(pin_ledY, nBright);
    digitalWrite(pin_led_Y, LOW);  
  }
  else{
    lcd.setCursor(11, 1);
    lcd.print("0");
    lcd.setCursor(15, 1);
    lcd.print("1");
    
    digitalWrite(pin_ledY, LOW);
    analogWrite(pin_led_Y, nBright);
  }
  delay(300);
}
