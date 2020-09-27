int pin_SW1 = 8;
int pin_SW2 = 7;
int led = 3;

int button1 = 0;
int button2 = 0;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(pin_SW1, INPUT_PULLUP);
  pinMode(pin_SW2, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  button1 = digitalRead(pin_SW1);
  button2 = digitalRead(pin_SW2);
  
  Serial.print("SW1: ");
  Serial.print("\t");
  Serial.print(button1);

  Serial.print("\t");
  
  Serial.print("SW2: ");
  Serial.print("\t");
  Serial.print(button2);

  Serial.print("\t");

  if(button1==0 || button2==0){
    digitalWrite(led, HIGH);
    Serial.print("Uvjet zadovoljen!"); 
  }
  else{
    digitalWrite(led, LOW);
    Serial.print("Uvjet nije zadovoljen!"); 
  }

  Serial.print("\n");
  delay(200);
}
