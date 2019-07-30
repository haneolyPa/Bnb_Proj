#ifndef _BNB_ARDUINOJSON_H_
#define _BNB_ARDUINOJSON_H_

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include <ArduinoJson.h>

#define MEASUREMENT     "measurement"
#define TAG             "tags"
#define FIELDS          "fields"

class BNB_ArduinoJSON
{
public:
	BNB_ArduinoJSON();
	~BNB_ArduinoJSON() {}

public:
	DeserializationError deserializeJson(byte* payload, unsigned int length);
	void Format(String format);

	void setRoot(String key);
	
	template<typename T>
	void addTag(String key, T val)
	{
		m_doc[TAG][key] = val;
	}

	template<typename T>
	void addValue(String key, T val)
	{
		m_doc[FIELDS][key] = val;
	}

	template<typename T>
	void getValue(String key, T& val) const
	{
		T tempVal = m_doc[FIELDS][key];
		val = tempVal;
	}

	String toString() const;

public:
	void Test() const;

private:
	DynamicJsonDocument m_doc;
};

#endif // _BNB_ARDUINOJSON_H_