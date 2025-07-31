#include <WiFi.h>
#include <PubSubClient.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET     -1
Adafruit_SSD1306 display(128, 64, &Wire, OLED_RESET);

// Replace with your WiFi and MQTT credentials
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";
const char* mqtt_server = "broker.hivemq.com";

WiFiClient espClient;
PubSubClient client(espClient);

float readVoltage() {
  return analogRead(34) * (3.3 / 4095.0) * 10; // basic estimation
}

void setup_wifi() {
  delay(100);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) delay(500);
}

void reconnect() {
  while (!client.connected()) {
    client.connect("ESP32Client");
  }
}

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
}

void loop() {
  if (!client.connected()) reconnect();
  client.loop();
  float voltage = readVoltage();
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("Voltage: ");
  display.print(voltage);
  display.println(" V");
  display.display();
  client.publish("home/energy/voltage", String(voltage).c_str());
  delay(5000);
}
