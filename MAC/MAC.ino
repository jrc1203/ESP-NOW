// Universal MAC Address code for both ESP32 and ESP8266
#ifdef ESP32
#include <WiFi.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#endif

void setup() {
  Serial.begin(115200);
  delay(500); // Give serial connection time to start

  // Set WiFi to station mode
  WiFi.mode(WIFI_STA);
  delay(100); // Short delay to ensure mode change

  Serial.println("\nESP MAC Address Finder");
  Serial.println("---------------------");
  
  // Print board type
  #if defined(ESP32)
    Serial.println("Board: ESP32");
  #elif defined(ESP8266)
    Serial.println("Board: ESP8266");
  #endif

  // Print MAC Address
  Serial.print("MAC Address: ");
  
  #if defined(ESP32)
    uint8_t mac[6];
    WiFi.macAddress(mac);
    char macStr[18];
    snprintf(macStr, sizeof(macStr), "%02X:%02X:%02X:%02X:%02X:%02X",
             mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
    Serial.println(macStr);
  #elif defined(ESP8266)
    Serial.println(WiFi.macAddress());
  #endif
}

void loop() {
  // Empty loop
  delay(1000);
}