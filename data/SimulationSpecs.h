//
// Created by pozzo on 01/05/2024.
//

#ifndef SCHEDULER_SIMULATIONSPECS_H
#define SCHEDULER_SIMULATIONSPECS_H


#include <string>
#include <utility>
#include <vector>
#include "Task.h"

class SimulationSpecs {
private:
    int simulation_time;
    std::string scheduler_name;
    int tasks_number;
    std::vector<Task> tasks;

public:
    SimulationSpecs(int simulation_time, std::string scheduler_name, int tasks_number, std::vector<Task> tasks);
    int getSimulationTime() const;
    std::string getSchedulerName() const;
    int getTasksNumber() const;
    std::vector<Task> getTasks() const;
};

#endif //SCHEDULER_SIMULATIONSPECS_H
