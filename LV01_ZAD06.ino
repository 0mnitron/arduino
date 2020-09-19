int ledR = 9;         //crvena 

int i;

void setup() {
  pinMode(ledR, OUTPUT);
}

void loop() {
  for(i=0; i<255; i=i+32){
    analogWrite(ledR, i);
    delay(1000);
    if(i==224){
      analogWrite(ledR, 255);  
      delay(1000);
    }
  }
}
