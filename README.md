# Thermostat Project

A learning project focused on embedded software architecture, simulating a temperature regulating valve controlled by a Finite State Machine (FSM).

## 1. Project Overview
The goal of this project is to practice writing clean, testable C code for embedded systems by strictly separating the business logic from hardware dependencies.

**Key Features:**
* **Finite State Machine**: Core logic handling `INIT`, `REGULATING`, and `ERROR` states.
* **Hardware Abstraction**: The thermostat logic is decoupled from actual sensor reading and valve actuation.
* **Fail-Safe Behavior**: Automatic valve shutdown upon critical sensor failures.

## 2. Tools & Stack
* C Compiler (GCC / MinGW)
* CMake 
* Unity (ThrowTheSwitch) for unit testing

## 3. Project Structure
```text
Thermostat_project/
├── CMakeLists.txt        
├── inc/                  
├── src/                  
└── test/
