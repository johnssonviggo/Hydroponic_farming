/*
 * This Arduino UNO R4 code was developed by newbiely.com
 *
 * This Arduino UNO R4 code is made available for public use without any restriction
 *
 * For comprehensive instructions and wiring diagrams, please visit:
 * https://newbiely.com/tutorials/arduino-uno-r4/arduino-uno-r4-dht11
 */

#include <DHT.h>
#define DHT11_PIN 2 // The Arduino UNO R4 pin connected to DHT11

DHT dht11(DHT11_PIN, DHT11);

void setup() {
  Serial.begin(9600);
  dht11.begin(); // initialize the sensor
}

void loop() {
  // wait a few seconds between measurements.
  delay(3000);

  // read humidity
  float humidity  = dht11.readHumidity();
  // read temperature as Celsius
  float tempC = dht11.readTemperature();
  // read temperature as Fahrenheit
  float tempF = dht11.readTemperature(true);

  // check if any reads failed
  if (isnan(humidity) || isnan(tempC) || isnan(tempF)) {
    Serial.println("Failed to read from DHT11 sensor!");
  } else {
    Serial.print("DHT11# Humidity: ");
    Serial.print(humidity);
    Serial.print("%");

    Serial.print("  |  "); 

    Serial.print("Temperature: ");
    Serial.print(tempC);
    Serial.print("°C ~ ");
    Serial.print(tempF);
    Serial.println("°F");
  }
}