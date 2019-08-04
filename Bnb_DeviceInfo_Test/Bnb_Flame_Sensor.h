// Bnb_Flame_Sensor.h

#ifndef _BNB_FLAME_SENSOR_h
#define _BNB_FLAME_SENSOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Bnb_Digital_Sensor.h"

class Bnb_Flame_Sensor : public Bnb_Digital_Sensor
{
public:
	Bnb_Flame_Sensor(SENSORPIN dhtpin) : Bnb_Digital_Sensor(dhtpin) {}

private:
	virtual String _getSensorName() { return String("Flame_Sensor"); }
};

#endif

