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

void loop() {
  for(int i=0; i<=9; i++){
    lcd.setCursor(0, 1);
    lcd.print(i);
    delay(2000);
  }
  
  if(digitalRead(pin_sw1) == 0){
    led_on();
  }
  if(digitalRead(pin_sw2) == 0){
    led_off();
  }
  
  digitalWrite(pin_LED, state);

  
  if(state){
    lcd.setCursor(0, 0);
    lcd.print("HIGH");
  }else{
    lcd.setCursor(0, 0);
    lcd.print("LOW ");
  }
}

void led_on(){
  state = HIGH;
}

void led_off(){
  state = LOW;
}
