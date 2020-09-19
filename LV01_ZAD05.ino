int ledR = 9;         //crvena (R)
int ledY = 10;        //žuta  (Y)
int ledG = 11;        //zelena  (G)

int delayR = 10000;
int delayY = 2000;
int delayG = 10000;

void setup() {
  pinMode(ledR, OUTPUT);
  pinMode(ledY, OUTPUT);
  pinMode(ledG, OUTPUT);
}

void loop() {
  digitalWrite(ledR, HIGH);
  delay(delayR);
  
  digitalWrite(ledY, HIGH);
  delay(delayY);

  digitalWrite(ledR, LOW);
  digitalWrite(ledY, LOW);

  digitalWrite(ledG, HIGH);
  delay(delayG);
  
  digitalWrite(ledG, LOW);
  digitalWrite(ledY, HIGH);
  delay(delayY);
  
  digitalWrite(ledY, LOW);
}
