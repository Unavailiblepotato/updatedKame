//#include <ESP8266WiFi.h>
//#include <ESP8266WebServer.h>
#include "ESPAsyncWebServer.h"
#include <Arduino.h>
#include <robot.h>
#include <FS.h>
#include <WiFi.h>
#define LED_BUILTIN 2
#include "LittleFS.h"
/* Put your SSID & Password */
const char* ssid = "Kame";  // Enter SSID here
const char* password = "12345670";  //Enter Password here

/* Put IP Address details */
AsyncWebServer server(80);

void handle_jump(){
 Serial.println("jump");
}

void handle_OnConnect() {
  ;

}

void handle_forward() {

Serial.println("forward");
}

void handle_backward() {
Serial.println("backward");
}

void handle_right() {
Serial.println("right");
;
}

void handle_left() {
Serial.println("left");
}

void handle_NotFound(){
Serial.println("notfound");
}

void handle_home(){
 Serial.println("home");
 homeAll(200);
}
void handle_auto(){
 Serial.println("auto");
}

void handle_sprint(){

}

void setup(){
  pinMode(2, OUTPUT);
  servoInit();
  Serial.begin(9600);
  
  if(!LittleFS.begin()){
    Serial.println("An Error has occurred while mounting LittleFS");
  return;
  }

  WiFi.softAP(ssid, password);
 
  Serial.println();
  Serial.print("IP address: ");
  Serial.println(WiFi.softAPIP());
 
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(LittleFS, "/index.html", String(), false);
    handle_OnConnect();
  });
  server.on("/forward", HTTP_GET, [](AsyncWebServerRequest *request){
    request->redirect("/");
    handle_forward();
  });
    server.on("/sprint", HTTP_GET, [](AsyncWebServerRequest *request){
    request->redirect("/");
    handle_sprint();
  });
  server.on("/left", HTTP_GET, [](AsyncWebServerRequest *request){
    request->redirect("/");
    handle_left();
  });
  server.on("/right", HTTP_GET, [](AsyncWebServerRequest *request){
    request->redirect("/");
    handle_right();
  });
  server.on("/backward", HTTP_GET, [](AsyncWebServerRequest *request){
    request->redirect("/");
    handle_backward();
  });
  server.on("/jump", HTTP_GET, [](AsyncWebServerRequest *request){
    request->redirect("/");
    handle_jump();
  });
  server.on("/home", HTTP_GET, [](AsyncWebServerRequest *request){
    request->redirect("/");
    handle_home();
  });
  server.on("/auto", HTTP_GET, [](AsyncWebServerRequest *request){
    request->redirect("/");
    handle_auto();
  });
  server.begin();
}


void loop() {

}

//String getContentType(String filename){
  //if(filename.endsWith(".htm")) return "text/html";
  //else if(filename.endsWith(".html")) return "text/html";
  //else if(filename.endsWith(".css")) return "text/css";
  //else if(filename.endsWith(".jpg")) return "image/jpeg";
  //return "text/plain";
//}


