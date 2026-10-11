#include <stdint.h>
#include "temp_sensor.h"
#include "temp_sensor_mock.h"

static TempSensor_Status_t Next_Status;
static int16_t Next_Temperature;

TempSensor_Status_t TempSensor_Read(int16_t *temperature_cC){
    *temperature_cC = Next_Temperature;
    return Next_Status;
}

void TempSensorMock_SetNextRead(TempSensor_Status_t TempSensor_Status, int16_t temperature_cC){
    Next_Status = TempSensor_Status;
    Next_Temperature = temperature_cC;
    return;
}