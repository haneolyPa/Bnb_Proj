// Bnb_DHT11_Sensor.h

#ifndef _BNB_DHT11_SENSOR_h
#define _BNB_DHT11_SENSOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <DHT.h>       // DHT.h 라이브러리를 포함한다
#include "Bnb_Sensor.h"

class Bnb_DHT11_Sensor : public Bnb_Sensor
{
public:
	Bnb_DHT11_Sensor(SENSORPIN dhtpin) : Bnb_Sensor(dhtpin), m_impl(dhtpin, DHT11) {}

public:
	float readHumidity(bool force=false) { return m_impl.readHumidity(force); }
	float readTemperature(bool S=false, bool force=false) { return m_impl.readTemperature(S, force); }

private:
	virtual void _setValue();
	virtual String _getSensorName() { return String("DHT11_Sensor"); }
	
private:
	DHT m_impl;
	BNB_ArduinoJSON m_dataJSON;
};


#endif

