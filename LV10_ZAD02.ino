#include <Keypad.h> 
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const byte ROWS = 4; 
const byte COLS = 4; 
char keys[ROWS][COLS] = { 
  { '1','2','3','A' }, 
  { '4','5','6','B' },
  { '7','8','9','C' },
  { '*','0','#','D' },
};

byte rowPins[ROWS] = { 13, 12, 11, 10 }; 
                     
byte colPins[COLS] = { 9, 8, 7, 6 }; 

char kombinacija[] = { '1','2','3','A' };

char kombinacija1[sizeof(kombinacija) / sizeof(char)];
int i = 0, j = 0;

Keypad kpd = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

int n=0;

void setup(){
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
}

void loop(){
  char key = kpd.getKey();  
  lcd.setCursor(0,0);
  lcd.print("Unesite pin:");
  
  if (key){ 
    Serial.println(key);
    if(n < 4){
      n++;
      lcd.setCursor(11+n,0);
      lcd.print("*");
    }
    if(n == 4){
      n = 0;
      delay(300);
      lcd.clear();
    }
    
    kombinacija1[i] = key;
    if(kombinacija[i] == kombinacija1[i]){
      i++;
      j++;
      if(j == sizeof(kombinacija)/sizeof(char)){
        Serial.println("Vrata Otkljucana!");
        i = 0;
        j = 0;
      }
    }
    else{
      i = 0;
      j = 0;
    }
  }
}
