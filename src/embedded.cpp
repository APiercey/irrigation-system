#ifdef EMBEDDED
#include "time.h"
#include <Arduino.h>
#include <MQTT.h>
#include <WiFi.h>

const char *ssid = "TheTechLab";             //  your network SSID (name)
const char *password = "AWildGooseAppeared"; // your network password
unsigned long lastMillis = 0;

const char *ntpServer = "pool.ntp.org";
const long gmtOffset_sec = 0;
const int daylightOffset_sec = 3600;

WiFiClient net;
MQTTClient mqtt;

void connectToNetwork() {
  uint8_t tryCount = 0;
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    tryCount++;

    if (tryCount >= 4 && WiFi.status() == WL_CONNECT_FAILED) {
      WiFi.begin(ssid, password);
    }
  }

  if (WiFi.isConnected()) {
    Serial.println("Connected to Wifi");
    Serial.println(WiFi.macAddress());
  } else {
    Serial.println("Not connected");
  }
}

void messageReceived(String &topic, String &payload) {
  Serial.println("incoming: " + topic + " - " + payload);
}

void connectToBroker() {
  Serial.print("\nconnecting...");

  while (!mqtt.connect("arduino")) {
    Serial.print(".");
    delay(1000);
  }

  Serial.println("\nconnected!");
  mqtt.subscribe(WiFi.macAddress());
}

void setup() {
  Serial.begin(115200);

  mqtt.begin("test.mosquitto.org", net);
  mqtt.onMessage(messageReceived);

  connectToNetwork();
  connectToBroker();

  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
}

void loop() {
  if (!mqtt.connected()) {
    connectToBroker();
  }

  mqtt.loop();

  if (millis() - lastMillis > 1000) {
    lastMillis = millis();
    mqtt.publish(WiFi.macAddress(), "world");
  }
}
#endif
