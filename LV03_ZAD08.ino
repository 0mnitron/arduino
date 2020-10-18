int pin_pot = A0;
int pin_piezo = 5;
int pin_led = 6;
int pin_SW = 7;

int AD_value = 0;

int warning = 0;  // stanje zujalice, 1 - upaljenja, 0 - ugašena

// dozvoljava paljenje zujalice, 1 - dozvoljeno, 2 - nedozvoljeno
// svaka petlja restartira warning varijablu - potrebna nezavisna 
// varijabla koja dozvoljava/nedozvoljava zujanje
int toggle_warning = 1;  

void setup() {
  pinMode(pin_pot, INPUT);
  pinMode(pin_led, OUTPUT);
  pinMode(pin_piezo, OUTPUT);
  pinMode(pin_SW, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  AD_value = analogRead(pin_pot);  // vrijednost potenciometra
  
  int nTemperature = map(AD_value, 0, 1023, 0, 60);  // vrijednost (0-1023) pretvaramo u (0-60)
  delay(1000);
  Serial.print("\nTemperatura:\t");
  Serial.print(nTemperature);

  
  if(nTemperature > 40){
    warning = 1;

    digitalWrite(pin_led, HIGH);
    Serial.print("\tOpasnost!");
  }else{
    warning = 0;
    toggle_warning = 1;
    digitalWrite(pin_led, LOW);
  }

  if(digitalRead(pin_SW) == LOW){  // ako je sklopka uključena
    warning = 0;
    toggle_warning = 0;
  }

  if(warning && toggle_warning){  // warning == 1 ->True,    toggle_warning == 1 ->True
    tone(pin_piezo, 3000, 500);
  }else{
    tone(pin_piezo, 1000, 20);
  }
  
}
