// 
// 
// 

#include "Bnb_DHT11_Sensor.h"
#include "BnbPubSubClient.h"

void Bnb_DHT11_Sensor::_setValue()
{
	float h, t;
	h = readHumidity();
	t = readTemperature();
	Serial.print("Humidity = ");
	Serial.print(h);
	Serial.print(",");
	Serial.print(" Temperature = ");
	Serial.print(t);
	Serial.println();
	_getJSON().addValue("Humidity", h);
	_getJSON().addValue("Temperature", t);
}