int pin_pot = A0;
int pin_led = 5;
int pin_SW = 7;

int AD_value = 0;
int button = 0;

void setup() {
  pinMode(pin_pot, INPUT);
  pinMode(pin_led, OUTPUT);
  pinMode(pin_SW, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  AD_value = analogRead(pin_pot);  //analognu vrijednost potenciometra stavljamo u varijablu AD_value
  button = digitalRead(pin_SW);  //očitavamo stanje na switchu (button==0 - sklopka spojena)
  
  int nBright = map(AD_value, 0, 1023, 0, 255); //vrijednost (0-1023) pretvaramo u (0-255)

  if(button != 1){    //ako je sklopka uključena
    analogWrite(pin_led, nBright);
  }
  else{
    analogWrite(pin_led, 0);  
  }
  
  Serial.print("A/D vrijednost: \t");
  Serial.print(AD_value);
  Serial.print("\t nBright = ");
  Serial.print(nBright);
  Serial.print("\t Sw: \t");
  Serial.print(button);
  Serial.print("\n");
}
