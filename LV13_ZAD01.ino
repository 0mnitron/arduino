int pin_sw1= 2;
int pin_sw2 = 3;
int pin_LED = 8;

void setup() {
  pinMode(pin_sw1, INPUT_PULLUP);
  pinMode(pin_sw2, INPUT_PULLUP);
  pinMode(pin_LED, OUTPUT);
}

bool state = LOW;

void loop() {
  if(digitalRead(pin_sw1) == 0){
    led_on();
  }
  if(digitalRead(pin_sw2) == 0){
    led_off();
  }
  digitalWrite(pin_LED, state);
}

void led_on(){
  state = HIGH;
}

void led_off(){
  state = LOW;
}
