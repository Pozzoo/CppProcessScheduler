#include "managers/JsonManager.h"
#include "data/SimulationSpecs.h"
#include "data/Task.h"
#include "managers/SimulationManager.h"

using namespace std;

int main() {
    SimulationSpecs simulationSpecs = JsonManager::readJson(R"(..\examples\exemplo_sched.json)");
    SimulationSpecs simulationSpecs1 = JsonManager::readJson(R"(..\examples\exemplo_rm.json)");
    SimulationSpecs simulationSpecs2 = JsonManager::readJson(R"(..\examples\exemplo_edf.json)");

    std::vector<Task> tasks = simulationSpecs.getTasks();

    SimulationManager simulationManager = SimulationManager();
    simulationManager.startSimulation(simulationSpecs2);

    return 0;
}