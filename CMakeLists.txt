cmake_minimum_required(VERSION 3.28)
project(Scheduler)

set(CMAKE_CXX_STANDARD 17)

add_executable(Scheduler main.cpp
        data/SimulationSpecs.cpp
        data/SimulationSpecs.h
        data/Task.cpp
        data/Task.h
        managers/JsonManager.cpp
        managers/JsonManager.h
        managers/CpuManager.cpp
        managers/CpuManager.h
        managers/SimulationManager.cpp
        managers/SimulationManager.h
)

include_directories(/nlohmann/json.hpp)
