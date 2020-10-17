int pin_pot = A0;
int pin_led = 5;
int pin_SW = 7;
int pin_piezo = 6;

int AD_value = 0;

void setup() {
  pinMode(pin_pot, INPUT);
  pinMode(pin_led, OUTPUT);
  pinMode(pin_SW, INPUT_PULLUP);
  pinMode(pin_piezo, OUTPUT);
}

void loop() {
  AD_value = analogRead(pin_pot);  //analognu vrijednost potenciometra stavljamo u varijablu AD_value
  
  int nBright = map(AD_value, 0, 1023, 0, 255); //vrijednost (0-1023) pretvaramo u (0-255)

  if(digitalRead(pin_SW) == LOW){    //ako je sklopka uključena
    analogWrite(pin_led, nBright);
    tone(pin_piezo, 175);      //palimo zujalicu s frekvencijom 175 HZ, bez vremenskog ograničenja
  }
  else{
    analogWrite(pin_led, 0);
    noTone(pin_piezo);  
  }
  
}
