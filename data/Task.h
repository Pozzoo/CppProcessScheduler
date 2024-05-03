//
// Created by pozzo on 01/05/2024.
//

#ifndef SCHEDULER_TASK_H
#define SCHEDULER_TASK_H


class Task {
private:
    int offset;
    int computation_time;
    int period_time;
    int quantum;
    int deadline;
    int index;
    int relativeDeadline;

public:
    Task() = default;
    Task(int offset, int computation_time, int period_time, int quantum, int deadline, int index);
    Task(int index);
    int getOffset() const;
    int getComputationTime() const;
    void setComputationTime(int computationTime);
    int getPeriodTime() const;
    int getQuantum() const;
    int getDeadline() const;
    int getIndex() const;
    int getRelativeDeadline() const;
    void setRelativeDeadline(int deadline);
    Task cloneTask() const;
};


#endif //SCHEDULER_TASK_H
