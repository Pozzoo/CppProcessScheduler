//
// Created by pozzo on 03/05/2024.
//

#ifndef SCHEDULER_JSONMANAGER_H
#define SCHEDULER_JSONMANAGER_H


#include "../data/SimulationSpecs.h"

class JsonManager {
public:
    static SimulationSpecs readJson(std::string path);
};


#endif //SCHEDULER_JSONMANAGER_H
