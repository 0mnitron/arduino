int PIN_motor = 3;
int SW1 = 9;
int SW2 = 10;
int nSpeed = 0;

void setup() {
  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);
  pinMode(PIN_motor, OUTPUT);
}

void loop() {
  if (digitalRead(SW1) == 0){
    (nSpeed<255) ? nSpeed++ : nSpeed = 255;
    delay(5);
  }

  if(digitalRead(SW2) == 0){
    (nSpeed>0) ? nSpeed-- : nSpeed = 0;
    delay(5);
  }

  analogWrite(PIN_motor, nSpeed);
}
