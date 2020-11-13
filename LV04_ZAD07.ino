#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// kreiranje slova š i ć
uint8_t slovo1[8] = { 0xa,0x4,0xe,0x10,0xe,0x1,0x1e };
uint8_t slovo2[8] = { 0x2,0x4,0xe,0x10,0x10,0x11,0xe };

LiquidCrystal_I2C lcd(0x27, 16, 2);  
                                     
void setup() {  
  lcd.begin();
  lcd.backlight(); 
  lcd.setCursor(0, 0);

  lcd.createChar(1, slovo1);  // slovo š  
  lcd.createChar(2, slovo2);  // slovo ć
  lcd.home(); 

  lcd.write(1);
  lcd.print("areno li");
  lcd.write(1);
  lcd.write(2);
  lcd.print("e");  
}

void loop() {

}
