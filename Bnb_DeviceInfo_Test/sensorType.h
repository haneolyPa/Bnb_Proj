// sensorType.h

#ifndef _SENSORTYPE_h
#define _SENSORTYPE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#define SENSORPIN	uint8_t

enum BNB_Sensor_type  {
	null_sensor = 0,
	DHT11_Sensor,			// �½��� ����
	PhotoResistor_Sensor,	// ���� ����
	Door_Sensor,			// ���� ����
	Flame_Sensor,			// �Ҳ� ����
	Gas_Sensor,				// ���� ����
	Sound_Sensor,			// �Ҹ� ����
	Motion_Sensor,			// ��� ����
	Soil_Moisture_Sensor	// ������ ����
};

#endif

