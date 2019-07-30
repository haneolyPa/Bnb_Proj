// 
// 
// 

#include "Bnb_DoorDigital_Sensor.h"

void Bnb_DoorDigital_Sensor::_setValue()
{
	int digitalVal = digitalRead();
	Serial.print("digitalVal = ");
	Serial.print(digitalVal);
	Serial.println();

	_getJSON().addValue("Door_Status", digitalVal ? "Open" : "Close");
}
