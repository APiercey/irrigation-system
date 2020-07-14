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

  // Note: Do not use the mqtt in the callback to publish, subscribe or
  // unsubscribe as it may cause deadlocks when other things arrive while
  // sending and receiving acknowledgments. Instead, change a global variable,
  // or push to a queue and handle it in the loop after calling `mqtt.loop()`.
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

void printLocalTime() {
  struct tm timeinfo;

  if (!getLocalTime(&timeinfo)) {
    Serial.println("Failed to obtain time");
    return;
  }

  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
  Serial.print("Day of week: ");
  Serial.println(&timeinfo, "%A");
  Serial.print("Month: ");
  Serial.println(&timeinfo, "%B");
  Serial.print("Day of Month: ");
  Serial.println(&timeinfo, "%d");
  Serial.print("Year: ");
  Serial.println(&timeinfo, "%Y");
  Serial.print("Hour: ");
  Serial.println(&timeinfo, "%H");
  Serial.print("Hour (12 hour format): ");
  Serial.println(&timeinfo, "%I");
  Serial.print("Minute: ");
  Serial.println(&timeinfo, "%M");
  Serial.print("Second: ");
  Serial.println(&timeinfo, "%S");

  Serial.println("Time variables");

  char timeHour[3];
  strftime(timeHour, 3, "%H", &timeinfo);
  Serial.println(timeHour);

  char timeWeekDay[10];
  strftime(timeWeekDay, 10, "%A", &timeinfo);
  Serial.println(timeWeekDay);
  Serial.println();
}

void setup() {
  Serial.begin(115200);

  mqtt.begin("test.mosquitto.org", net);
  mqtt.onMessage(messageReceived);

  connectToNetwork();
  connectToBroker();

  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  printLocalTime();
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
