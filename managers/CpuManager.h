//
// Created by pozzo on 03/05/2024.
//

#ifndef SCHEDULER_CPUMANAGER_H
#define SCHEDULER_CPUMANAGER_H


#include "../data/Task.h"

class CpuManager {
private:
    int computationTime;
    int quantum;
    Task taskInCpu{};

public:
    CpuManager();
    bool compute(Task task, bool hasQuantum, bool preempt);
    Task getTaskInCpu();
    void setTaskInCpu(Task task);
};


#endif //SCHEDULER_CPUMANAGER_H
