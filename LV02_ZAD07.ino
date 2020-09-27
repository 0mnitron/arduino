int pin_SW1 = 8;
int pin_SW2 = 7;

int led[5]={2,3,4,5,6};

int button1 = 0;
int button2 = 0;

int nDelay = 200;
int i;

void setup() {
  pinMode(led[0], OUTPUT);
  pinMode(led[1], OUTPUT);
  pinMode(led[2], OUTPUT);
  pinMode(led[3], OUTPUT);
  pinMode(led[4], OUTPUT);
  
  pinMode(pin_SW1, INPUT_PULLUP);
  pinMode(pin_SW2, INPUT_PULLUP);
}

void loop() {
  button1 = digitalRead(pin_SW1);
  button2 = digitalRead(pin_SW2);

  if(button1==0 && button2==0){    //sve diode upaljene
    for(i=0; i<5; i++){
      digitalWrite(led[i], HIGH);
    }
  }
  
  else if(button1==0){           //diode se pale slijeva nadesno
    digitalWrite(led[2], LOW);  //gasimo središnju diodu (iz else slučaja)
    
    digitalWrite(led[0], HIGH);
    delay(nDelay);

    for(i=0; i<5; i++){
      digitalWrite(led[i], LOW);
      digitalWrite(led[i+1], HIGH);
      delay(nDelay);
    }
    digitalWrite(led[4], LOW);
  }
  
  else if(button2==0){           //diode se pale zdesna nalijevo
    digitalWrite(led[2], LOW);  //gasimo središnju diodu (iz else slučaja)
    
    digitalWrite(led[4], HIGH);
    delay(nDelay);

    for(i=4; i>=0; i--){
      digitalWrite(led[i], LOW);
      digitalWrite(led[i-1], HIGH);
      delay(nDelay);
    }
    digitalWrite(led[0], LOW);
  }
  
  else{
    digitalWrite(led[0], LOW);
    digitalWrite(led[1], LOW);
    digitalWrite(led[2], HIGH); // palimo središnju diodu
    digitalWrite(led[3], LOW);
    digitalWrite(led[4], LOW);
  }
}
