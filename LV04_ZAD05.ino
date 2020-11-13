#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  
                                     
void setup() {
  int br = 1023;
  
  lcd.begin();
  lcd.backlight(); 
  
  lcd.setCursor(0, 0);
  lcd.print(br, BIN);  // ispisivanje broja u binarnom obliku

  lcd.setCursor(0, 1);
  lcd.print(br, HEX);  // ispisivanje broja u heksadekadskom obliku
}

void loop() {

}
