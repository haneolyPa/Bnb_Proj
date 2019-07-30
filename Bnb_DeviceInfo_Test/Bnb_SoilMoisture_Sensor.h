// Bnb_SoilMoisture_Sensor.h

#ifndef _BNB_SOILMOISTURE_SENSOR_h
#define _BNB_SOILMOISTURE_SENSOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "BNB_ArduinoJSON.h"
#include "Bnb_Analog_Sensor.h"

class Bnb_SoilMoisture_Sensor : public Bnb_Analog_Sensor
{
public:
	Bnb_SoilMoisture_Sensor(SENSORPIN dhtpin) : Bnb_Analog_Sensor(dhtpin) {}

private:
	virtual void _setValue();
	virtual String _getSensorName();
};

#endif

