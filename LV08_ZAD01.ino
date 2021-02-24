int nDelay = 500;

void setup() {
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  

}

void loop() {
  // slovo P
  digitalWrite(0,1);  // A
  digitalWrite(1,1);  // B
  digitalWrite(2,0);  // C
  digitalWrite(3,0);  // D
  digitalWrite(4,1);  // E
  digitalWrite(5,1);  // F
  digitalWrite(6,1);  // G
  digitalWrite(7,0);  // DP
  
  // odabir segmenta
  digitalWrite(8,0);  // odabran prvi segment
  digitalWrite(9,1);
  digitalWrite(10,1);
  digitalWrite(11,1);
  delay(nDelay);
}
