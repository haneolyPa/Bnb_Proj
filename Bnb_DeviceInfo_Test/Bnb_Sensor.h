// Bnb_Sensor.h

#ifndef _BNB_SENSOR_h
#define _BNB_SENSOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "BNB_ArduinoJSON.h"
#include "sensorType.h"

class Bnb_DeviceInfoClass;

class Bnb_Sensor
{
public:
	//Bnb_Sensor() {}
	Bnb_Sensor(SENSORPIN dhtpin);
	~Bnb_Sensor() {}

public:
	void init();
	void loop();
	String toString() const;
	void setDeviceInfo(Bnb_DeviceInfoClass* deviceInfo) { 
		m_pDeviceInfo = deviceInfo;
		init();
	}

protected:
	BNB_ArduinoJSON& _getJSON() { return m_dataJSON; }
	uint8_t _getInputPin() const { return m_inputPin; }
	Bnb_DeviceInfoClass* getDeviceInfo() { return m_pDeviceInfo; }

private:
	virtual void _setValue() = 0;
	virtual String _getSensorName() = 0;

private:
	SENSORPIN m_inputPin;
	BNB_ArduinoJSON m_dataJSON;
	Bnb_DeviceInfoClass* m_pDeviceInfo;
};

extern Bnb_Sensor* BnbSensor;

#endif

