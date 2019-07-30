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

	m_dataJSON.setRoot(getDeviceInfo()->getMeasurement());
	m_dataJSON.addTag("student_id", getDeviceInfo()->getStudentID());
	m_dataJSON.addTag("student_name", getDeviceInfo()->getStudentName());
	m_dataJSON.addTag("device", getDeviceInfo()->getDeviceName());
	m_dataJSON.addTag("sensor", this->_getSensorName());
	//m_dataJSON.addTag("sensor_id", getDeviceInfo());
}

void Bnb_Sensor::loop()
{
	delay(2000);		// dev_info ¿¡¼­

	_setValue();

	BNBPubSubClient->loop();
	BNBPubSubClient->publish(m_dataJSON.toString().c_str());
}

String Bnb_Sensor::toString()const
{
	return m_dataJSON.toString();
}



Bnb_Sensor* BnbSensor;