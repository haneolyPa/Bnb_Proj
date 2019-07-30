// Bnb_Analog_Sensor.h

#ifndef _BNB_ANALOG_SENSOR_h
#define _BNB_ANALOG_SENSOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "BNB_ArduinoJSON.h"
#include "Bnb_Sensor.h"

class Bnb_Analog_Sensor : public Bnb_Sensor
{
public:
	Bnb_Analog_Sensor(SENSORPIN dhtpin) : Bnb_Sensor(dhtpin) {}

public:
	int analogRead() const { return ::analogRead(_getInputPin()); }

private:
	virtual void _setValue();
	virtual String _getSensorName() { return String("Analog_Sensor"); }
};


#endif

