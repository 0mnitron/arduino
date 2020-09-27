int pin_SW1 = 8;
int pin_SW2 = 7;

int led = 3;

int button1 = 0;
int button2 = 0;
int svjetlina = 0;

void setup() {
  pinMode(pin_SW1, INPUT_PULLUP);
  pinMode(pin_SW2, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop() {
  button1 = digitalRead(pin_SW1);
  button2 = digitalRead(pin_SW2);

  if(button1 != 1 && svjetlina<245){
    svjetlina = svjetlina + 10;
    delay(200);
  }
  if(button2 != 1 && svjetlina >=10){
    svjetlina = svjetlina - 10;
    delay(200);
  }
  
  analogWrite(led, svjetlina);
}
