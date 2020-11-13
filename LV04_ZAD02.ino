#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // definiranje I2C adrese LCD‐a (0x27)
                                     // i veličine LCD-a (16 znakova u 2 retka)
void setup() {
  lcd.begin();  // inicjijaliziranje LCD-a
  lcd.backlight();  // uključivanje pozadinskog osvjetljenja LCD‐a
  lcd.setCursor(0, 0);  // (stupac, redak)
  lcd.print("Hello World");
}

void loop() {
  // put your main code here, to run repeatedly:
}
