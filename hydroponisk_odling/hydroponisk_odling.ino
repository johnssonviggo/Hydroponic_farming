

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <dht11.h>
#define DHT11PIN 7

dht11 DHT11;


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET 4
//Adafruit_SH1106 display(OLED_RESET);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT);  

#define BLUE 0x001F



void setup() {


 // display.begin(SH1106_SWITCHCAPVCC, 0x3C);
   display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  
  delay(2000);
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
 //  display.setTextColor(BLUE);
}

void loop() {


  int chk = DHT11.read(DHT11PIN);

  float Humidity = DHT11.humidity;
  float temperature = DHT11.temperature;




  display.clearDisplay();

  // display temperature
  display.setTextSize(1);
  display.setCursor(0,7);
  //display.setTextColor(BLUE);
  display.print("Temperature: ");
  display.setTextSize(2);
  display.setCursor(0,16);
  display.print(temperature);
  display.print(" ");
  display.setTextSize(1);
  display.cp437(true);
  display.write(167);
  display.setTextSize(2);
  display.print("C");
  
  // display humidity
  display.setTextSize(1);
  display.setCursor(0, 37);
  display.print("Humidity: ");
  display.setTextSize(2);
  display.setCursor(0, 50);
  display.print(Humidity);
  display.print(" %"); 
  
  display.display(); 
}
