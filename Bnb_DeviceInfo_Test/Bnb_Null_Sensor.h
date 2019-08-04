// Bnb_Null_Sensor.h

#ifndef _BNB_NULL_SENSOR_h
#define _BNB_NULL_SENSOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "BNB_ArduinoJSON.h"
#include "Bnb_Sensor.h"

class Bnb_Null_Sensor : public Bnb_Sensor
{
public:
	Bnb_Null_Sensor(SENSORPIN dhtpin) : Bnb_Sensor(dhtpin) {}

private:
	virtual String _getSensorName() { return String("Null_Sensor"); }
	virtual void _jsonInit() {}
	virtual boolean _isNullSensor() { return true; }
	virtual void _publish() {}
};



#endif

