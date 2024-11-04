#ifndef DISTRIBUTE_RESOURCES_H
#define DISTRIBUTE_RESOURCES_H

#include "DRReceiver.h"
#include "Command.h"

/**
 * @class DistributeResources
 * @brief Command for distributing resources across the map.
 * 
 * The DistributeResources class is responsible for managing the distribution of resources
 * by interacting with a DRReceiver and updating the map as needed.
 */
class DistributeResources : Command {
private:
    /** @brief Receiver responsible for handling resource distribution logic. */
    DRReceiver receiver;

    /** @brief Pointer to the map where resources are distributed. */
    Map* map;

public:
    /**
     * @brief Constructs a DistributeResources command with a specified map.
     * 
     * Initializes a command for resource distribution, specifying the map to which resources
     * will be distributed.
     * 
     * @param map Pointer to the Map object where resources will be distributed.
     */
    DistributeResources(Map* map);
    
    /**
     * @brief Executes the resource distribution command.
     * 
     * This method uses the receiver to distribute resources across the specified map,
     * interacting with each tile as necessary.
     */
    void execute();
};

#endif // CREATE_AND_DISTRIBUTE_GOODS_H
