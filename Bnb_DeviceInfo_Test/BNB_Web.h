
#ifndef BNB_WEB_H
#define BNB_WEB_H
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <PubSubClient.h>
#include "BNB_NetConfig.h"

class BNB_Web
{
protected:
  String _name;
  static ESP8266WebServer server;
  
public:
  BNB_Web();
  void StartUp();
  void Shutdown();
  void Loop();

  static void handleRoot();
  static void handleReset(); 
  static void handleRegister(); 
};

#endif
