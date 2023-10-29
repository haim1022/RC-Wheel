/*
 * The servos used in this project are 360 degrees MG996r servos - no position detection, runs endlessly
 */

//Include libraries
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <Servo.h>

//Declare I/O pins
#define LEFT_WHEEL_MOTOR_PIN 1 //TX
#define RIGHT_WHEEL_MOTOR_PIN 2 //D4

//Constatnt parameters
#define DEFAULT_AP_SSID "Robot"
#define DEFAULT_AP_PASSWORD "Aa123456"
#define DEFAULT_MDNS_ADDRESS "robot"

//Declare classes
struct _CONTROLS
{
  int8_t _value;
} _rightServoControls, _leftServoControls;

//Declare objects
  //Network objects
ESP8266WebServer server(80);
  //Servo motors objects
Servo rightServo, leftServo;

//Declare functions
void wifiSetup();
void handleRoot(); //Handle API's interface
void handleCSSStyle(); //Handle CSS styling
void handleJSScript(); //Handle JS scripting
void handleManifest(); //Handle Progressive web app's manifest
void handleServiceWorker(); //Handle the service worker for the PWA
void handleControllerData();
void updateServosPosition();
void handleNotFound(); //Error 420
void setupServos();

void setup() {
  Serial.begin(1000000);
  SPIFFS.begin();
  //Create the local AP
  wifiSetup();
  webserverSetup();
  setupServos();
}

void loop() {
  //Handle network
  MDNS.update();
  server.handleClient();
  //Handle mechanics
  updateServosPosition();
}
