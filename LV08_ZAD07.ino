void setup() {
  DDRD = B11111111;  // postavlja pinove 0-7 kao izlazne
  DDRB = B11111111;  // postavlja pinove 8-13 kao izlazne
  DDRC = B00000000;  // postavlja pinove A0-A5 kao ulazne
}

void loop() {
  int AD_value = analogRead(A0);
  int nDelay = map(AD_value, 0, 1023, 10, 250);
  
  // slovo P - 1. segment
  PORTD = 0b01110011;  // 0b DP,G,F,E,D,C,B,A
                       // odabiremo elemente jednog segmenta
  PORTB = 0b00001110;  // odabiremo segment (0bxxxx1110)
  delay(nDelay);
  
  // svi elementi u stanju 0
  PORTD = 0b00000000;
  PORTB = 0b00000000;


  // slovo U - 2. segment
  PORTD = 0b00111110;
  PORTB = 0b00001101;
  delay(nDelay);
  
  // svi elementi u stanju 0
  PORTD = 0b00000000;
  PORTB = 0b00000000;
  
  
  // slovo L - 3. segment
  PORTD = 0b00111000;
  PORTB = 0b00001011;
  delay(nDelay);
  
  // svi elementi u stanju 0
  PORTD = 0b00000000;
  PORTB = 0b00000000;
  
  
  // slovo A - 4. segment
  PORTD = 0b01110111;
  PORTB = 0b00000111;
  delay(nDelay);

  // svi elementi u stanju 0
  PORTD = 0b00000000;
  PORTB = 0b00000000;
}
