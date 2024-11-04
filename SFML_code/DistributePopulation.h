#ifndef DISTRIBUTEPOPULATION_H
#define DISTRIBUTEPOPULATION_H

#include "Command.h"   // Make sure to include the Command header
#include "DReceiver.h"

class DistributePopulation : public Command 
{
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
    DistributePopulation(Map* map, std::vector<int>& shuffledTiles, double& populationPool, double& employmentPool, 
              double& popTotal, double birthRate, double deathRate, double population, double taxRate);

    void execute();  // Declaration only, implementation can be below or in .cpp
};

#endif // DISTRIBUTE_POPULATION_H
