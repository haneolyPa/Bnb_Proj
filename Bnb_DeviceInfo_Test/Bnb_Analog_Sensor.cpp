// 
// 
// 

#include "Bnb_Analog_Sensor.h"

// 
// 
// 

#include "Bnb_Analog_Sensor.h"
#include "BnbPubSubClient.h"

void Bnb_Analog_Sensor::_publish()
{
	_getJSON().addValue("value", analogRead());
	Serial.println(toString());
	BNBPubSubClient->publish(toString());
}



