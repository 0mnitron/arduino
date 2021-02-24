int nDelay = 500;

void setup() {
  DDRD = B11111111;  // postavlja pinove 0-7 kao izlazne
  DDRB = B11111111;  // postavlja pinove 8-13 kao izlazne
}

void loop() {
  // slovo P - 1. segment
  digitalWrite(0,1);
  digitalWrite(1,1);
  digitalWrite(2,0);
  digitalWrite(3,0);
  digitalWrite(4,1);
  digitalWrite(5,1);
  digitalWrite(6,1);
  digitalWrite(7,0);
  
  digitalWrite(8,0);
  digitalWrite(9,1);
  digitalWrite(10,1);
  digitalWrite(11,1);
  delay(nDelay);


  digitalWrite(0,0);
  digitalWrite(1,0);
  digitalWrite(2,0);
  digitalWrite(3,0);
  digitalWrite(4,0);
  digitalWrite(5,0);
  digitalWrite(6,0);
  digitalWrite(7,0);
  
  digitalWrite(8,0);
  digitalWrite(9,0);
  digitalWrite(10,0);
  digitalWrite(11,0);


  // slovo U - 2. segment  
  digitalWrite(0,0);
  digitalWrite(1,1);
  digitalWrite(2,1);
  digitalWrite(3,1);
  digitalWrite(4,1);
  digitalWrite(5,1);
  digitalWrite(6,0);
  digitalWrite(7,0);
  
  digitalWrite(8,1);
  digitalWrite(9,0);
  digitalWrite(10,1);
  digitalWrite(11,1);
  delay(nDelay);


  digitalWrite(0,0);
  digitalWrite(1,0);
  digitalWrite(2,0);
  digitalWrite(3,0);
  digitalWrite(4,0);
  digitalWrite(5,0);
  digitalWrite(6,0);
  digitalWrite(7,0);
  digitalWrite(8,0);
  digitalWrite(9,0);
  digitalWrite(10,0);
  digitalWrite(11,0);
}
