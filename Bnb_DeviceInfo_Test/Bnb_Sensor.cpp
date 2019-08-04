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
	_getJSON().addTag("student_id", getDeviceInfo()->getStudentID());
	_getJSON().addTag("student_name", getDeviceInfo()->getStudentName());
	_getJSON().addTag("device", getDeviceInfo()->getDeviceName());
	_getJSON().addTag("sensor", this->_getSensorName());
	_getJSON().addTag("sensor_id", getDeviceInfo()->getSensorID());
}

void Bnb_Sensor::loop()
{
	delay(2000);		// dev_info ¿¡¼­

	if (!_isNullSensor())
		_setValue();

	BNBPubSubClient->loop();

	if (!_isNullSensor())
		BNBPubSubClient->publish(toString());
}

String Bnb_Sensor::toString() const
{
	return _getConstJSON().toString();
}


Bnb_Sensor* BnbSensor = NULL;