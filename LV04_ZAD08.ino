#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int pin_pot = A0;
int AD_value = 0;

LiquidCrystal_I2C lcd(0x27, 16, 2);  
                                     
void setup() {  
  pinMode(pin_pot, INPUT);
   
  lcd.begin();
  lcd.backlight();  
}

void loop() {
  AD_value = analogRead(pin_pot);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("A/D:");
  lcd.print(AD_value);
  delay(200);
}
