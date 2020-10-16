int pin_pot = A0;
int AD_value = 0;
int pin_led = 5;

void setup() {
  pinMode(pin_pot, INPUT);
  pinMode(pin_led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  AD_value = analogRead(pin_pot);  //analognu vrijednost potenciometra stavljamo u varijablu AD_value
  int nBright = map(AD_value, 0, 1023, 0, 255); //vrijednost (0-1023) pretvaramo u (0-255)
  analogWrite(pin_led, nBright);
  
  Serial.print("A/D vrijednost: \t");
  Serial.print(AD_value);
  Serial.print("\t nBright = ");
  Serial.print(nBright);
  Serial.print("\n");
}
