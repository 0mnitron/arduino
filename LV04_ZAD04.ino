#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  
                                     
void setup() {
  lcd.begin();  
}

void loop() {
  lcd.backlight();
  
  lcd.setCursor(0, 0);
  lcd.print("Hello World");
  lcd.setCursor(0, 1);
  lcd.print("Hello World");
  
  delay(1000);
  
  //lcd.noBacklight();   isključivanje pozadinskog osvjetljenja LCD-a
  
  lcd.clear();
  delay(1000);
}
