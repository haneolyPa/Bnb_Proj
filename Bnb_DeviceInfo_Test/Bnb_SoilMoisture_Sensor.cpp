// 
// 
// 

#include "Bnb_SoilMoisture_Sensor.h"
#include "BnbPubSubClient.h"

void Bnb_SoilMoisture_Sensor::_setValue()
{
	int analogVal = analogRead();
	int soilper = map(analogVal, 170, 1024, 100, 0);
	Serial.print("analogRead = ");
	Serial.print(analogVal);
	Serial.println();

	_getJSON().addValue("SoilMoisture_val", analogVal);
	_getJSON().addValue("SoilMoisture_per", soilper);
}

String Bnb_SoilMoisture_Sensor::_getSensorName()
{
	return String("SoilMoisture_Sensor");
}