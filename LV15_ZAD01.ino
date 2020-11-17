#include <DHT.h>

#define DHTTYPE DHT11
#define DHTPIN A0

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float t = dht.readTemperature();
  float h = dht.readHumidity();

  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.print("\t Vlaga: ");
  Serial.print(h);
  Serial.print("\n");

  delay(2000);
}
