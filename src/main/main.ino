#include "DHT.h"
#include <LiquidCrystal_I2C.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27 and 16x2 display

void setup() {
  dht.begin();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Starting DHT");
}

void loop() {
  lcd.clear();
  float humidity = dht.readHumidity();
  float temp = dht.readTemperature();
  if(isnan(humidity) || isnan(temp)) {
    lcd.setCursor(0,0);
    lcd.print("Measurement fail");
    return;
  }
  lcd.setCursor(0, 0);
  lcd.print("Humidity: ");
  lcd.setCursor(10, 0);
  lcd.print(humidity);
  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.setCursor(6, 1);
  lcd.print(temp);
  // wait between measurements because we don't need to update very often
  delay(20000);
}
