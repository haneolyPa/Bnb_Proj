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
	DHT11_Sensor,			// 온습도 센서
	PhotoResistor_Sensor,	// 조도 센서
	Door_Sensor,			// 도어 센서
	Flame_Sensor,			// 불꽃 센서
	Gas_Sensor,				// 가스 센서
	Sound_Sensor,			// 소리 센서
	Motion_Sensor,			// 모션 센서
	Soil_Moisture_Sensor	// 토양습도 센서
};

#endif

