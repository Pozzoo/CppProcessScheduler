//
// Created by pozzo on 01/05/2024.
//

#include "SimulationSpecs.h"

SimulationSpecs::SimulationSpecs(int simulation_time, std::string scheduler_name, int tasks_number, std::vector<Task> tasks) {
    this -> simulation_time = simulation_time;
    this -> scheduler_name = std::move(scheduler_name);
    this -> tasks_number = tasks_number;
    this -> tasks = std::move(tasks);
}

int SimulationSpecs::getSimulationTime() const {
    return simulation_time;
}

std::string SimulationSpecs::getSchedulerName() const {
    return scheduler_name;
}

int SimulationSpecs::getTasksNumber() const {
    return tasks_number;
}

std::vector<Task> SimulationSpecs::getTasks() const {
    return tasks;
}