
#ifndef BNB_MQTT_H
#define BNB_MQTT_H
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <PubSubClient.h>
#include "BNB_NetConfig.h"

#define TOPIC_FROM_SERVER "bnbstudy/command"
#define TOPIC_FROM_DEVICE "bnbstudy/device"

class BNB_MQTT
{
protected:
  String mName;
  PubSubClient mMqttClient;
  long mLastReconnectAttempt;
  long mLastSend;
  int mValue;
  
public:
  BNB_MQTT(WiFiClient& wifi);
  void StartUp( MQTT_CALLBACK_SIGNATURE );
  void Shutdown();
  void Loop();
  boolean Reconnect();
  void SetValue(int v);
  
} ;

#endif
