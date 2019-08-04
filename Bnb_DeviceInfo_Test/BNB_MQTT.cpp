#include "BNB_MQTT.h"
#include "Bnb_DeviceInfo.h"

BNB_MQTT::BNB_MQTT(WiFiClient& wifi) : mLastReconnectAttempt(0), mLastSend(0), mValue(0), mMqttClient(wifi)
{

}


void BNB_MQTT::StartUp( MQTT_CALLBACK_SIGNATURE )
{
  Serial.println(Bnb_DeviceInfo.getNetConfig().Get_MQTT_IP().c_str());
  IPAddress ipAddress;
  if (ipAddress.fromString(Bnb_DeviceInfo.getNetConfig().Get_MQTT_IP()))
  {
    mMqttClient.setServer(ipAddress, 1883);
    mMqttClient.setCallback(callback);
    mLastReconnectAttempt = 0;
    mLastSend = 0;
  }
}

void BNB_MQTT::Shutdown()
{

}

void BNB_MQTT::SetValue(int v)
{
  mValue = v;
}

//MQTT 재접속
boolean  BNB_MQTT::Reconnect() 
{
  String clientId = "ESP8266Client-";
  clientId += String(random(0xffff), HEX);
  //String clientId = g_NetConfig.GetNAME();   
  if (mMqttClient.connect(clientId.c_str())) 
  {
    Serial.println("connected mqtt server...");
    mMqttClient.subscribe(TOPIC_FROM_SERVER);
  }
  
  return mMqttClient.connected();
}


//업데이트 MQTT
void BNB_MQTT::Loop()
{
    //SSID가 기본 값일 경우 공유기 설정이 안되어 있다고 보고 처리하지 않는다.
   if (Bnb_DeviceInfo.getNetConfig().GetSSID().equals(DEFAULT_SSID))
    return;
    
    //재접속 시도
    if (!mMqttClient.connected()) 
    {
      long now = millis();
      if ((now - mLastReconnectAttempt) > 5000) 
      {
        Serial.println("reconnect mqtt server...");
        mLastReconnectAttempt = now;
        if (Reconnect()) 
        {
          mLastReconnectAttempt = 0;
        }
      }
    } 
    else //5초 단위 보고
    {
      //
      long now = millis();
      if ((now - mLastSend) > 5000) 
      {
        mLastSend = now;

        String deviceName = Bnb_DeviceInfo.getNetConfig().GetNAME();
        String measurement = "sensor";
        String data = String(mValue);
        String message = "";
        message += "[{'measurement' : '" + measurement + "' , 'tags': {'device_name': '" + deviceName + "'}, 'fields': {'value': " + data + "}}]";
        Serial.println("report: ");
        Serial.println(message);
        
        mMqttClient.publish(TOPIC_FROM_DEVICE, message.c_str());
        Serial.println("update mqtt...");
      }
      
      mMqttClient.loop();
    }
}
