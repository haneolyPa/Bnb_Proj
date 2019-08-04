// 
// 
// 

#include "Bnb_Digital_Sensor.h"
#include "BnbPubSubClient.h"

void Bnb_Digital_Sensor::_publish()
{
	_getJSON().addValue("value", digitalRead());
	Serial.println(toString());
	BNBPubSubClient->publish(toString());
}


