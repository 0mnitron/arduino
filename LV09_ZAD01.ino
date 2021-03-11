int PIN_motor = 3;
int SW1 = 9;

void setup() {
  pinMode(SW1, INPUT_PULLUP);
  pinMode(PIN_motor, OUTPUT);
}

void loop() {
  if(digitalRead(SW1) == 0){
    digitalWrite(PIN_motor, HIGH);
  }
  else{
    digitalWrite(PIN_motor, LOW);  
  }
}
