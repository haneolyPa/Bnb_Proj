// 
// 
// 

#include "Bnb_Analog_Sensor.h"

// 
// 
// 

#include "Bnb_Analog_Sensor.h"
#include "BnbPubSubClient.h"

void Bnb_Analog_Sensor::_setValue()
{
	int analogVal = analogRead();
	Serial.print("analogRead = ");
	Serial.print(analogVal);
	Serial.println();
	_getJSON().addValue("analogVal", analogVal);
}



