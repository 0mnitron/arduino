#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int pin_sw1= 2;
int pin_sw2 = 3;
int pin_LED = 8;

void setup() {
  pinMode(pin_sw1, INPUT_PULLUP);
  pinMode(pin_sw2, INPUT_PULLUP);
  pinMode(pin_LED, OUTPUT);
  lcd.begin();
  lcd.backlight();
}

bool state = LOW;
bool on;

void loop() {
  if(digitalRead(pin_sw1) == 0){
    led_on();
    on = true;
  }
  if(digitalRead(pin_sw2) == 0){
    led_off();
    on = false;
  }
  digitalWrite(pin_LED, state);
  lcd.clear();
  if(on){
    lcd.setCursor(0, 0);
    lcd.print("HIGH");
  }else{
    lcd.setCursor(0, 0);
    lcd.print("LOW");
  }
}

void led_on(){
  state = HIGH;
}

void led_off(){
  state = LOW;
}
