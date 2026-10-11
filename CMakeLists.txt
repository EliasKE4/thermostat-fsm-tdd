cmake_minimum_required(VERSION 3.10)
project(ThermostatProject)

include_directories(inc test test/unity)

set(SOURCES
    src/thermostat.c
    test/temp_sensor_mock.c
    test/thermostat_test.c
    test/unity/unity.c
)

add_executable(test_thermostat ${SOURCES})