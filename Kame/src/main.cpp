#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Arduino.h>
#include <robot.h>
/* Put your SSID & Password */
const char* ssid = "Kame";  // Enter SSID here
const char* password = "12345670";  //Enter Password here

/* Put IP Address details */
IPAddress local_ip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);
String HTML()
{
  String msg="<!DOCTYPE html> <html>\n";
  msg+="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  msg+="<title>LED Control</title>\n";
  msg+="<style>html{font-family:Helvetica; display:inline-block; margin:0px auto; text-align:center;}\n";
  msg+="body{margin-top: 50px;} h1{color: #444444; margin: 50px auto 30px;} h3{color:#444444; margin-bottom: 50px;}\n";
  msg+=".button{display:block; width:80px; background-color:#f48100; border:none; color:white; padding: 13px 30px; text-decoration:none; font-size:25px; margin: 0px auto 35px; cursor:pointer; border-radius:4px;}\n";
  msg+=".button-on{background-color:#f48100;}\n";
  msg+=".button-on:active{background-color:#f48100;}\n";
  msg+=".button-off{background-color:#26282d;}\n";
  msg+=".button-off:active{background-color:#26282d;}\n";
  msg+="</style>\n";
  msg+="</head>\n";
  msg+="<body>\n";
  msg+="<h1>ESP8266 Web Server</h1>\n";
  msg+="<h3>Using Station (AP) Mode</h3>\n";
  msg+="</body>\n";
  msg+="</html>\n";
  return msg;
}
ESP8266WebServer server(80);

uint8_t LED1pin = D7;
bool LED1status = LOW;

uint8_t LED2pin = D6;
bool LED2status = LOW;

void handle_jump(){
  server.send(200, "text/html", HTML());
}

void handle_OnConnect() {
  server.send(200, "text/html", HTML()); 
}

void handle_forward() {

  server.send(200, "text/html", HTML()); 
}

void handle_backward() {
  server.send(200, "text/html", HTML()); 
}

void handle_right() {

  server.send(200, "text/html", HTML()); 
}

void handle_left() {
  server.send(200, "text/html", HTML()); 
}

void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}







void setup() {
  servoInit();
  Serial.begin(115200);
  pinMode(LED1pin, OUTPUT);
  pinMode(LED2pin, OUTPUT);

  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);

  delay(100);
  
  server.on("/", handle_OnConnect);
  server.on("/forward", handle_forward);
  server.on("/right", handle_right);
  server.on("/left", handle_left);
  server.on("/backward", handle_backward);
  server.on("/jump", jump);
  server.on("/home", start);
  server.onNotFound(handle_NotFound);
  server.begin();
}

void loop() {
  server.handleClient();

}



