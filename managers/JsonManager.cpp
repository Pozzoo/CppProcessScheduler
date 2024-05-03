//
// Created by pozzo on 03/05/2024.
//

#include <iostream>
#include <fstream>
#include "JsonManager.h"
#include "../include/nlohmann/json.hpp"

using json = nlohmann::json;

SimulationSpecs JsonManager::readJson(std::string path) {
    std::ifstream jsonFileStream(path);
    if (!jsonFileStream.is_open())
        std::cout << "failed to open json, verify path" << std::endl;

    json jsonData = json::parse(jsonFileStream);

    int taskNumber = jsonData["tasks_number"];
    std::vector<Task> tasks(taskNumber);

    for (int i = 0; i < taskNumber; ++i) {
        Task task(jsonData["tasks"][i]["offset"], jsonData["tasks"][i]["computation_time"], jsonData["tasks"][i]["period_time"], jsonData["tasks"][i]["quantum"], jsonData["tasks"][i]["deadline"], i);
        tasks[i] = task;
    }

    return {jsonData["simulation_time"], jsonData["scheduler_name"], jsonData["tasks_number"], tasks};
}
