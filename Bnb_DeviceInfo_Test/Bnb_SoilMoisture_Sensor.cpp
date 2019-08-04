// 
// 
// 

#include "Bnb_SoilMoisture_Sensor.h"
#include "BnbPubSubClient.h"

void Bnb_SoilMoisture_Sensor::_setValue()
{
	int analogVal = analogRead();
	int soilper = map(analogVal, 170, 1024, 100, 0);

	Serial.println("_setValue in Soil Moisture Sensor");
	Serial.print("SoilMoisture_val = ");
	Serial.print(analogVal);
	Serial.println();
	Serial.print("SoilMoisture_per = ");
	Serial.print(soilper);
	Serial.println();

	_getJSON().addValue("SoilMoisture_val", analogVal);
	_getJSON().addValue("SoilMoisture_per", soilper);
}

String Bnb_SoilMoisture_Sensor::_getSensorName()
{
	return String("SoilMoisture_Sensor");
}