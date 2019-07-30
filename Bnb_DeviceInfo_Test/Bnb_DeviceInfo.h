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

// ���� ����
#define SET_MEASUREMENT(val)		Bnb_DeviceInfo.setMeasurement(val)

// �й�
#define SET_STUDENT_ID(id)			Bnb_DeviceInfo.setStudentID(id)

// �̸�
#define SET_STUDENT_NAME(name)		Bnb_DeviceInfo.setStudentName(name)

// ��ġ��
#define SET_DEVICE_NAME(devName)	Bnb_DeviceInfo.setDeviceName(devName)

// ���� Ÿ��
#define SET_SENSOR_TYPE(sensorType)	Bnb_DeviceInfo.setSensorType(sensorType)

// ���� PIN
#define SET_SENSOR_PIN(sensorPin)	Bnb_DeviceInfo.setSensorPin(sensorPin)

extern void Device_Info();

class Bnb_DeviceInfoClass
{
 public:
	void init();

public:
	void setMeasurement(String val) { m_measurement = val; }
	String getMeasurement() { return m_measurement; }

	void setStudentID(String id) { m_studentID = id; }
	String getStudentID() { return m_studentID; }

	void setStudentName(String name) { m_studentName = name; }
	String getStudentName() { return m_studentName; }

	void setDeviceName(String devName) { m_deviceName = devName; }
	String getDeviceName() { return m_deviceName; }

	void setSensorType(BNB_Sensor_type sensorType) { m_sensorType = sensorType; }
	BNB_Sensor_type getSensorType() { return m_sensorType; }

	void setSensorPin(SENSORPIN sensorPin) { m_sensorPin = sensorPin; }
	SENSORPIN getSensorPin() { return m_sensorPin; }

private:
	String m_measurement;
	String m_studentID;
	String m_studentName;
	String m_deviceName;
	BNB_Sensor_type m_sensorType;
	SENSORPIN		m_sensorPin;
};

extern Bnb_DeviceInfoClass Bnb_DeviceInfo;

#endif

