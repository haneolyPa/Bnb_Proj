/*
 Name:		Bnb_DeviceInfo_Test.ino
 Created:	2019-07-25 오후 11:56:06
 Author:	Bnb Study
*/

//#include "Bnb_Null_Sensor.h"
#include "sensorType.h"
#include "Bnb_DeviceInfo.h"
#include "BnbPubSubClient.h"

void Device_Info() {
	// 센서 타입
	SET_SENSOR_TYPE(null_sensor);
}

void setup() {
	// DeviceInfo 테스트
	delay(1000);
	Bnb_DeviceInfo.init();
}

// the subscribe function runs when mqtt subscribe
void subscribe(const BNB_ArduinoJSON& Json) {
	if (!BnbSensor->checkSensorType(Json))
		return;

	Serial.print("subscrib Json = ");
	Json.Test();
}

// the loop function runs over and over again until power down or reset
void loop() {
	delay(1000);
	if (!BnbSensor)
		BnbSensor->loop();

	delay(1000);
}