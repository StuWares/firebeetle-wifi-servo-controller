#include "config.h"
#include "WiFi.h"
#include "ESPAsyncWebServer.h"

const char* ssid = WIFI_SSID;
const char* password = WIFI_PASSWORD;

AsyncWebServer server(80);

void setup() {

  Serial.begin(115200);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED ) {
    delay(1000);
    Serial.println("Connecting to wifi...");
  }

  Serial.println("Wifi comnected, IP address:");
  Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:

}
