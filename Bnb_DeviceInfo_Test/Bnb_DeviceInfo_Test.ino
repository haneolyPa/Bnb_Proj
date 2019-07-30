/*
 Name:		Bnb_DeviceInfo_Test.ino
 Created:	2019-07-25 오후 11:56:06
 Author:	Bnb Study
*/

#include "sensorType.h"
#include "Bnb_DeviceInfo.h"
#include "BnbPubSubClient.h"

void Device_Info() {
	// 측정 내용
	SET_MEASUREMENT("Bnb_Gas_Sensor");
	// 학번
	SET_STUDENT_ID("123456-7890987");
	// 이름
	SET_STUDENT_NAME("name");
	// 장치명
	SET_DEVICE_NAME("WemosD1R1");
	// 센서 타입
	SET_SENSOR_TYPE(Gas_Sensor);
	// 전송 시간 : 초
	// 
	SET_SENSOR_PIN(A0);
}

void setup() {
	// DeviceInfo 테스트
	delay(1000);
	Bnb_DeviceInfo.init();
}

// the subscribe function runs when mqtt subscribe
void subscribe(const BNB_ArduinoJSON& Json)
{
	Serial.print("subscrib Json = ");
	Json.Test();
}

// the loop function runs over and over again until power down or reset
void loop() {
	delay(1000);
	BnbSensor->loop();
}


