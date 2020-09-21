int ledR = 9;
int ledG = 10;
int ledB = 11;

void setup() {
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
}

void loop() {
  setColor(random(255), random(255), random(255));
  delay(1000);
}

void setColor(int red, int green, int blue){
  analogWrite(ledR, red);
  analogWrite(ledG, green);
  analogWrite(ledB, blue);  
}
