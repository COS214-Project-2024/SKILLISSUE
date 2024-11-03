#include "DistributePopulation.h"

DistributePopulation::DistributePopulation(Map* map, std::vector<int>& shuffledTiles, double& populationPool, double& employmentPool, 
                                        double& popTotal, double birthRate, double deathRate, double population, double taxRate)
                                        : map(map), shuffledTiles(shuffledTiles), populationPool(populationPool), 
                                        employmentPool(employmentPool), popTotal(popTotal), birthRate(birthRate), 
                                        deathRate(deathRate), population(population), taxRate(taxRate) {}

void DistributePopulation::execute() {
    receiver.distribute(map, shuffledTiles, populationPool, employmentPool, 
              popTotal, birthRate,  deathRate, population, taxRate);  // Calls the receiver's distribute function
}
