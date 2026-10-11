#ifndef TEMP_SENSOR_MOCK_H
#define TEMP_SENSOR_MOCK_H

#include <stdint.h>
#include "temp_sensor.h"

void TempSensorMock_SetNextRead(TempSensor_Status_t TempSensor_Status, int16_t temperature_cC);

#endif /* TEMP_SENSOR_MOCK_H */