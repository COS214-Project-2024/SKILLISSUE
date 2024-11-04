#ifndef CREATE_AND_DISTRIBUTE_GOODS_H
#define CREATE_AND_DISTRIBUTE_GOODS_H

#include "CDReceiver.h"
#include "Command.h"

/**
 * @class CreateAndDistributeGoods
 * @brief Command for creating and distributing goods across the map.
 * 
 * This command class initializes the creation and distribution of goods,
 * using a receiver to handle distribution and updating revenue based on a specified tax rate.
 */
class CreateAndDistributeGoods : Command {
private:
    /** @brief Receiver responsible for handling the distribution of goods. */
    CDReceiver receiver;

    /** @brief Pointer to the map where goods are to be distributed. */
    Map* map;

    /** @brief Reference to the vector of shuffled tile indices for distribution. */
    std::vector<int>& shuffledTiles;
    
    /** @brief Reference to the industrial revenue, which will be updated by this command. */
    double& industrialRevenue;

    /** @brief Reference to the commercial revenue, which will be updated by this command. */
    double& commercialRevenue;

    /** @brief Tax rate used for revenue adjustments. */
    double taxRate;

public:
    /**
     * @brief Constructs a CreateAndDistributeGoods command with specified parameters.
     * 
     * Initializes a command to create and distribute goods by specifying a map, 
     * shuffled tile indices, revenue references, and a tax rate.
     * 
     * @param map Pointer to the Map object where goods will be distributed.
     * @param shuffledTiles Reference to a vector of shuffled tile indices.
     * @param industrialRevenue Reference to the industrial revenue variable.
     * @param commercialRevenue Reference to the commercial revenue variable.
     * @param taxRate Tax rate affecting the revenue calculation.
     */
    CreateAndDistributeGoods(Map* map, std::vector<int>& shuffledTiles, double& industrialRevenue,
               double& commercialRevenue, double taxRate);
    /**
     * @brief Executes the create and distribute goods command.
     * 
     * This method invokes the receiver to handle the creation and distribution of goods
     * across the specified map, updating industrial and commercial revenues.
     */
    void execute();
};

#endif // CREATE_AND_DISTRIBUTE_GOODS_H
