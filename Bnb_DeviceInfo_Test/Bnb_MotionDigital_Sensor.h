// Bnb_MotionDigital_Sensor.h

#ifndef _BNB_MOTIONDIGITAL_SENSOR_h
#define _BNB_MOTIONDIGITAL_SENSOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Bnb_Digital_Sensor.h"

class Bnb_MotionDigital_Sensor : public Bnb_Digital_Sensor
{
public:
	Bnb_MotionDigital_Sensor(SENSORPIN dhtpin) : Bnb_Digital_Sensor(dhtpin) {}

private:
	virtual void _setValue();
	virtual String _getSensorName() { return String("DoorDigital_Sensor"); }
};

#endif

