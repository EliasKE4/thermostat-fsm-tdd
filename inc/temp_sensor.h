#ifndef TEMP_SENSOR_H
#define TEMP_SENSOR_H

#include <stdint.h>

typedef enum{
    TEMP_SENSOR_OK,
    TEMP_SENSOR_COMM_ERR,
    TEMP_SENSOR_OUT_OF_RANGE,
} TempSensor_Status_t;

void TempSensor_Init(void);
TempSensor_Status_t TempSensor_Read(int16_t *temperature_cC);

#endif /* TEMP_SENSOR_H */
