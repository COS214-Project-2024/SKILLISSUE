#ifndef DISTRIBUTE_RESOURCES_H
#define DISTRIBUTE_RESOURCES_H

#include "Command.h"   // Make sure to include the Command header
#include "DReceiver.h"

class DistributeResources : public Command {
private:
    DReceiver receiver;
    Map* map;
    std::vector<int>& shuffledTiles;
    double& populationPool;
    double& employmentPool;
    double& popTotal;
    double birthRate;
    double deathRate;
    double population;
    double taxRate;

public:
    DistributeResources(Map* map, std::vector<int>& shuffledTiles, double& populationPool, double& employmentPool, 
              double& popTotal, double birthRate, double deathRate, double population, double taxRate);

    void execute();  // Declaration only, implementation can be below or in .cpp
};

#endif // DISTRIBUTE_RESOURCES_H
