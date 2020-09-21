int ledR = 9;
int ledG = 10;
int ledB = 11;

void setup() {
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
}

void loop() {
  setColor(255, 0, 0);
  delay(1000);
  
  setColor(0, 255, 0);
  delay(1000);

  setColor(0, 0, 255);
  delay(1000);

  setColor(255, 255, 0);
  delay(1000);

  setColor(0, 255, 255);
  delay(1000);

  setColor(139, 69, 19);
  delay(1000);

  setColor(255, 255, 255);
  delay(1000);
}

void setColor(int red, int green, int blue){
  analogWrite(ledR, red);
  analogWrite(ledG, green);
  analogWrite(ledB, blue);  
}
