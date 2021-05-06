// Ultrazvučni senzor HC-SR04 postavljen da mjeri razinu u spremniku
// Vcc = 5V

#include <Wire.h>
#include<LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define TANKSIZE 15  // dubina spremnika = 15 centimetara
#define trigPin 8
#define echoPin 7
long duration, cm;


void setup(){
  lcd.begin();
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);  
}


void loop(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(4);
  
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
 
  duration = pulseIn(echoPin, HIGH);
  cm = (duration/2)/29.1;
  delay(250);

  // LCD
  lcd.setCursor(0, 0);
  lcd.print("Razina: ");
  lcd.setCursor(0, 1);
  lcd.print(TANKSIZE-cm);
  lcd.print(" cm    ");
  
  delay(500);
}
