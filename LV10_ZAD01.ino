#include <Keypad.h> // Dodavanje Keypad.h biblioteke
const byte ROWS = 4; // Definiranje broja redaka tipkovnice
const byte COLS = 4; // Definiranje broja stupaca tipkovnice
char keys[ROWS][COLS] = { // U dvodimenzionalno polje definirati
  { '1','2','3','A' }, // oznaku svake tipke
  { '4','5','6','B' },
  { '7','8','9','C' },
  { '*','0','#','D' },
};

byte rowPins[ROWS] = { 13, 12, 11, 10 }; // Definiramo pinove na koji
                     
byte colPins[COLS] = { 9, 8, 7, 6 }; // Definiramo pinove na koji
                  
//Kreiranje tipkovnice
Keypad kpd = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);


void setup(){
  Serial.begin(9600);
}

void loop(){
  char key = kpd.getKey();  // Očitanje pritisnute tipke
  if (key){  // Ako je registrirana pritisnuta tipka ispiši njenu vrijednost
    Serial.println(key);
  }
}
