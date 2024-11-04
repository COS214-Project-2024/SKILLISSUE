// DReceiver.h
#ifndef D_RECEIVER_H
#define D_RECEIVER_H

#include "Tile.h"
#include "Map.h"
#include <vector>

/**
 * @class DReceiver
 * @brief Handles population distribution within the map.
 * 
 * The DReceiver class is responsible for managing the distribution of population and employment
 * across different tiles in the map, applying birth and death rates and adjusting pools as needed.
 */
class DReceiver {

public:
    /**
     * @brief Default constructor for DReceiver.
     * 
     * Initializes the DReceiver object, preparing it for handling distribution tasks.
     */
    DReceiver();
    /**
     * @brief Distributes population and employment across the map tiles.
     * 
     * This function iterates over shuffled tiles and applies distribution rules
     * based on population pools, birth and death rates, and a tax rate.
     * 
     * @param map Pointer to the Map object representing the area of distribution.
     * @param shuffledTiles Reference to the vector of tile indices in shuffled order.
     * @param populationPool Reference to the population pool variable.
     * @param employmentPool Reference to the employment pool variable.
     * @param popTotal Reference to the total population count.
     * @param birthRate Rate of population increase per day.
     * @param deathRate Rate of population decrease per day.
     * @param population Current population count.
     * @param taxRate Tax rate that may impact distribution.
     */
    void distribute(Map* map, std::vector<int>& shuffledTiles, double& populationPool, double& employmentPool, 
              double& popTotal, double birthRate, double deathRate, double population, double taxRate);

    /**
     * @brief Distributes a specified amount from a pool to a given tile.
     * 
     * This helper function allocates a proportion of a resource pool to a tile
     * based on a specified rate, enabling controlled resource distribution.
     * 
     * @param pool Reference to the resource pool being distributed.
     * @param tile Pointer to the Tile where resources are allocated.
     * @param rate The rate at which resources are distributed from the pool.
     * @return The amount distributed to the tile.
     */
    double distributePool(double& pool, Tile* tile, double rate);
};

#endif // D_RECEIVER_H
