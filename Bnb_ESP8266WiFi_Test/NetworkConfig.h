// NetworkConfig.h

#ifndef _NETWORKCONFIG_h
#define _NETWORKCONFIG_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <ESP8266WebServer.h>

class NetworkConfigClass
{
public:
	NetworkConfigClass();

 public:
	void init();

	void SetInfo(String ssid, String password, String mqttBroker);

private:
	// 설정파일 가져오기
	boolean _InitInfo();
	boolean _read();
	//void _write();

	boolean _wifiConnect();
	void _setSoftAPMode();

	void _startWeb();

	String _getSSID() const { return m_ssid; }
	void _setSSID(String ssid) { m_ssid = ssid; }

	String _getPassword() const { return m_pass; }
	void _setPassword(String pass) { m_pass = pass; }

	String _getSoftAPName() { return m_name; }
	//String _GetSoftAPPassword() { return }

private:
	String m_name;
	String m_mqtt_ip;
	String m_ssid;
	String m_pass;

	ESP8266WebServer* m_pServer;
};

extern NetworkConfigClass NetworkConfig;
extern ESP8266WebServer server;

#endif

