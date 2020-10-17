int pin_pot1 = A0;
int pin_pot2 = A1;
int pin_led = 5;
int pin_SW = 7;
int pin_piezo = 6;

int AD_value1 = 0;
int AD_value2 = 0;

void setup() {
  pinMode(pin_pot1, INPUT);
  pinMode(pin_pot2, INPUT);
  pinMode(pin_led, OUTPUT);
  pinMode(pin_SW, INPUT_PULLUP);
  pinMode(pin_piezo, OUTPUT);
}

void loop() {
  AD_value1 = analogRead(pin_pot1); //vrijednost 1. potenciometra
  AD_value2 = analogRead(pin_pot2); //vrijednost 2. potenciometra
  
  int nBright = map(AD_value1, 0, 1023, 0, 255); //vrijednost (0-1023) pretvaramo u (0-255)
  int nFrequency = map(AD_value2, 0, 1023, 750, 2000); //vrijednost (0-1023) pretvaramo u (750-2000)

  if(nFrequency > 1500){ //ako je frekvencija veća od 1500 Hz
    analogWrite(pin_led, nBright);
  }
  else{
    analogWrite(pin_led, 0);
  }
  
  if(digitalRead(pin_SW) == LOW){    //ako je sklopka uključena
    tone(pin_piezo, nFrequency);
  }
  else{
    noTone(pin_piezo);  
  }
  
}
