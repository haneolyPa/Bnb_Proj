// Bnb_Digital_Sensor.h

#ifndef _BNB_DIGITAL_SENSOR_h
#define _BNB_DIGITAL_SENSOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "BNB_ArduinoJSON.h"
#include "Bnb_Sensor.h"

class Bnb_Digital_Sensor : public Bnb_Sensor 
{
public:
	Bnb_Digital_Sensor(SENSORPIN dhtpin) : Bnb_Sensor(dhtpin) {}

public:
	int digitalRead() const { return ::digitalRead(_getInputPin()); }

private:
	virtual void _setValue();
	virtual String _getSensorName() { return String("digital_Sensor"); }
};


#endif

