# smart-plant-monitor
An IoT-based plant monitoring system that displays real-time Soil Moisture, Humidity &amp; Temperature on an OLED screen.

Components used
-Esp 32 microcontroller
-DHT sensor(DHT11)
-soil moisture sensor
-SSD1306 OLED Display 
-jumper wires and breadboard
<img width="800" height="800" alt="WhatsApp Image 2026-05-09 at 11 57 49" src="https://github.com/user-attachments/assets/5d51b2e5-0cba-41a7-9c0e-e745ae5ed3e2" />


version-2
Intermediate embedded systems project using ESP32 with multi-sensor integration, actuator control, and real-time OLED display


Component
ESP32 
DHT11  GPIO 13
Soil Sensor  GPIO 34
Relay  GPIO 15
Trig (Ultrasonic)  GPIO 5
Echo  GPIO 18
Buzzer  GPIO 4
pump
9V battery
OLED display
level convertor
⚠️ A logic level converter is used on the relay signal line to step up 3.3V (ESP32) → 5V (Relay), ensuring reliable switching

 Libraries Used

Adafruit_SSD1306
Adafruit_GFX
DHT sensor library
