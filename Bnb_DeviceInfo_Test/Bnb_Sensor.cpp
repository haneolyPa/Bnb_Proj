// 
// 
// 

#include "Bnb_Sensor.h"
#include "BnbPubSubClient.h"
#include "Bnb_DeviceInfo.h"

Bnb_Sensor::Bnb_Sensor(SENSORPIN dhtpin) : m_inputPin(dhtpin)
{

}

void Bnb_Sensor::init()
{
	BNBPubSubClient->Init();
	_jsonInit();
}

void Bnb_Sensor::_jsonInit()
{
	_getJSON().setRoot(getDeviceInfo()->getMeasurement());
	_getJSON().addTag("student_name", getDeviceInfo()->getStudentName());
	_getJSON().addTag("device", getDeviceInfo()->getDeviceName());
	_getJSON().addTag("sensor", this->_getSensorName());
}

boolean Bnb_Sensor::_isOutputTime()
{
	/*unsigned long currentMillis = millis();

	getDeviceInfo()->getInterval();
	if (currentMillis - previousMillis >= getDeviceInfo()->getInterval())
		previousMillis = currentMillis;*/
	return true;
}

void Bnb_Sensor::loop()
{
	delay(2000);		// dev_info ¿¡¼­

	/*if (!_isNullSensor())
		_setValue();*/

	BNBPubSubClient->loop();

	if (!_isNullSensor() && _isOutputTime()) {
		_getJSON().addTag("publish_time", millis());
		//BNBPubSubClient->publish(toString());
		_publish();
	}
}

String Bnb_Sensor::toString() const
{
	return _getConstJSON().toString();
}


Bnb_Sensor* BnbSensor = NULL;