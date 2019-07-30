// Bnb_SensorFactory.h

#ifndef _BNB_SENSORFACTORY_h
#define _BNB_SENSORFACTORY_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "sensorType.h"
#include "Bnb_Sensor.h"

#define BnbSensorFactory								Bnb_SensorFactory::GetInstance()
#define BnbSensorCreate(sensorType, sensorPin)			BnbSensorFactory->createSensor(sensorType, sensorPin)

class Bnb_SensorFactory
{
private:
	Bnb_SensorFactory() : m_pSensor(NULL) {}
public:
	~Bnb_SensorFactory();

public:
	static Bnb_SensorFactory* GetInstance();

public:
	Bnb_Sensor* createSensor(BNB_Sensor_type sensorType, SENSORPIN sensorPin);

private:
	void _destroySensor();

private:
	static Bnb_SensorFactory* m_pInst;
	Bnb_Sensor* m_pSensor;
};


#endif

