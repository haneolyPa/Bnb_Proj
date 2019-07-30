//
//
//

#include "BNB_ArduinoJSON.h"
#include <Arduino.h>

/*
// send json format
{
	"measurement": "temperature_humidity",
	"tags": {
		"student_id": "201834-363856",
		"device": "D1",		// 필요 여부에 따라 추가나 삭제
		"sensor": "DHT11"	// 필요 여부에 따라 추가나 삭제
	},
	"fields": {
		"temperature": 25.50,
		"humidity": 33.00
	}
}
*/
BNB_ArduinoJSON::BNB_ArduinoJSON() : m_doc(1024)
{
	/*String input = "{\"measurement\":\"temperature_humidity\",\"tags\":{\"student_id\":\"201834-363856\",\"device\":\"D1\",\"sensor\":\"DHT11\"},\"fields\":{\"temperature\": 25.50,\"humidity\": 33.00}}";
	::deserializeJson(m_doc, input);*/
}

void BNB_ArduinoJSON::Test() const
{
	::serializeJson(m_doc, Serial);
	Serial.println();
}

DeserializationError BNB_ArduinoJSON::deserializeJson(byte* payload, unsigned int length)
{
	return ::deserializeJson(m_doc, payload, length);
}

void BNB_ArduinoJSON::Format(String format)
{
	::deserializeJson(m_doc, format);
}

void BNB_ArduinoJSON::setRoot(String key)
{
	m_doc[MEASUREMENT] = key;
}

String BNB_ArduinoJSON::toString() const
{
	char buf[1024];
	serializeJson(m_doc, buf);
	return String(buf);
}