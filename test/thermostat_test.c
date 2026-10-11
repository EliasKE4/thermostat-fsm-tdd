#include "temp_sensor_mock.h"
#include "thermostat.h"
#include "temp_sensor.h"
#include "unity.h"

void setUp(void){
    Thermostat_Init();
}

void tearDown(void){
    //Clean and shut down everything
}
void test_Thermostat_Init(void){
    TEST_ASSERT_EQUAL(THERMOSTAT_INIT, Thermostat_GetState());
}

void test_Thermostat_SwitchToRegulating(void){
    TEST_ASSERT_EQUAL(VALVE_CMD_NONE, Thermostat_Update());
    TEST_ASSERT_EQUAL(THERMOSTAT_REGULATING, Thermostat_GetState());
}

void test_Thermostat_StaysRegulating(void){
    Thermostat_Update();

    TempSensorMock_SetNextRead(TEMP_SENSOR_OK, 2900);
    TEST_ASSERT_EQUAL(VALVE_CMD_NONE, Thermostat_Update());
    TEST_ASSERT_EQUAL(THERMOSTAT_REGULATING, Thermostat_GetState());

}

void test_Thermostat_OpenValve(void){
    Thermostat_Update();

    TempSensorMock_SetNextRead(TEMP_SENSOR_OK, 3500);
    TEST_ASSERT_EQUAL(VALVE_CMD_OPEN, Thermostat_Update());
    TEST_ASSERT_EQUAL(THERMOSTAT_REGULATING, Thermostat_GetState());
}

void test_Thermostat_CloseValve(void){
    Thermostat_Update();

    TempSensorMock_SetNextRead(TEMP_SENSOR_OK, 2000);
    TEST_ASSERT_EQUAL(VALVE_CMD_CLOSE, Thermostat_Update());
    TEST_ASSERT_EQUAL(THERMOSTAT_REGULATING, Thermostat_GetState());
}

void test_Thermostat_CommError(void){
    Thermostat_Update();

    TempSensorMock_SetNextRead(TEMP_SENSOR_COMM_ERR, 2900);
    TEST_ASSERT_EQUAL(VALVE_CMD_NONE, Thermostat_Update());
    TEST_ASSERT_EQUAL(THERMOSTAT_ERROR, Thermostat_GetState());
}

void test_Thermostat_CloseValveDuringError(void){
    Thermostat_Update();
    TempSensorMock_SetNextRead(TEMP_SENSOR_COMM_ERR, 2900);
    Thermostat_Update();

    TEST_ASSERT_EQUAL(VALVE_CMD_CLOSE, Thermostat_Update());
    TEST_ASSERT_EQUAL(THERMOSTAT_ERROR, Thermostat_GetState());
}

void test_Thermostat_OutOfRange(void){
    Thermostat_Update();

    TempSensorMock_SetNextRead(TEMP_SENSOR_OUT_OF_RANGE, 2900);
    TEST_ASSERT_EQUAL(VALVE_CMD_NONE, Thermostat_Update());
    TEST_ASSERT_EQUAL(THERMOSTAT_ERROR, Thermostat_GetState());
}

int main(void) {
    UNITY_BEGIN();
    
    // On lance chaque scénario
    RUN_TEST(test_Thermostat_Init);
    RUN_TEST(test_Thermostat_SwitchToRegulating);
    RUN_TEST(test_Thermostat_StaysRegulating);
    RUN_TEST(test_Thermostat_OpenValve);
    RUN_TEST(test_Thermostat_CloseValve);
    RUN_TEST(test_Thermostat_CommError);
    RUN_TEST(test_Thermostat_CloseValveDuringError);
    RUN_TEST(test_Thermostat_OutOfRange);
    
    return UNITY_END();
}