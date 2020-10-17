int pin_pot1 = A0;
int pin_pot2 = A1;

int pin_led[4] = {5,6,9,10};

int pin_SW = 7;

int AD_value1 = 0;
int AD_value2 = 0;

int i, n = 0;

void setup() {
  pinMode(pin_pot1, INPUT);
  pinMode(pin_pot2, INPUT);
  
  pinMode(pin_led[0], OUTPUT);
  pinMode(pin_led[1], OUTPUT);
  pinMode(pin_led[2], OUTPUT);
  pinMode(pin_led[3], OUTPUT);
  
  pinMode(pin_SW, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  AD_value1 = analogRead(pin_pot1); //vrijednost 1. potenciometra
  AD_value2 = analogRead(pin_pot2); //vrijednost 2. potenciometra
  
  float nVoltage = map(AD_value1, 0, 1023, 0, 5); //vrijednost (0-1023) pretvaramo u (0-5)
  int nBright = map(AD_value2, 0, 1023, 0, 255); //vrijednost (0-1023) pretvaramo u (0-255)

//Ispitujemo koliko dioda treba upaliti
  if(nVoltage >= 0.0 && nVoltage < 1.0){
    n = 0;  
  }
  else if(nVoltage >= 1.0 && nVoltage <2.0){
    n = 1;
  }
  else if(nVoltage >= 2.0 && nVoltage < 3.0){
    n = 2;
  }
  else if(nVoltage >= 3.0 && nVoltage < 4.0){
    n = 3;
  }
  else if(nVoltage >= 4.0 && nVoltage <= 5.0){
    n = 4;
  }

  if(digitalRead(pin_SW) == LOW){    //ako je sklopka uključena
    for(i=0; i<4; i++){
      digitalWrite(pin_led[i], HIGH);
    }
  }
  else{
    for(i=0; i<4; i++){
      digitalWrite(pin_led[i], LOW);
    }
    
    for(i=0; i<n; i++){
      analogWrite(pin_led[i], nBright);
    }
  }

  Serial.print("A/D vrijednost: \t");
  Serial.print(AD_value1);
  Serial.print("\t nBright = ");
  Serial.print(nBright);
  Serial.print("\t Sw: \t");
  Serial.print(digitalRead(pin_SW));
  Serial.print("\t nVoltage = ");
  Serial.print(nVoltage);
  Serial.print("\n");
  
}
