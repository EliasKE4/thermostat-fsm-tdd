#include <stdint.h>
#include "thermostat.h"
#include "temp_sensor.h"

static Thermostat_State_t thermostat_curr_state;

void Thermostat_Init(void){
    thermostat_curr_state = THERMOSTAT_INIT;
    return;
}

Thermostat_State_t Thermostat_GetState(void){
    return thermostat_curr_state;
}

Valve_Command_t Thermostat_Update(void){
    TempSensor_Status_t tempSensor_curr_state;
    int16_t curr_temp;
    Valve_Command_t valve_cmd = VALVE_CMD_NONE;
    switch (thermostat_curr_state) {
        case THERMOSTAT_INIT:
            thermostat_curr_state = THERMOSTAT_REGULATING;
            break;
        case THERMOSTAT_REGULATING:
            tempSensor_curr_state = TempSensor_Read(&curr_temp);
            if (tempSensor_curr_state != TEMP_SENSOR_OK){
                thermostat_curr_state = THERMOSTAT_ERROR;
            } else if (curr_temp > 3000){
                valve_cmd = VALVE_CMD_OPEN;
            } else if (curr_temp < 2800) {
                valve_cmd = VALVE_CMD_CLOSE;
            } 
            break;
        case THERMOSTAT_ERROR:
            valve_cmd = VALVE_CMD_CLOSE;
            break;
        default:
            thermostat_curr_state = THERMOSTAT_ERROR;
            break;
    }
    return valve_cmd;
}
