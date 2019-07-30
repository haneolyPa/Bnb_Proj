// 
// 
// 

#include "Bnb_MotionDigital_Sensor.h"

void Bnb_MotionDigital_Sensor::_setValue()
{
	int digitalVal = digitalRead();
	Serial.print("digitalVal = ");
	Serial.print(digitalVal);
	Serial.println();

	_getJSON().addValue("Motion_Status", digitalVal ? "On" : "Off");
}
