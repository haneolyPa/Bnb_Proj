// 
// 
// 

#include "NetworkConfig.h"
#include <ESP8266WiFi.h>
#include <SPIFFSIniFile.h>
#include <ArduinoJson.h>

ESP8266WebServer server(80);

void handleRoot();
void handleReset();
void handleRegister();


#define CONFIG_FILEPATH   "/config.json"

#define FILE_READ       "r"
#define FILE_WRITE      "w"
#define FILE_APPEND     "a"

#define DEFAULT_SSID     "BNB_iot_ssid"
#define DEFAULT_PASS     "password"

NetworkConfigClass::NetworkConfigClass() : m_name(DEFAULT_SSID)
{

}

void NetworkConfigClass::init()
{
	// 설정파일 없으면, 최초 접속
	if (!_InitInfo()) {
		Serial.println("Info File Not Found!!!");
		// AP 모드로 변경
		_setSoftAPMode();
	} else if (!_wifiConnect()) {				// wifi 접속시도
		Serial.println("===Connected fail===");
		 // AP 모드로 변경
		 _setSoftAPMode();
	 }
}

boolean NetworkConfigClass::_InitInfo()
{
	//SPIFFS 시작
	if (!SPIFFS.begin()) {
		Serial.println("An Error has occurred while mounting SPIFFS");
		return false;
	}

	//설정 파일 없으면 초기 파일 생성
	if (!SPIFFS.exists(CONFIG_FILEPATH))
		return false;

	//설정 파일 불러오기
	if (!_read())
		return false;

	return true;
}

//설정 파일 불러오기
boolean NetworkConfigClass::_read()
{
	//파일 열기
	File file = SPIFFS.open(CONFIG_FILEPATH, FILE_READ);
	if (!file)
	{
		Serial.println("Failed to open file for reading");
		return false;
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
		return false;
	}

	//설정 데이터 불러오기
	m_ssid = doc["ssid"].as<String>();
	m_pass = doc["pass"].as<String>();
	m_name = doc["name"].as<String>();
	m_mqtt_ip = doc["mqtt_ip"].as<String>();

	//////////////////////////////////////////////////////////////////////
	Serial.println(fileContext);
	Serial.println("NetworkConfig ReadData Success..");
	return true;
}

boolean NetworkConfigClass::_wifiConnect()
{
	WiFi.begin(_getSSID(), _getPassword());
	
	int wifiConnectAttempt = 0;
	while (WiFi.status() != WL_CONNECTED)
	{
		delay(50);
		Serial.print(".");
		wifiConnectAttempt++;
		if (wifiConnectAttempt > 200)
			break;
	}

	if (WiFi.status() != WL_CONNECTED)
		return false;

	return true;
}

void NetworkConfigClass::_setSoftAPMode()
{
	Serial.println("Soft AP Mode!!!");
	WiFi.softAP(_getSoftAPName(), DEFAULT_PASS);
	Serial.println(_getSoftAPName());

	IPAddress myIP = WiFi.softAPIP();
	Serial.print("AP IP address: ");
	Serial.println(myIP);

	// 
	_startWeb();
}

void NetworkConfigClass::_startWeb()
{
	//웹서버 시작
	server.on("/", handleRoot);
	server.on("/reset", handleReset);
	server.on("/register", handleRegister);
	server.begin();

	Serial.println("HTTP server started");
}

boolean NetworkConfigClass::SetInfo(String ssid, String password, String mqttServer)
{
	_setSSID(ssid);
	_setPassword(password);
	// mqttServer 설정

	if (!_wifiConnect()) {

	}

	return false;
}

void handleRoot()
{
	String message =
		"<!DOCTYPE html>"
		"<html><head>"
		"<meta charset='UTF-8'>"
		"<meta name='viewport' content='width=device-width, initial-scale=1'>"
		"</head><body>"
		"<form action='/register' method='get'>"
		"  SSID:<br>"
		"  <input type='text' name='ssid' value='iot_ssid' style='width: 400px; height: 30px;'>"
		"  <br>"
		"  PASSWORD:<br>"
		"  <input type='text' name='password' value='password' style='width: 400px; height: 30px;'>"
		"  <br>"
		//"  NAME:<br>"
		//"  <input type='text' name='name' value='BNB_iot_device' style='width: 400px; height: 30px;'>"
		//"  <br>"
		"  MQTT_IP:<br>"
		"  <input type='text' name='mqtt_ip' value='1.212.145.110' style='width: 400px; height: 30px;'>"
		"  <p>&nbsp<p>"
		"  <input type='submit' value='Register' style='width: 400px; height: 40px;'>"
		"</form><p>"
		"<form action='/reset' method='get'>"
		"  <input type='submit' value='Reset Setting' style='width: 400px; height: 40px;'>"
		"</form> "
		"</body></html> ";

	server.send(200, "text/html", message);
}

//웹서버 (192.168.0.x/Reset/ 요청)
void handleReset()
{
	/*NetworkConfig.Reset();*/
	server.send(200, "text/html", "<h1>Reset Network Setting!</h1>");
}

//웹서버 (192.168.0.x/Register/ 요청)
void handleRegister()
{
	if (3 > server.args())
		return;

	if (!server.argName(0).equals("ssid"))
		return;

	if (!server.argName(1).equals("password"))
		return;

	if (!server.argName(2).equals("name"))
		return;

	if (!server.argName(3).equals("mqtt_ip"))
		return;

	NetworkConfig.SetInfo(server.arg(0), server.arg(1), server.arg(2), server.arg(3));

	int wifiConnectAttempt = 0;
	WiFi.begin(NetworkConfig.GetSSID(), NetworkConfig.GetPASSWORD());
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

	String message = "";
	message += "<html><head>";
	message += "<meta charset='UTF-8'><meta http-equiv='refresh' content='10;url=http://192.168.4.1/'>";
	message += "<meta name='viewport' content='width=device-width, initial-scale=1'>";
	message += "</head><body>";
	message += "<h1>네트워크 설정 성공!</h1>";
	message += "<br>";
	message += "ssid: ";
	message += server.arg(0);
	message += "<br>";
	message += "pw: ";
	message += server.arg(1);
	message += "<br>";
	message += "name: ";
	message += server.arg(2);
	message += "<br>";
	message += "mqtt_ip: ";
	message += server.arg(3);
	message += "<br>";
	message += "my_ip: ";
	message += WiFi.localIP().toString();
	message += "</body></html>";

	server.send(200, "text/html", message);
}

NetworkConfigClass NetworkConfig;

