int pin_pot = A0;
int AD_value = 0;

void setup() {
  pinMode(pin_pot, INPUT);
  Serial.begin(9600);
}

void loop() {
  AD_value = analogRead(pin_pot);  //analognu vrijednost potenciometra stavljamo u varijablu AD_value
  Serial.print("A/D vrijednost: \t");
  Serial.print(AD_value);
  Serial.print("\n");
}
