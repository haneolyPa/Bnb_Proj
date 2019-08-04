#ifndef BNB_WIFI_H
#define BNB_WIFI_H

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <PubSubClient.h>
#include "BNB_NetConfig.h"

class BNB_Wifi
{
public:
  WiFiClient mWifiClient;
  
protected:
  String mSSID;
  String mPASS;
  
public:
  BNB_Wifi();
  void StartUp();
  void Shutdown();
  void Loop();
  void Reconnect();
};

#endif
