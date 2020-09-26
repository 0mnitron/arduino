int pin_SW1 = 2;
int button1 = 0;

void setup() {
  //pinMode(pin_SW1, INPUT);         a-g
  pinMode(pin_SW1, INPUT_PULLUP);  //h
  Serial.begin(9600);
}

void loop() {
  button1 = digitalRead(pin_SW1);
  Serial.print("SW1: ");
  Serial.print("\t");
  Serial.print(button1);
  Serial.println("");
  delay(200);
}
