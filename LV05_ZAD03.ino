int pin_SW_A = 2;
int pin_SW_B = 3;
int pin_SW_C = 4;

int pin_ledY = 8;
int pin_led_Y = 9;

int pin_led_A = 5;
int pin_led_B = 6;
int pin_led_C = 7;

int button_A, button_B, button_C;

void setup() {
  pinMode(pin_SW_A, INPUT_PULLUP);
  pinMode(pin_SW_B, INPUT_PULLUP);
  pinMode(pin_SW_C, INPUT_PULLUP);
  
  pinMode(pin_led_A, OUTPUT);
  pinMode(pin_led_B, OUTPUT);
  pinMode(pin_led_C, OUTPUT);
  
  pinMode(pin_ledY, OUTPUT);
  pinMode(pin_led_Y, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  button_A = digitalRead(pin_SW_A);
  button_B = digitalRead(pin_SW_B);
  button_C = digitalRead(pin_SW_C);
  
  Serial.print("A=");
  Serial.print(!button_A);
  Serial.print("\t B=");
  Serial.print(!button_B);
  Serial.print("\t C=");
  Serial.print(!button_C);
  
  if(button_A == 0){
    digitalWrite(pin_led_A, HIGH);
  }
  else{
    digitalWrite(pin_led_A, LOW);
  }

  if(button_B == 0){
    digitalWrite(pin_led_B, HIGH);
  }
  else{
    digitalWrite(pin_led_B, LOW);
  }

  if(button_C == 0){
    digitalWrite(pin_led_C, HIGH);
  }
  else{
    digitalWrite(pin_led_C, LOW);
  }

  
  if(button_A==0 && button_B==0 && button_C==0){
    Serial.print("\t Y=1 \t -Y=0");
    digitalWrite(pin_ledY, HIGH);
    digitalWrite(pin_led_Y, LOW);  
  }
  else{
    Serial.print("\t Y=0 \t -Y=1");
    digitalWrite(pin_ledY, LOW);
    digitalWrite(pin_led_Y, HIGH);
  }
  Serial.print("\n");
  delay(200);
}
