// 
// 
// 

#include "Bnb_SoilMoisture_Sensor.h"
#include "BnbPubSubClient.h"

void Bnb_SoilMoisture_Sensor::_publish()
{
	int analogVal = analogRead();
	int soilper = map(analogVal, 170, 1024, 100, 0);

	_getJSON().addValue("value", analogVal);
	Serial.println(toString());
	BNBPubSubClient->publish(toString());

	_getJSON().addValue("value", soilper);
	Serial.println(toString());
	BNBPubSubClient->publish(toString());
}

String Bnb_SoilMoisture_Sensor::_getSensorName()
{
	return String("SoilMoisture_Sensor");
}