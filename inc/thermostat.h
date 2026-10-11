#ifndef THERMOSTAT_H
#define THERMOSTAT_H

#include <stdint.h>

typedef enum{
    THERMOSTAT_INIT,
    THERMOSTAT_REGULATING,
    THERMOSTAT_ERROR,
} Thermostat_State_t;

typedef enum {
    VALVE_CMD_NONE,
    VALVE_CMD_OPEN,
    VALVE_CMD_CLOSE,
} Valve_Command_t;

void Thermostat_Init(void);

Valve_Command_t Thermostat_Update(void);

Thermostat_State_t Thermostat_GetState(void);

#endif /* THERMOSTAT_H */