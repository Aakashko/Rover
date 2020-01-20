/*
    This sketch demonstrates how to set up a simple HTTP-like server.
    The server will set a GPIO pin depending on the request
      http://server_ip/gpio/0 will set the GPIO2 low,
      http://server_ip/gpio/1 will set the GPIO2 high
    server_ip is the IP address of the ESP8266 module, will be
    printed to Serial when the module is connected.
*/

#include <ESP8266WiFi.h>

#ifndef STASSID
#define STASSID "realme"
#define STAPSK  "iwilltypeforyou"
#endif

const char* ssid = STASSID;
const char* password = STAPSK;

// Create an instance of the server
// specify the port to listen on as an argument
WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  delay(1000);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(0, OUTPUT);
  pinMode(2, OUTPUT);

  Serial.print(F("Connecting to "));
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(F("."));
  }
  Serial.println();
  Serial.println(F("WiFi connected"));

  // Start the server
  server.begin();
  Serial.println(F("Server started"));

  // Print the IP address
  Serial.println(WiFi.localIP());
}

void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  Serial.println(F("new client"));

  while(client)
  {
    String m = client.readStringUntil('.');
    if(m.length()!=0)
    {
      Serial.println("move: ");
      Serial.println(m);
      if(m=="w")
      {
        digitalWrite(5, 1);
        digitalWrite(4, 0);
        digitalWrite(0, 1);
        digitalWrite(2, 0);        
      }
      else if(m=="s")
      {
        digitalWrite(5, 0);
        digitalWrite(4, 1);
        digitalWrite(0, 0);
        digitalWrite(2, 1);
      }
      else if(m=="d")
      {
        digitalWrite(5, 1);
        digitalWrite(4, 0);
        digitalWrite(0, 0);
        digitalWrite(2, 0);
      }
      else if(m=="a")
      {
        digitalWrite(5, 0);
        digitalWrite(4, 1);
        digitalWrite(0, 0);
        digitalWrite(2, 0);
      }
      delay(1000);
    }    
  }  
}
