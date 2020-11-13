#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// kreiranje simbola srce (♥)
uint8_t heart[8] = { 0x0, 0xa, 0x1f, 0x1f, 0xe, 0x4, 0x0 };

LiquidCrystal_I2C lcd(0x27, 16, 2);  
                                     
void setup() {  
  lcd.begin();
  lcd.backlight(); 
  lcd.setCursor(0, 0);

  lcd.createChar(1, heart);  // pozivanje simbola srce (♥)
  lcd.home(); 

  lcd.print("Mi");
  lcd.setCursor(3, 0);
  lcd.write(1);  // ispisivanje simbola srce (♥)

  lcd.setCursor(0, 1);
  lcd.print("Arduino");
}

void loop() {

}
