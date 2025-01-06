#if defined(ESP32)
  #include <WiFi.h>
#elif defined(ESP8266)
  #include <ESP8266WiFi.h>
#endif

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  
  #if defined(ESP32)
    String macAddress = String(WiFi.macAddress()); // ESP32 can return String format!
    Serial.println("MAC: " + macAddress);
  #else
    Serial.println("MAC: " + WiFi.macAddress());
  #endif
}

void loop() {
  delay(1000);
}