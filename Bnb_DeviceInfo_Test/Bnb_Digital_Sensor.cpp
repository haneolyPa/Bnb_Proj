// 
// 
// 

#include "Bnb_Digital_Sensor.h"
#include "BnbPubSubClient.h"

void Bnb_Digital_Sensor::_setValue()
{
	int digitalVal = digitalRead();
	Serial.print("digitalVal = ");
	Serial.print(digitalVal);
	Serial.println();

	_getJSON().addValue("digitalVal", digitalVal);
}


