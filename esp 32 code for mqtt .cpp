
ESP32 Code for MQTT:

#include <WiFi.h>
#include "DHT.h"
#include <PubSubClient.h>
#include "SoftwareSerial.h"// Enables the ESP32 to connect to the local network (via WiFi)
#define RX_PIN 4
#define TX_PIN 2
#define DHTPIN 15
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
SoftwareSerial sds011Serial(RX_PIN, TX_PIN);
const char* WIFI_SSID = "Sahithi";
const char* WIFI_PASSWORD = "sahithi123";
const char* MQTT_SERVER = "broker.hivemq.com";
const char* MQTT_CLIENT_ID = "livingroom";
const char* MQTT_TOPIC = "home/livingroom";
float pm25,pm10;
//const int temp = 34; // Analog input pin for temperature sensor
WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);
void setup() {
  Serial.begin(9600);
  dht.begin();
  sds011Serial.begin(9600);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status()!= WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  mqttClient.setServer(MQTT_SERVER,1883);
}
void connectToMqtt() {
  while (!mqttClient.connected()) {
    Serial.println("Connecting to MQTT server...");

    if (mqttClient.connect(MQTT_CLIENT_ID)) {
      Serial.println("Connected to MQTT server");
    } else {
      Serial.println("Connection to MQTT server failed. Retrying in 5 seconds...");
      delay(5000);
    }
  }
}
void loop() {
 Serial.setTimeout(2000);
 
float h = dht.readHumidity();
float t = dht.readTemperature();
while(sds011Serial.available()) {
     pm25 = sds011Serial.read();
     pm10 = sds011Serial.read();
}
    // Print the values to serial monitor
    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.print(" °C | Humidity: ");
    Serial.print(h);
    Serial.print(" % | PM2.5: ");
    Serial.print(pm25);
    Serial.print(" μg/m³ | PM10: ");
    Serial.print(pm10);
    Serial.println(" μg/m³");
    
   /* array[0]=t;
    array[1]=h;
    array[2]=pm25;
    array[3]=pm10;
    }
// MQTT can only transmit strings
String hs="Hum: "+String((float)h)+" % ";
String ts="Temp: "+String((float)t)+" C ";
String pm251="PM 2.5: "+String((float)pm25)+" ug/m3 ";
String pm101="PM 10: "+String((float)pm10)+" ug/m3 ";
*/
/*float t=40.0  ;
float h=20.0;
float pm25=120.0;
float pm10=180.0;*/
  if (mqttClient.connected()) {
  // char message[100];
//  sprintf(message, sizeof(message), "{\"humidity\": %.2f, \"temperature\": %.2f, \"pm25\": %.2f, \"pm10\": %.2f}", t,h, pm25, pm10);
  char payload[32];
        snprintf(payload, sizeof(payload), "%.2f,%.2f,%.2f,%.2f", t, h, pm25, pm10);
  mqttClient.publish(MQTT_TOPIC, payload);
  delay(5000);
    Serial.println("Published sensor value to MQTT server");
  } else {
    connectToMqtt();
  }
  delay(1000);
}