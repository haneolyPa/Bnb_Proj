
#ifndef BNB_NETCONFIG_H
#define BNB_NETCONFIG_H

#include "FS.h"
#include <SPIFFSIniFile.h>
#include <ArduinoJson.h>


#define FILE_READ       "r"
#define FILE_WRITE      "w"
#define FILE_APPEND     "a"

#define DEFAULT_SSID     "iot_ssid"
#define DEFAULT_PASS     "password"
#define DEFAULT_DEVICENAME      "iot_device"
#define DEFAULT_MQTT_SERVER_IP  "192.168.0.100"
#define CONFIG_FILEPATH   "/config.json"

class BNB_NetConfig
{
protected:
	String _name;
	String _mqtt_ip;
	String _ssid;
	String _pass;

public:
	BNB_NetConfig();
	boolean StartUp();
	void Shutdown();
	void Reset();
	void Read();
	void Write(String ssid, String pass, String name, String mqtt_ip);
	String GetNAME();
	String GetSSID();
	String GetPASSWORD();
	String Get_MQTT_IP();

};

//extern BNB_NetConfig g_NetConfig;

#endif
