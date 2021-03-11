int PIN_motor = 3;

void setup() {
  pinMode(PIN_motor, OUTPUT);
}

void loop() {
  for(int i = 0; i < 255; i++){
    analogWrite(PIN_motor, i);
    delay(5);
  }
  
  for(int i = 255; i >= 0; i--){
    analogWrite(PIN_motor, i);
    delay(5);
  }
}
