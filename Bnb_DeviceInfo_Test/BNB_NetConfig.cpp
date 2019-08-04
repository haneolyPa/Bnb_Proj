#include "BNB_NetConfig.h"

//BNB_NetConfig g_NetConfig;

BNB_NetConfig::BNB_NetConfig() : _name(DEFAULT_SSID), _ssid(DEFAULT_SSID), _pass(DEFAULT_PASS)
{

}

boolean BNB_NetConfig::StartUp()
{
	boolean bRes;
	//SPIFFS 시작
	if (!SPIFFS.begin())
	{
		Serial.println("An Error has occurred while mounting SPIFFS");
		return false;;
	}

	//설정 파일 없으면 초기 파일 생성
	if (!SPIFFS.exists(CONFIG_FILEPATH))
	{
		bRes = false;
		this->Reset();
	}
	else
		bRes = true;

	//설정 파일 불러오기
	this->Read();
	return bRes;
}

void BNB_NetConfig::Shutdown()
{
	SPIFFS.end();
}

//설정 파일 기본 값
void BNB_NetConfig::Reset()
{
	this->Write(DEFAULT_SSID, DEFAULT_PASS, DEFAULT_SSID, DEFAULT_MQTT_SERVER_IP);
}

//설정 파일 불러오기
void BNB_NetConfig::Read()
{
	//파일 열기
	File file = SPIFFS.open(CONFIG_FILEPATH, FILE_READ);
	if (!file)
	{
		Serial.println("Failed to open file for reading");
		return;
	}

	//파일 불러오기
	String fileContext = "";
	while (file.available())
		fileContext += (char)file.read();

	//파일 닫기
	file.close();

	//json 파싱
	//////////////////////////////////////////////////////////////////////
	const int capacity = JSON_OBJECT_SIZE(8);
	StaticJsonDocument<200> doc;
	DeserializationError error = deserializeJson(doc, fileContext);
	if (error)
	{
		Serial.print(F("deserializeJson() failed: "));
		Serial.println(error.c_str());
		return;
	}

	//설정 데이터 불러오기

	_ssid = doc["ssid"].as<String>();
	_pass = doc["pass"].as<String>();
	_name = doc["name"].as<String>();
	_mqtt_ip = doc["mqtt_ip"].as<String>();

	//////////////////////////////////////////////////////////////////////
	Serial.println(fileContext);
	Serial.println("BNB_NetConfig ReadData Success..");

	Serial.print("ssid");
	Serial.println(_ssid);

	Serial.print("pass");
	Serial.println(_pass);

	Serial.print("name");
	Serial.println(_name);

	Serial.print("mqtt_ip");
	Serial.println(_mqtt_ip);
}

//설정 저장하기
void BNB_NetConfig::Write(String ssid, String pass, String name, String mqtt_ip)
{
	//json 쓰기
	String fileContext;
	const int capacity = JSON_OBJECT_SIZE(8);
	StaticJsonDocument<capacity> doc;
	doc["ssid"] = ssid;
	doc["pass"] = pass;
	doc["name"] = name;
	doc["mqtt_ip"] = mqtt_ip;
	serializeJson(doc, fileContext);

	//파일 열기
	File file = SPIFFS.open(CONFIG_FILEPATH, FILE_WRITE);
	if (!file)
	{
		Serial.println("There was an error opening the file for writing");
		return;
	}

	//파일 쓰기
	if (file.print(fileContext))
	{
		_ssid = ssid;
		_pass = pass;
		_name = name;
		_mqtt_ip = mqtt_ip;
		Serial.println("File was written");
	}
	else
	{
		Serial.println("File write failed");
	}

	//파일 종료
	file.close();

	//////////////////////////////////////////////////////////////////////
	Serial.println(fileContext);
	Serial.println("BNB_NetConfig WriteData Success..");
}

String BNB_NetConfig::GetNAME()
{
	return String(_name);
}

String BNB_NetConfig::GetSSID()
{
	return String(_ssid);
}

String BNB_NetConfig::GetPASSWORD()
{
	return String(_pass);
}

String BNB_NetConfig::Get_MQTT_IP()
{
	return String(_mqtt_ip);
}
