// DRReceiver.h
#ifndef DR_RECEIVER_H
#define DR_RECEIVER_H

#include "Tile.h"
#include "Map.h"
#include <vector>
#include "ResourceInterface.h"
#include "ResourceManager.h"

/**
 * @class DRReceiver
 * @brief Handles the distribution of resources across the map.
 * 
 * The DRReceiver class provides the functionality to distribute resources
 * to various tiles on the map, interacting with the ResourceManager to manage resources.
 */
class DRReceiver {

public:
     /** @brief Proxy ResourceManager used to manage resources during distribution. */
    ResourceManager proxy;

    /**
     * @brief Default constructor for DRReceiver.
     * 
     * Initializes the DRReceiver object and sets up the resource management proxy.
     */
    DRReceiver();

     /**
     * @brief Distributes resources across the tiles in the specified map.
     * 
     * This method iterates over tiles in the map and allocates resources as required,
     * using the ResourceManager to handle resource transactions.
     * 
     * @param map Pointer to the Map object where resources are distributed.
     */
    void Distribute(Map* map);
};

#endif // D_RECEIVER_H