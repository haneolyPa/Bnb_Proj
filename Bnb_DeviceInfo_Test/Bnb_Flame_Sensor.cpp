// 
// 
// 

#include "Bnb_Flame_Sensor.h"

void Bnb_Flame_Sensor::_setValue()
{
	int digitalVal = digitalRead();
	Serial.print("digitalVal = ");
	Serial.print(digitalVal);
	Serial.println();

	_getJSON().addValue("Flame_Status", digitalVal ? "On" : "Off");
}
