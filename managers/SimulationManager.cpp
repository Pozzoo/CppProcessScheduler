//
// Created by pozzo on 03/05/2024.
//

#include <iostream>
#include <cmath>
#include "SimulationManager.h"

SimulationManager::SimulationManager() {
    cpu = CpuManager();
    cpuTime = 0;
}

bool SimulationManager::step(bool isComputing, bool hasQuantum, bool preempt, bool hasDeadline, int time) {

    if (!readyQueue.empty() || cpu.getTaskInCpu().getIndex() != -1) {
        if (!isComputing || preempt) {
            if (cpu.getTaskInCpu().getIndex() != -1 || cpu.getTaskInCpu().getComputationTime() > 0) {
                if (cpu.getTaskInCpu().getIndex() != -1 && (cpu.getTaskInCpu().getComputationTime() > 0)) {
                    readyQueue.push_back(cpu.getTaskInCpu());
                }
                cpu.setTaskInCpu(Task(-1));
            }

            if (!readyQueue.empty()) {
                isComputing = cpu.compute(readyQueue.front(), hasQuantum, preempt);
                readyQueue.pop_front();
            } else {
                isComputing = cpu.compute(cpu.getTaskInCpu(), hasQuantum, preempt);
            }
        } else {
            isComputing = cpu.compute(cpu.getTaskInCpu(), hasQuantum, false);
        }
    }

    if (hasDeadline) {
        cpu.getTaskInCpu().setRelativeDeadline(cpu.getTaskInCpu().getRelativeDeadline() - 1);
    }

    for (Task task : readyQueue) {
        task.setRelativeDeadline(task.getRelativeDeadline() - 1);
    }

    return isComputing;
}

void SimulationManager::preemptiveAddToList(Task task, int i) {
    bool added = false;

    if (task.getOffset() == i || ((i - task.getOffset()) % task.getPeriodTime()) == 0) {
        if (readyQueue.empty()) {
            readyQueue.push_back(task.cloneTask());
        } else {
            for (int j = 0; j < readyQueue.size(); ++j) {
                if (task.getPeriodTime() < readyQueue[j].getPeriodTime()) {
                    std::_Deque_iterator iterator = readyQueue.begin() + j;
                    readyQueue.insert(iterator, task);
                    added = true;
                    break;
                }
            }

            if (!added) {
                readyQueue.push_back(task);
            }
        }
    }
}

void SimulationManager::nonPreemptiveAddToList(int i) {
    for (Task task : tasks) {
        if (task.getOffset() == i || ((i - task.getOffset()) % task.getPeriodTime()) == 0) {
            readyQueue.push_back(task.cloneTask());

        }
    }
}

void SimulationManager::edf(int simulationTime, bool isComputing) {
    float systemUtilization = 0;

    for (Task task : tasks) {
        systemUtilization += ((float) task.getComputationTime() / (float) task.getPeriodTime());
    }

    if (systemUtilization > 1) {
        std::cout << "Non Schedulable" << std::endl;
        return;
    } else {
        bool preempt;

        for (int i = 0; i < simulationTime; ++i) {
            for (Task task : tasks) {
                preemptiveAddToList(task.cloneTask(), i);
            }

            preempt = !readyQueue.empty() && cpu.getTaskInCpu().getIndex() != -1 && readyQueue.front().getRelativeDeadline() < cpu.getTaskInCpu().getRelativeDeadline();

            std::cout << "time: " << i << std::endl;
            isComputing = step(isComputing, false, preempt, true, i);
        }
    }


}

void SimulationManager::rm(int simulationTime, bool isComputing, int taskNumber) {
    float systemUtilization = 0;

    for (Task task : tasks) {
        systemUtilization += ((float) task.getComputationTime() / (float) task.getPeriodTime());
    }

    if (systemUtilization > (taskNumber * (pow(2, ((double) 1 / taskNumber) - 1)))) {
        std::cout << "Non schedulable" << std::endl;
        return;

    } else {
        bool preempt;

        for (int i = 0; i < simulationTime; ++i) {
            for (Task task : tasks) {
                preemptiveAddToList(task, i);
            }

            preempt = !readyQueue.empty() && cpu.getTaskInCpu().getIndex() != -1 && readyQueue.front().getDeadline() < cpu.getTaskInCpu().getDeadline();

            std::cout << "time: " << i << std::endl;
            isComputing = step(isComputing, false, preempt, true, i);
        }
    }
}

void SimulationManager::rr(int simulationTime, bool isComputing) {
    for (int i = 0; i < simulationTime; ++i) {
        std::cout << "Time: " << i << std::endl;
        nonPreemptiveAddToList(i);
        isComputing = step(isComputing, true, false, false, i);
    }
}

void SimulationManager::fcfs(int simulationTime, bool isComputing) {
    for (int i = 0; i < simulationTime; ++i) {
        std::cout << "Time: " << i << std::endl;
        nonPreemptiveAddToList(i);
        isComputing = step(isComputing, false, false, false, i);

    }
}

void SimulationManager::warmupSimulation(std::vector<Task> tasks) {
    //TODO: SEE IF THIS IS NEEDED

}

void SimulationManager::startSimulation(const SimulationSpecs& specs) {
    int simulationTime = specs.getSimulationTime();
    bool isComputing = false;

    tasks = specs.getTasks();

    warmupSimulation(tasks);

    if (specs.getSchedulerName() == "firstcomefirsserve" || specs.getSchedulerName() == "fcfs") {
        fcfs(simulationTime, isComputing);
    } else if (specs.getSchedulerName() == "roundrobin" || specs.getSchedulerName() == "rr") {
        rr(simulationTime, isComputing);
    } else if (specs.getSchedulerName() == "ratemonotonic" || specs.getSchedulerName() == "rm") {
        rm(simulationTime, isComputing, specs.getTasksNumber());
    } else if (specs.getSchedulerName() == "earliestdeadlinefirst" || specs.getSchedulerName() == "edf") {
        edf(simulationTime, isComputing);
    } else {
        std::cout << "Scheduler not found" << std::endl;
    }
}

