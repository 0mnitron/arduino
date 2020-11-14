#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int pin_pot = A0;
int AD_value = 0;

// kreiranje simbola baterije
uint8_t battery1[8] = { 0x0E, 0x1B, 0x11, 0x11, 0x11, 0x11, 0x11, 0x1F };
uint8_t battery2[8] = { 0x0E, 0x1B, 0x11, 0x11, 0x11, 0x11, 0x1F, 0x1F };
uint8_t battery3[8] = { 0x0E, 0x1B, 0x11, 0x11, 0x11, 0x1F, 0x1F, 0x1F };
uint8_t battery4[8] = { 0x0E, 0x1B, 0x11, 0x11, 0x1F, 0x1F, 0x1F, 0x1F };
uint8_t battery5[8] = { 0x0E, 0x1B, 0x11, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F };
uint8_t battery6[8] = { 0x0E, 0x1B, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F };
uint8_t battery7[8] = { 0x0E, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F };

LiquidCrystal_I2C lcd(0x27, 16, 2);  
                                     
void setup() {  
  pinMode(pin_pot, INPUT);
   
  lcd.begin();
  lcd.backlight();
  
  lcd.createChar(1, battery1);
  lcd.createChar(2, battery2);
  lcd.createChar(3, battery3);
  lcd.createChar(4, battery4);
  lcd.createChar(5, battery5);
  lcd.createChar(6, battery6);
  lcd.createChar(7, battery7);
  lcd.home();  
}

void loop() {
  AD_value = analogRead(pin_pot);
  
  int nVoltage1 = map(AD_value, 0, 1023, 0, 500);  // razina "napona" od 0.00 do 5.00v
  float nVoltage2 = (float)nVoltage1/100;
  
  int nBattery = map(AD_value, 0, 1023, 0, 7);  // koliko simbola baterije treba iscrtati na ekranu
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("A/D:");
  lcd.print(AD_value);

  // ispis razine "napona" na ekran
  lcd.setCursor(9, 0);
  lcd.print("U=");
  lcd.print(nVoltage2);
  lcd.print("V");

  lcd.setCursor(0, 1);
  lcd.print("BATTERY");
  
  // ispis simbola baterije na ekran
  lcd.setCursor(9, 1);
  for(int i=1; i<=nBattery; i++){
    lcd.write(i);
  }

  delay(300);
}
