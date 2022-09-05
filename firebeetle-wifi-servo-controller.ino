#include "config.h"
#include "WiFi.h"
#include "ESPAsyncWebServer.h"

const char* ssid = WIFI_SSID;
const char* password = WIFI_PASSWORD;

AsyncWebServer server(80);

void setup() {

  Serial.begin(115200);

  pinMode(LED_BUILTIN, OUTPUT);

  WiFi.begin(ssid, password);

  // Wait until WiFi connects
  while (WiFi.status() != WL_CONNECTED ) {
    delay(1000);
    Serial.println("Connecting to wifi...");
  }

  Serial.println("Wifi comnected, IP address:");
  Serial.println(WiFi.localIP());

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(200, "text/html", "<a href='/h'><button>Switch light on</button><a><br /><a href='/l'><button>Switch light off</button><a>");
  });

  server.on("/h", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(200, "text/plain", "Light is on");
    digitalWrite(LED_BUILTIN, HIGH);
  });

  server.on("/l", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(200, "text/plain", "Light is off");
    digitalWrite(LED_BUILTIN, LOW);
  });

  server.begin();

}

void loop() {
  

}
