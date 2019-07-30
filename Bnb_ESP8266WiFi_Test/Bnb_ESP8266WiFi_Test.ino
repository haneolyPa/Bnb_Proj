/*
 Name:		IOT_Device_Template.ino
 Created:	2019-07-24 오후 4:31:41
 Author:	BNB Study
*/

// the setup function runs once when you press reset or power the board
#include "NetworkConfig.h"

void setup() {
	Serial.begin(115200);
	delay(1000);
	Serial.println("=== begin NetworkConfig Test ===");

	NetworkConfig.init();
}

// the loop function runs over and over again until power down or reset
void loop() {
	//웹서버 업데이트
	updateWeb();
}

//웹서버 업데이트
void updateWeb()
{
	//업데이트 웹서버
	server.handleClient();
}