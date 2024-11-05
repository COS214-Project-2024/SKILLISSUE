#ifndef SC_RECEIVER_H
#define SC_RECEIVER_H

#include "Map.h"
#include "Tile.h"
#include <vector>

/**
 * @class SCReceiver
 * @brief Responsible for calculating the satisfaction level within the simulation.
 * 
 * The SCReceiver class provides the method for calculating satisfaction based on
 * the map, tax type, and population size, updating the satisfaction metric accordingly.
 */
class SCReceiver 
{
public:
    /**
     * @brief Default constructor for SCReceiver.
     * 
     * Initializes an SCReceiver object, setting it up for satisfaction calculations.
     */
    SCReceiver();

    /**
     * @brief Calculates the satisfaction level based on provided parameters.
     * 
     * This method computes satisfaction by analyzing the map's state, tax type, 
     * and population size, and updates the provided satisfaction variable.
     * 
     * @param map Pointer to the Map object representing the area of calculation.
     * @param taxtype String representing the type of tax policy applied.
     * @param population The current population size impacting satisfaction.
     * @param satisfaction Reference to the satisfaction metric to be updated.
     */
    void Calculate(Map* map, std::string taxtype, double population, double& satisfaction);

};

#endif // SD_RECEIVER_H
