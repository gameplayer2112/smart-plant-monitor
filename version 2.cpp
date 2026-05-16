#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>
// ultrasonic sensor
#define Trigpin 5
#define echopin 18
#define buzzer 4

//OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

//DHT11
#define DHTPIN 13
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

//Soil Sensor
#define SOIL_PIN 34

//Relay
#define RELAY_PIN 15

// Threshold for dry soil
int threshold = 3000;

// Global variables
int soilValue;
float temperature;
float humidity;

// Function to read soil moisture
void readSoilMoisture()
{
soilValue = analogRead(SOIL_PIN);
Serial.print("Soil Moisture: ");
Serial.println(soilValue);
}
void ultrasonic()
{digitalWrite(Trigpin, LOW);
delayMicroseconds(2);
digitalWrite(Trigpin, HIGH);
delayMicroseconds(10); // Must be at least 10 microseconds
digitalWrite(Trigpin, LOW);
  long duration=pulseIn(echopin,HIGH);
  float distance=(duration * 0.0343) / 2;
  Serial.println(distance);
  if(distance>6)
  digitalWrite(buzzer,HIGH);
  delay(30);
  digitalWrite(buzzer,LOW);
  
}

// Function to read DHT11
void readDHTSensor() {

temperature = dht.readTemperature();
humidity = dht.readHumidity();

Serial.print("Temperature: ");
Serial.print(temperature);
Serial.println(" C");

Serial.print("Humidity: ");
Serial.print(humidity);
Serial.println("%");
}

// Function to control pump
void controlPump() {
if (soilValue > threshold)
{
digitalWrite(RELAY_PIN, LOW);   // Pump ON
Serial.println("Pump ON");
}
else
{
digitalWrite(RELAY_PIN, HIGH);  // Pump OFF
Serial.println("Pump OFF");
}
}

// Function to display data on OLED
void displayData() {
display.clearDisplay();

display.setTextSize(1);
display.setTextColor(WHITE);

display.setCursor(0,0);
display.print("Soil: ");
display.print(soilValue);

display.setCursor(0,20);
display.print("Temp: ");
display.print(temperature);
display.print(" C");

display.setCursor(0,40);
display.print("Humidity: ");
display.print(humidity);
display.print("%");

display.display();
}

// Setup
void setup() {
//Initialise Serial Print
Serial.begin(115200);
//ultrasonic sensor and buzzer
pinMode(buzzer,OUTPUT);
pinMode(Trigpin,OUTPUT);
pinMode(echopin,INPUT);

//Initialise Relay
pinMode(RELAY_PIN, OUTPUT);
digitalWrite(RELAY_PIN, HIGH);

//Initialise DHT
dht.begin();

//Initialise OLED
if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
{
Serial.println("OLED not found");
while (1);
}

Serial.println("System Started");
}

// Loop
void loop()
{
readSoilMoisture();
 
readDHTSensor();
 
controlPump();
 
displayData();
ultrasonic();

 delay(2000);
}
