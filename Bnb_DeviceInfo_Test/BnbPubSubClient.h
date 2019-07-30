// BnbPubSubClient.h

#ifndef _BNBPUBSUBCLIENT_h
#define _BNBPUBSUBCLIENT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#define MQTT_MAX_PACKET_SIZE 1024
#include <PubSubClient.h>
#include "BNB_ArduinoJson.h"

#define BNBPubSubClient		BnbPubSubClient::GetInstance()

// ¼ö½Å JSON
extern void subscribe(const BNB_ArduinoJSON& Json);

class BnbPubSubClient
{
private:
	BnbPubSubClient();
	~BnbPubSubClient();

public:
	static BnbPubSubClient* GetInstance();

public:
	void Init();

	boolean connect(const char* id);
	boolean connected();

	boolean publish(const char* payload);
	boolean publish(String payload);
	boolean publish();

	boolean subscribe();
	boolean subscribe(const char* topic);

	boolean unsubscribe(const char* topic);
	boolean loop();
	int state();

private:
	PubSubClient* _getImpl() { return &m_Impl; }

	void _begin_Mqtt();
	void _reconnect();
	//void internal_callback(char* topic, byte* payload, unsigned int length);

	const String& _clientID() const { return m_clientId; }
	void _mekeClientID();

private:
	static BnbPubSubClient	*m_pInst;
	PubSubClient			m_Impl;
	String					m_clientId;
};

#endif

