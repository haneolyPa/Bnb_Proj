// 
// 
// 

#include "Bnb_DHT11_Sensor.h"
#include "BnbPubSubClient.h"

void Bnb_DHT11_Sensor::_publish()
{
	_getJSON().addValue("value", readHumidity());
	Serial.println(toString());
	BNBPubSubClient->publish(toString());

	_getJSON().addValue("value", readTemperature());
	Serial.println(toString());
	BNBPubSubClient->publish(toString());
}