int pin_pot1 = A0;
int pin_pot2 = A1;

int pin_led1 = 5;
int pin_led2 = 6;
int pin_led3 = 9;
int pin_led4 = 10;

int pin_SW = 7;

int AD_value1 = 0;
int AD_value2 = 0;

void setup() {
  pinMode(pin_pot1, INPUT);
  pinMode(pin_pot2, INPUT);
  
  pinMode(pin_led1, OUTPUT);
  pinMode(pin_led2, OUTPUT);
  pinMode(pin_led3, OUTPUT);
  pinMode(pin_led4, OUTPUT);
  
  pinMode(pin_SW, INPUT_PULLUP);
}

void loop() {
  AD_value1 = analogRead(pin_pot1); //vrijednost 1. potenciometra
  AD_value2 = analogRead(pin_pot2); //vrijednost 2. potenciometra
  
  int nDelay = map(AD_value1, 0, 1023, 100, 1000); //vrijednost (0-1023) pretvaramo u (100-1000)
  int nBright = map(AD_value2, 0, 1023, 0, 255); //vrijednost (0-1023) pretvaramo u (0-255)
  
  if(digitalRead(pin_SW) == HIGH){    //ako je sklopka isključena
    analogWrite(pin_led1, nBright);
    delay(nDelay);
    
    analogWrite(pin_led1, 0);
    analogWrite(pin_led2, nBright);
    delay(nDelay);

    analogWrite(pin_led2, 0);
    analogWrite(pin_led3, nBright);
    delay(nDelay);

    analogWrite(pin_led3, 0);
    analogWrite(pin_led4, nBright);
    delay(nDelay);

    analogWrite(pin_led4, 0);
  }
  else{
    analogWrite(pin_led4, nBright);
    delay(nDelay);

    analogWrite(pin_led4, 0);
    analogWrite(pin_led3, nBright);
    delay(nDelay);

    analogWrite(pin_led3, 0);
    analogWrite(pin_led2, nBright);
    delay(nDelay);

    analogWrite(pin_led2, 0);
    analogWrite(pin_led1, nBright);
    delay(nDelay);  

    analogWrite(pin_led1, 0);
  }
  
}
