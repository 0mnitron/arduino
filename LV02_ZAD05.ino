int pin_SW1 = 8;
int pin_SW2 = 7;

int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;

int button1 = 0;
int button2 = 0;

int nDelay = 200;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  
  pinMode(pin_SW1, INPUT_PULLUP);
  pinMode(pin_SW2, INPUT_PULLUP);
}

void loop() {
  button1 = digitalRead(pin_SW1);
  button2 = digitalRead(pin_SW2);

  if(button1==0 || button2==0){
    digitalWrite(led1, HIGH);
    delay(nDelay);
    
    digitalWrite(led1, LOW); 
    digitalWrite(led2, HIGH);
    delay(nDelay);

    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    delay(nDelay);

    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
    delay(nDelay);

    digitalWrite(led4, LOW);
    digitalWrite(led5, HIGH);
    delay(nDelay);

    digitalWrite(led5, LOW);
  }
  else{
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
  }
}
