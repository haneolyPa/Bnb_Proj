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
	virtual ~Bnb_Sensor() {}

public:
	virtual void init();
	virtual void loop();

public:
	String toString() const;
	void setSensorType(BNB_Sensor_type sensorType) { m_sensorType = sensorType; }
	BNB_Sensor_type getSensorType() const { return m_sensorType; }
	void setDeviceInfo(Bnb_DeviceInfoClass* deviceInfo) {
		m_pDeviceInfo = deviceInfo;
		init();
	}

	boolean checkSensorType(BNB_ArduinoJSON subscribeJson)
	{
		String sensorName;
		subscribeJson.getTag("sensor", sensorName);
		return sensorName.equals(_getSensorName());
	}

protected:
	BNB_ArduinoJSON& _getJSON() { return m_dataJSON; }
	const BNB_ArduinoJSON& _getConstJSON() const { return m_dataJSON; }
	uint8_t _getInputPin() const { return m_inputPin; }
	Bnb_DeviceInfoClass* getDeviceInfo() { return m_pDeviceInfo; }

private:
	virtual String _getSensorName() = 0;
	virtual void _publish() = 0;

private:
	virtual void _jsonInit();
	virtual boolean _isNullSensor() { return false; }

private:
	boolean _isOutputTime();
	//unsigned long _getpreviousMillisForPublish();

private:
	SENSORPIN m_inputPin;
	BNB_ArduinoJSON m_dataJSON;
	Bnb_DeviceInfoClass* m_pDeviceInfo;
	BNB_Sensor_type m_sensorType;
	unsigned long m_previousMillis;
};

extern Bnb_Sensor* BnbSensor;

#endif

