#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <string.h>

const char* ssid = "WiFiNetwork";
const char* password = "password";

ESP8266WebServer server(80);

const int led = D3;
const int BAUD = 57600;

String ip = "";

String html(String content) {
  String html = "<html>";
  html += "<head></head>";
  html += "<body>" + content + "</body>";
  html += "</html>";
  return html;
}

void blink() {
  digitalWrite(led, 1);
  delay(1000);
  digitalWrite(led, 0);
}

void led_on() {
  digitalWrite(led, 1);
}

void led_off() {
  digitalWrite(led, 0);
}

void handleRoot() {
  digitalWrite(led, 1);
  String hello = "<h1>Connected to ESP8266</h1>";
  hello += "<p></p>";
  server.send(200, "text/html", html(hello));
  blink();
}

void handleNotFound(){
  digitalWrite(led, 1);
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET)?"GET":"POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i=0; i<server.args(); i++){
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
  blink();
}

void setup(void){
  Serial.begin(BAUD);
  pinMode(led, OUTPUT);
  digitalWrite(led, 1);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  ip = WiFi.localIP().toString();
  
  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
    digitalWrite(led, 0);
  }

  Serial.println("ESP8266WiFi.printDiag(Print& p)");
  WiFi.printDiag(Serial);
  
  server.on("/", handleRoot);

  server.on("/switch/on", [](){
    server.send(200, "text/plain", "The Light is now ON");
    led_on();
  });

  server.on("/switch/off", [](){
    server.send(200, "text/plain", "The Light is now OFF");
    led_off();
  });
  
  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void){
  server.handleClient();
}
