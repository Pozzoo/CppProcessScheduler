//
// Created by pozzo on 03/05/2024.
//

#include <iostream>
#include "CpuManager.h"

CpuManager::CpuManager() {
    taskInCpu = Task(-1);
    computationTime = 0;
    quantum = 0;
}

bool CpuManager::compute(Task task, bool hasQuantum, bool preempt) {
    if (task.getIndex() != -1) {
        if (computationTime <= 0 || quantum <= 0 || preempt) {
            task.setComputationTime(task.getComputationTime() - 1);
            quantum = task.getQuantum();
            taskInCpu = task;
        } else {
            taskInCpu.setComputationTime(taskInCpu.getComputationTime() - 1);
        }
        computationTime = taskInCpu.getComputationTime();
        quantum--;
    }

    if (!hasQuantum) quantum = 2;

    std::cout << "Task in CPU: " << taskInCpu.getIndex() + 1 << std::endl;

    return computationTime > 0 && quantum > 0;
}

Task CpuManager::getTaskInCpu() {
    return this -> taskInCpu;
}

void CpuManager::setTaskInCpu(Task task) {
    this -> taskInCpu = task;
}