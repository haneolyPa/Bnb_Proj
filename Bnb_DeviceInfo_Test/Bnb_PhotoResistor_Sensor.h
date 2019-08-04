// Bnb_PhotoResistor_Sensor.h

#ifndef _BNB_PHOTORESISTOR_SENSOR_h
#define _BNB_PHOTORESISTOR_SENSOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Bnb_Analog_Sensor.h"

class Bnb_PhotoResistor_Sensor : public Bnb_Analog_Sensor
{
public:
	Bnb_PhotoResistor_Sensor(SENSORPIN dhtpin) : Bnb_Analog_Sensor(dhtpin) {}

private:
	virtual String _getSensorName() { return String("PhotoResistor_Sensor"); }
	//virtual void _publish();
};


#endif

