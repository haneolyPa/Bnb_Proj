// 
// 
// 

#include <ESP8266WiFi.h>

#include "BnbPubSubClient.h"

#define _DEBUG

#define PUB_TOPIC	"bnbstudy\/device"
#define SUB_TOPIC	"bnbstudy\/device"

BnbPubSubClient* BnbPubSubClient::m_pInst = NULL;

WiFiClient _espClient;

const char* ssid = "BNB";
const char* password = "bnbstudy";
//const char* ssid = "U+NetE8D1";
//const char* password = "1C18060730";
const char* mqtt_server = "1.212.145.110";

void _setup_wifi() {

	delay(10);
	// We start by connecting to a WiFi network
	Serial.println();
	Serial.print("Connecting to ");
	Serial.println(ssid);

	WiFi.begin(ssid, password);

	while (WiFi.status() != WL_CONNECTED) {
		delay(500);
		Serial.print(".");
	}

	randomSeed(micros());

	Serial.println("");
	Serial.println("WiFi connected");
	Serial.println("IP address: ");
	Serial.println(WiFi.localIP());
	Serial.println(PUB_TOPIC);
}

void internal_callback(char* topic, byte* payload, unsigned int length) 
{
	Serial.print("Message arrived [");
	Serial.print(topic);
	Serial.print("] ");
	Serial.println();

	BNB_ArduinoJSON bnbSubJson;
	bnbSubJson.deserializeJson(payload + 1, length - 1);
	bnbSubJson.Test();

	subscribe(bnbSubJson);
}

BnbPubSubClient::BnbPubSubClient() : m_Impl(_espClient)
{
	_mekeClientID();
}

BnbPubSubClient::~BnbPubSubClient()
{
}

BnbPubSubClient* BnbPubSubClient::GetInstance()
{
	if (!m_pInst)
		m_pInst = new BnbPubSubClient();

	return m_pInst;
}

void BnbPubSubClient::Init()
{
#ifdef _DEBUG
	// 烙矫
	pinMode(LED_BUILTIN, OUTPUT);
#endif

	// wifi 立加
	_setup_wifi();

	// mqtt broker 立加
	_begin_Mqtt();
}

void BnbPubSubClient::_begin_Mqtt()
{
	//
	_getImpl()->setServer(mqtt_server, 1883);
	// callback 殿废
	_getImpl()->setCallback(internal_callback);
}

boolean BnbPubSubClient::connected()
{
	return _getImpl()->connected();
}

boolean BnbPubSubClient::connect(const char* id)
{
	return _getImpl()->connect(id);
}

boolean BnbPubSubClient::publish(const char* payload)
{
	char buf[1024];
	sprintf(buf, "[%s]", payload);
	//sprintf(buf, "%s", payload);
	Serial.println(buf);
	if (_getImpl()->publish(PUB_TOPIC, buf)) {
		Serial.println("publish commplete!!!");
		return true;
	}
	else {
		Serial.println("publish failed!!!");
		return false;
	}
}

boolean BnbPubSubClient::publish(String payload)
{
	return publish(payload.c_str());
}

boolean BnbPubSubClient::publish()
{
	String msg = "{\"measurement\":\"temperature_humidity\",\"tags\":{\"student_id\":\"201834-363856\",\"device\":\"D1\",\"sensor\":\"DHT11\"},\"fields\":{\"temperature\":25.50,\"humidity\":33.00}}";
	return publish(msg.c_str());
}

boolean BnbPubSubClient::subscribe()
{
	_getImpl()->subscribe(SUB_TOPIC);
}

boolean BnbPubSubClient::subscribe(const char* topic)
{
	_getImpl()->subscribe(topic);
}

boolean BnbPubSubClient::unsubscribe(const char* topic)
{
	_getImpl()->unsubscribe(topic);
}

int BnbPubSubClient::state()
{
	_getImpl()->state();
}

boolean BnbPubSubClient::loop()
{
	if (!connected()) {
		_reconnect();
	}

	_getImpl()->loop();
}

void BnbPubSubClient::_reconnect() {
	// Loop until we're reconnected
	while (!connected()) {
		Serial.print("Attempting MQTT connection...");
		// Create a random client ID
		// Attempt to connect
		if (connect(_clientID().c_str())) {
			Serial.println("connected");
			// 立加!!!
			subscribe();
		}
		else {
			Serial.print("failed, rc=");
			Serial.print(BNBPubSubClient->state());
			Serial.println(" try again in 5 seconds");
			// Wait 5 seconds before retrying
			delay(5000);
		}
	}
}

void BnbPubSubClient::_mekeClientID()
{
	m_clientId = "BNB-ESP8266Client-";
	m_clientId += String(random(0xffff), HEX);
}


