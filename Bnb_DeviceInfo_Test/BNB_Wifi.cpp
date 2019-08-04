#include "BNB_Wifi.h"
#include "Bnb_DeviceInfo.h"


BNB_Wifi::BNB_Wifi()
{
  
}

void BNB_Wifi::StartUp()
{
  //AP 모드 시작
  Serial.print("Configuring access point...");
  WiFi.softAP(Bnb_DeviceInfo.getNetConfig().GetNAME(), DEFAULT_PASS);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);

  //Wifi 시작
  if (!Bnb_DeviceInfo.getNetConfig().GetSSID().equals(DEFAULT_SSID))
  {
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(Bnb_DeviceInfo.getNetConfig().GetSSID());
    
    WiFi.begin(Bnb_DeviceInfo.getNetConfig().GetSSID(), Bnb_DeviceInfo.getNetConfig().GetPASSWORD());

    int wifiConnectAttempt = 0;
    while (WiFi.status() != WL_CONNECTED) 
    {
      delay(50);
      Serial.print(".");
      wifiConnectAttempt++;
      if (wifiConnectAttempt > 200)
        break;
    }
    
    randomSeed(micros());
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println(WiFi.localIP());
    delay(500);
  }
}

void BNB_Wifi::Reconnect()
{
  int wifiConnectAttempt = 0;
  WiFi.begin(Bnb_DeviceInfo.getNetConfig().GetSSID(), Bnb_DeviceInfo.getNetConfig().GetPASSWORD());
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(50);
    Serial.print(".");
    wifiConnectAttempt++;
    if (wifiConnectAttempt > 200)
        break;
  }

  if (WiFi.status() == WL_CONNECTED)
  {
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println(WiFi.localIP());
  }
}

void BNB_Wifi::Shutdown()
{

}

void BNB_Wifi::Loop()
{

}
