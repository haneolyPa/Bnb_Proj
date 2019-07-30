# Bnb_Proj
BNB 프로젝트
* 추가 라이브러리
  * ArduinoJson
  * PubSubClient 
  * DHT Sensor library
  * SPIFFSIniFile

* 라이브러리 변경사항
  * PubSubClient 라이브러리의 PubSubClient.h 파일의 #define MQTT_MAX_PACKET_SIZE 128 -> 
  * #define MQTT_MAX_PACKET_SIZE 2048 으로 변경
  
Device_Info 항목 사용 가능
```{.cpp}
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
	// 센서 PIN
	SET_SENSOR_PIN(A0);
}
```

void subscribe(const BNB_ArduinoJSON& Json) 함수 꼭 추가 - 추가하지 않으면 빌드 에러 나요.
