// 
// 
// 

#include "Bnb_DeviceInfo.h"
#include "Bnb_SensorFactory.h"

void _setup_wifi() 
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

		if (WiFi.status() != WL_CONNECTED) {
			Serial.println("WiFi connect faile!!!");
			Serial.println("Start Ap Mode!!!");
			return ;
		}

		randomSeed(micros());
		Serial.println("");
		Serial.println("WiFi connected");
		Serial.println(WiFi.localIP());
		delay(500);
	}
}

void Bnb_DeviceInfoClass::init()
{
	Device_Info();
	NetConfig_StartUp();
	m_web.StartUp();

	// wifi 접속
	_setup_wifi();

	if (WiFi.status() == WL_CONNECTED) {
		BnbSensor = BnbSensorCreate(getSensorType(), getSensorPin());
		if (!BnbSensor)
			return;

		BnbSensor->setDeviceInfo(this);
	}
}

void Bnb_DeviceInfoClass::loop()
{
	m_web.Loop();
	if (BnbSensor != NULL)
		BnbSensor->loop();
}

void Bnb_DeviceInfoClass::NetConfig_StartUp()
{
	Serial.println("NetConfig Start UP!!!");
	m_netConfig.StartUp();
}


Bnb_DeviceInfoClass Bnb_DeviceInfo;

