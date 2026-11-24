#include "temp_sensor.h"
#include "bsp_adc.h"

void TempSensor_Init(void){
        //Init the sensor if necessary
}

TempSensor_Status_t TempSensor_Read(int16_t *temperature_cC){

    TempSensor_Status_t Temp_Status = TEMP_SENSOR_COMM_ERR;
    if (temperature_cC != NULL) {
        int32_t temp_cC = BSP_ADC_Read()*TEMP_RESOLUTION_CC;
        if ((temp_cC < TEMP_MIN_CC)||(temp_cC > TEMP_MAX_CC)) {
            Temp_Status = TEMP_SENSOR_OUT_OF_RANGE;
        } else {
            Temp_Status = TEMP_SENSOR_OK;
            *temperature_cC = (int16_t)temp_cC;
        }
    }
    return Temp_Status;
}