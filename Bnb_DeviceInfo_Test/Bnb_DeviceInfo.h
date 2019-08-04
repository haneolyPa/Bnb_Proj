// Bnb_DeviceInfo.h

#ifndef _BNB_DEVICEINFO_h
#define _BNB_DEVICEINFO_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "sensorType.h"
#include "Bnb_Sensor.h"
#include "BNB_NetConfig.h"
#include "BNB_Web.h"
#include "BNB_Wifi.h"

// 측정 내용
#define SET_MEASUREMENT(val)		Bnb_DeviceInfo.setMeasurement(val)

// 이름
#define SET_STUDENT_NAME(name)		Bnb_DeviceInfo.setStudentName(name)

// 센서 타입
#define SET_SENSOR_TYPE(sensorType)	Bnb_DeviceInfo.setSensorType(sensorType)

// 센서 PIN
#define SET_SENSOR_PIN(sensorPin)	Bnb_DeviceInfo.setSensorPin(sensorPin)

// 센서 ID
#define SET_SENSOR_ID(sensorID)		Bnb_DeviceInfo.setSensorID(sensorID)

// publish interval : 초
#define SET_INTERVAL_SEC(intervalSec)	Bnb_DeviceInfo.setInterval(intervalSec * 1000)

extern void Device_Info();

class Bnb_DeviceInfoClass
{
 public:
	void init();
	void loop();

public:
	void setMeasurement(String val) { m_measurement = val; }
	String getMeasurement() { return m_measurement; }

	void setStudentName(String name) { m_studentName = name; }
	String getStudentName() { return m_studentName; }

	String getDeviceName() { return getNetConfig().GetNAME(); }

	void setSensorType(BNB_Sensor_type sensorType) { m_sensorType = sensorType; }
	BNB_Sensor_type getSensorType() { return m_sensorType; }

	void setSensorPin(SENSORPIN sensorPin) { m_sensorPin = sensorPin; }
	SENSORPIN getSensorPin() { return m_sensorPin; }

	void setInterval(long interval) { m_publish_interval = interval; }
	long getInterval() { return m_publish_interval; }

	BNB_NetConfig& getNetConfig() { return m_netConfig; }
	void setNetConfig(BNB_NetConfig netConfig) { m_netConfig = netConfig; }

	void NetConfig_StartUp();

private:
	String m_measurement;
	String m_studentName;
	BNB_Sensor_type m_sensorType;
	SENSORPIN		m_sensorPin;
	long m_publish_interval;

	BNB_NetConfig	m_netConfig;
	BNB_Web			m_web;
	BNB_Wifi		m_wifi;
};

extern Bnb_DeviceInfoClass Bnb_DeviceInfo;

#endif

