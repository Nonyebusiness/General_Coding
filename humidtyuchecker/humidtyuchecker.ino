#include "DHT.h"

#define DHTPIN 2

#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
Serial.println("Humidity and Temperature");

dht.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
delay(2000);

float h = dht.readHumidity();

float t = dht.readTemperature();

Serial.print("Humidity: ");
Serial.print(h);
Serial.print("% Temperature: ");
Serial.print(t);
Serial.println("°C");

}
