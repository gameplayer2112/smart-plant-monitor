#include <DHT.h>
#define DHTPIN 14     
#define DHTTYPE DHT11  
#define i_m_sensor 4
DHT dht(DHTPIN, DHTTYPE);
#define Screenwidth 128
#define screenheight 32
#define oledreset -1
#include<Wire.h>
#include<Adafruit_SSD1306.h>
Adafruit_SSD1306 display(Screenwidth,screenheight,&Wire,oledreset);

void setup() {
  // put your setup code here, to run once:
  dht.begin();
  Wire.begin(21,22);
  if (!display.begin(SSD1306_SWITCHCAPVCC,0x3C))
  {
    Serial.println("OLED not found .check wiring!");
    for(;;);
    }
}
    
  
void loop() {
  // put your main code here, to run repeatedly:
  sensors();

}
void sensors()
{
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10,0);
  delayMicroseconds(2);
  int sense_it=analogRead(i_m_sensor);
  float humidity=dht.readHumidity();
  float temperature=dht.readTemperature();
  if(isnan(humidity) || isnan(temperature))
  {
    display.clearDisplay();
    display.println("dht sensor not working");
    display.display();
  }
  else
  {
    display.clearDisplay();
    display.print("humidity:");
    display.println(humidity);
    display.print("temp:");
    display.println(temperature);
    display.print("soil moisture:");
     display.println(sense_it);   
    display.display();
  }
  delay(2000);
}
