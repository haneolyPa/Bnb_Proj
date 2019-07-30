// 
// 
// 

#include "Bnb_SensorFactory.h"
#include "Bnb_Sensors.h"

Bnb_SensorFactory* Bnb_SensorFactory::m_pInst = NULL;

Bnb_SensorFactory::~Bnb_SensorFactory()
{
	_destroySensor();
}

Bnb_SensorFactory* Bnb_SensorFactory::GetInstance()
{
	if (!m_pInst)
		m_pInst = new Bnb_SensorFactory();

	return m_pInst;
}

Bnb_Sensor* Bnb_SensorFactory::createSensor(BNB_Sensor_type sensorType, SENSORPIN sensorPin)
{
	Serial.print("Seonsor Type :");
	Serial.println(sensorType);
	Serial.print("Seonsor Pin : ");
	Serial.println(sensorPin);

	_destroySensor();
	switch (sensorType)
	{
	case DHT11_Sensor:								// �½�������
		m_pSensor = new Bnb_DHT11_Sensor(sensorPin);
		break;
	case PhotoResistor_Sensor:						// ��������
		Serial.print("Seonsor Type : PhotoResistor_Sensor");
		m_pSensor = new Bnb_PhotoResistor_Sensor(sensorPin);
		if (m_pSensor)
			Serial.println("Sensor create successful!!!");
		else
			Serial.println("Sensor create failed!!!");
		break;
	case Door_Sensor:								// �����
		m_pSensor = new Bnb_DoorDigital_Sensor(sensorPin);
		break;
	case Flame_Sensor:								// �Ҳ� ����
		m_pSensor = new Bnb_Flame_Sensor(sensorPin);
		break;
	case Gas_Sensor:								// ���� ����
		m_pSensor = new Bnb_Gas_Sensor(sensorPin);
		break;
	case Sound_Sensor:								// �Ҹ� ����
		m_pSensor = new Bnb_Sound_Sensor(sensorPin);
		break;
	case Motion_Sensor:								// ��� ����
		m_pSensor = new Bnb_MotionDigital_Sensor(sensorPin);
		break;
	case Soil_Moisture_Sensor:						// ������ ����
		m_pSensor = new Bnb_SoilMoisture_Sensor(sensorPin);
		break;
	case null_sensor:
	default:
		break;
	}
	return m_pSensor;
}

void Bnb_SensorFactory::_destroySensor()
{
	if (m_pSensor != NULL) {
		Serial.println("sensor delete");
		delete m_pSensor;
	}

	m_pSensor = NULL;
}