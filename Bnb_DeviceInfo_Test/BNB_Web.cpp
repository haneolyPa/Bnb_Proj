#include "BNB_Web.h"
#include "Bnb_DeviceInfo.h"

ESP8266WebServer BNB_Web::server(80);

BNB_Web::BNB_Web()
{

}

void BNB_Web::StartUp()
{
	//웹서버 시작
	server.on("/", handleRoot);
	server.on("/reset", handleReset);
	server.on("/register", handleRegister);
	server.begin();
	Serial.println("HTTP server started");
}

void BNB_Web::Shutdown()
{

}

void BNB_Web::Loop()
{
	//업데이트 웹서버
	server.handleClient();
}

//웹서버 (192.168.0.x/ 요청)
void BNB_Web::handleRoot()
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
		"  NAME:<br>"
		"  <input type='text' name='name' value='iot_device' style='width: 400px; height: 30px;'>"
		"  <br>"
		"  MQTT_IP:<br>"
		"  <input type='text' name='mqtt_ip' value='192.168.0.100' style='width: 400px; height: 30px;'>"
		"  <p>&nbsp<p>"
		"  <input type='submit' value='Register' style='width: 400px; height: 40px;'>"
		"</form><p>"
		"<form action='/reset' method='get'>"
		"  <input type='submit' value='Reset Setting' style='width: 400px; height: 40px;'>"
		"</form> ";

	message += "<h1>네트워크 현재 설정</h1>";
	message += "<br>";
	message += "ssid: ";
	message += Bnb_DeviceInfo.getNetConfig().GetSSID();
	message += "<br>";
	message += "pw: ****";
	message += "<br>";
	message += "name: ";
	message += Bnb_DeviceInfo.getNetConfig().GetNAME();
	message += "<br>";
	message += "mqtt_ip: ";
	message += Bnb_DeviceInfo.getNetConfig().Get_MQTT_IP();
	message += "<br>";
	message += "my_ip: ";
	message += WiFi.localIP().toString();
	"</body></html> ";

	server.send(200, "text/html", message);
}

//웹서버 (192.168.0.x/Reset/ 요청)
void BNB_Web::handleReset()
{
	Bnb_DeviceInfo.getNetConfig().Reset();

	server.send(200, "text/html", "<h1>Reset Network Setting!</h1>");
}

//웹서버 (192.168.0.x/Register/ 요청)
void BNB_Web::handleRegister()
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

	Bnb_DeviceInfo.getNetConfig().Write(server.arg(0), server.arg(1), server.arg(2), server.arg(3));

	String message = "";
	message += "<html><head>";
	//message += "<meta charset='UTF-8'><meta http-equiv='refresh' content='10;url=http://192.168.4.1/'>";
	message += "<meta charset='UTF-8'>";
	message += "<meta name='viewport' content='width=device-width, initial-scale=1'>";
	message += "</head><body>";
	message += "<h1>네트워크 설정 성공!</h1>";
	message += "<br>";
	message += "</body></html>";

	server.send(200, "text/html", message);
}
