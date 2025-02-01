#include "DHT.h"

#define DHTPIN 3
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // init serial monitor of ide with speed
  Serial.begin(9600);
  Serial.println("Starting DHT measurements...");
  dht.begin();
}

void loop() {
  // wait between measurements because updates of DHT only occur after one second
  delay(2000);

  float humidity = dht.readHumidity();
  float temp = dht.readTemperature();
  if(isnan(humidity) || isnan(temp)) {
    Serial.println("Measurement failed!");
    return;
  }
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("%\tTemperature: ");
  Serial.print(temp);
  Serial.println("°C");
}
