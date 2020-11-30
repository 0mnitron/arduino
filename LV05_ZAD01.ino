int pin_SW_A = 2;
int pin_SW_B = 3;
int pin_SW_C = 4;

int pin_ledY = 8;
int pin_led_Y = 9;

int button_A, button_B, button_C;

void setup() {
  pinMode(pin_SW_A, INPUT_PULLUP);
  pinMode(pin_SW_B, INPUT_PULLUP);
  pinMode(pin_SW_C, INPUT_PULLUP);
  pinMode(pin_ledY, OUTPUT);
  pinMode(pin_led_Y, OUTPUT);
}

void loop() {
  button_A = digitalRead(pin_SW_A);  // tipka pritisnuta -> button = 0
  button_B = digitalRead(pin_SW_B);
  button_C = digitalRead(pin_SW_C);

  if(button_A==0 && button_B==0 && button_C==0){
    digitalWrite(pin_ledY, HIGH);
    digitalWrite(pin_led_Y, LOW);  
  }
  else{
    digitalWrite(pin_ledY, LOW);
    digitalWrite(pin_led_Y, HIGH);
  }
}
