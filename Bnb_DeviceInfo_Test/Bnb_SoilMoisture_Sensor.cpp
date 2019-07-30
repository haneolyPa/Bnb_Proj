// 
// 
// 

#include "Bnb_SoilMoisture_Sensor.h"
#include "BnbPubSubClient.h"

void Bnb_SoilMoisture_Sensor::_setValue()
{
	int analogVal = analogRead();
	Serial.print("analogRead = ");
	Serial.print(analogVal);
	Serial.println();

	_getJSON().addValue("SoilMoisture_val", analogVal);
}

String Bnb_SoilMoisture_Sensor::_getSensorName()
{
	return String("SoilMoisture_Sensor");
}