// 
// 
// 

#include "Bnb_DeviceInfo.h"
#include "Bnb_SensorFactory.h"

void Bnb_DeviceInfoClass::init()
{
	Device_Info();

	BnbSensor = BnbSensorCreate(getSensorType(), getSensorPin());
	if (!BnbSensor)
		return;

	BnbSensor->setDeviceInfo(this);
}


Bnb_DeviceInfoClass Bnb_DeviceInfo;

