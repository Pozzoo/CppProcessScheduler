//
// Created by pozzo on 01/05/2024.
//

#include "Task.h"


Task::Task(int offset, int computation_time, int period_time, int quantum, int deadline, int index) {
    this -> offset = offset;
    this -> computation_time = computation_time;
    this -> period_time = period_time;
    this -> quantum = quantum;
    this -> deadline = deadline;
    this -> relativeDeadline = deadline;
    this -> index = index;

}

Task::Task(int index) {
    this -> index = index;
}

int Task::getOffset() const {
    return this -> offset;
}

int Task::getComputationTime() const {
    return this -> computation_time;
}

void Task::setComputationTime(int computationTime) {
    this -> computation_time = computationTime;
}

int Task::getPeriodTime() const {
    return this -> period_time;
}

int Task::getQuantum() const {
    return this -> quantum;
}

int Task::getDeadline() const {
    return this -> deadline;
}

int Task::getIndex() const {
    return this -> index;
}

int Task::getRelativeDeadline() const {
    return this -> relativeDeadline;
}

void Task::setRelativeDeadline(int deadline) {
    this -> relativeDeadline = deadline;
}

Task Task::cloneTask() const {
    Task task(offset, computation_time, period_time, quantum, deadline, index);
    return task;
}
