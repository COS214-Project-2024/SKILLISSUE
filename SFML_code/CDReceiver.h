#ifndef CD_RECEIVER_H
#define CD_RECEIVER_H

#include "Map.h"
#include "Tile.h"
#include <vector>

/**
 * @class CDReceiver
 * @brief Handles the creation and distribution of goods across a map, using tax and revenue calculations.
 * 
 * This class manages the distribution of goods to tiles based on the given map,
 * shuffled tiles, revenue values, and tax rate.
 */
class CDReceiver {

public:
    /**
     * @brief Default constructor for CDReceiver.
     * 
     * Initializes the CDReceiver with necessary references to resources and revenue parameters.
     */
    CDReceiver();


    /**
     * @brief Creates and distributes goods across the map.
     * 
     * This function calculates and allocates goods to different tiles on the map based on 
     * shuffled tile indices, and adjusts industrial and commercial revenue according to the tax rate.
     * 
     * @param map Pointer to the Map object containing tiles.
     * @param shuffledTiles Vector of tile indices in shuffled order for distribution.
     * @param industrialRevenue Reference to the industrial revenue variable to be updated.
     * @param commercialRevenue Reference to the commercial revenue variable to be updated.
     * @param taxRate The current tax rate affecting revenue calculations.
     */
    void createAndDistributeGoods(Map* map, std::vector<int>& shuffledTiles, double& industrialRevenue,
               double& commercialRevenue, double taxRate);
};

#endif // CD_RECEIVER_H
