#ifndef DISTRIBUTEPOPULATION_H
#define DISTRIBUTEPOPULATION_H

#include "Command.h"   
#include "DReceiver.h"

/**
 * @class DistributePopulation
 * @brief Command for distributing population across the map.
 * 
 * This command handles population distribution, adjusting birth and death rates,
 * and managing the employment pool, while interacting with the specified map.
 */
class DistributePopulation : public Command 
{
private:
    /** @brief Receiver responsible for population distribution actions. */
    DReceiver receiver;
    
    /** @brief Pointer to the map where population is distributed. */
    Map* map;

    /** @brief Reference to the vector of shuffled tile indices for distribution. */
    std::vector<int>& shuffledTiles;

    /** @brief Reference to the pool of unallocated population. */
    double& populationPool;

    /** @brief Reference to the pool of employable population. */
    double& employmentPool;

    /** @brief Reference to the total population count. */
    double& popTotal;

    /** @brief Birth rate for the population growth calculation. */
    double birthRate;

    /** @brief Death rate for the population reduction calculation. */
    double deathRate;

    /** @brief Current population count. */
    double population;

    /** @brief Tax rate influencing population-related revenue calculations. */
    double taxRate;

public:
    /**
     * @brief Constructs a DistributePopulation command.
     * 
     * Initializes a command for population distribution with specified parameters
     * including map, tile order, population and employment pools, and rates.
     * 
     * @param map Pointer to the Map object where population is distributed.
     * @param shuffledTiles Reference to a vector of shuffled tile indices.
     * @param populationPool Reference to the population pool variable.
     * @param employmentPool Reference to the employment pool variable.
     * @param popTotal Reference to the total population count.
     * @param birthRate Birth rate for population growth.
     * @param deathRate Death rate for population reduction.
     * @param population Current population count.
     * @param taxRate Tax rate affecting population-based revenue.
     */
    DistributePopulation(Map* map, std::vector<int>& shuffledTiles, double& populationPool, double& employmentPool, 
              double& popTotal, double birthRate, double deathRate, double population, double taxRate);

    /**
     * @brief Executes the population distribution command.
     * 
     * This method performs the distribution of population across tiles, adjusting
     * pools and rates based on the map and other parameters.
     */
    void execute();  // Declaration only, implementation can be below or in .cpp
};

#endif // DISTRIBUTE_POPULATION_H
