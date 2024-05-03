//
// Created by pozzo on 03/05/2024.
//

#ifndef SCHEDULER_SIMULATIONMANAGER_H
#define SCHEDULER_SIMULATIONMANAGER_H


#include <vector>
#include <deque>
#include "CpuManager.h"
#include "../data/SimulationSpecs.h"

class SimulationManager {
private:
    CpuManager cpu;
    std::vector<Task> tasks;
    std::deque<Task> readyQueue;

public:
    SimulationManager();
    bool step(bool isComputing, bool hasQuantum, bool preempt, bool hasDeadline, int time);
    void preemptiveAddToList(Task task, int i);
    void nonPreemptiveAddToList(int i);
    void edf(int simulationTime, bool isComputing);
    void rm(int simulationTime, bool isComputing, int tasksNumber);
    void rr(int simulationTime, bool isComputing);
    void fcfs(int simulationTime, bool isComputing);
    void warmupSimulation(std::vector<Task> tasks);
    void startSimulation(const SimulationSpecs& specs);
};


#endif //SCHEDULER_SIMULATIONMANAGER_H
