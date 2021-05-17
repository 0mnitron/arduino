#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int pin_sw1= 2;
int pin_sw2 = 3;
int pin_LED = 8;
bool state = LOW;

volatile unsigned int counter = 0;

void setup() {
  pinMode(pin_sw1, INPUT_PULLUP);
  pinMode(pin_sw2, INPUT_PULLUP);
  pinMode(pin_LED, OUTPUT);
  
  attachInterrupt(digitalPinToInterrupt(pin_sw1), led_on, FALLING);
  attachInterrupt(digitalPinToInterrupt(pin_sw2), led_off, FALLING); 
  interrupts();
  
  lcd.begin();
  lcd.backlight();
}


void loop() {
  
  for(int i=0; i<=9; i++){
    lcd.setCursor(0, 1);
    lcd.print(i);
    lcd_and_led();
    delay(200);
  }  
  lcd.setCursor(8,0);
  lcd.print("Counter");
  lcd.setCursor(8,1);
  lcd.print(counter);
  lcd.print("  ");
}

void led_on(){
  state = HIGH;
  counter++;
}

void led_off(){
  state = LOW;
  (counter>0) ? counter-- : counter=counter;
  
}

void lcd_and_led(){ 
  digitalWrite(pin_LED, state);
  
  if(state){
    lcd.setCursor(0, 0);
    lcd.print("HIGH");
  }
  else{
    lcd.setCursor(0, 0);
    lcd.print("LOW ");
  }
}
