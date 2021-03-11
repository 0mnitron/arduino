int PIN_motor = 3;
int SW1 = 9;
int SW2 = 10;
int nSpeed = 0;
int pin_pot = A0;

void setup() {
  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);
  pinMode(PIN_motor, OUTPUT);
  pinMode(pin_pot, INPUT);
}

void loop() {
  int AD_value = analogRead(pin_pot);
  nSpeed = map(AD_value, 0, 1023, 0, 255);
  
  if (digitalRead(SW1) == 0 && digitalRead(SW2) == 0){
     analogWrite(PIN_motor, nSpeed);
  }
  else{
      analogWrite(PIN_motor, 0);
  }
}
