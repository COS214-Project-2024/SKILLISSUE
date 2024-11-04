#ifndef SASTISFACTIONCALCULATOR_H
#define SASTISFACTIONCALCULATOR_H
 
#include "Command.h"
#include "SCReceiver.h"

/**
 * @class SatisfactionCalculator
 * @brief Command class responsible for calculating the satisfaction level of the population.
 * 
 * The SatisfactionCalculator class inherits from Command and uses an SCReceiver to
 * calculate satisfaction based on factors like tax type, population, and map data.
 */
class SatisfactionCalculator : public Command{
private:
    /** @brief Receiver responsible for executing satisfaction-related calculations. */
    SCReceiver receiver;

    /** @brief Pointer to the map used to retrieve satisfaction-related data. */
    Map* map;
    /** @brief Type of tax policy affecting satisfaction. */
    std::string taxtype;
    /** @brief Current population size impacting satisfaction. */
    double population;
    /** @brief Reference to the satisfaction metric that will be updated. */
    double& satisfaction;

public:
    /**
     * @brief Constructs a SatisfactionCalculator command.
     * 
     * Initializes the SatisfactionCalculator with required parameters, allowing it
     * to calculate satisfaction based on map data, tax type, and population.
     * 
     * @param map Pointer to the Map object used in satisfaction calculation.
     * @param taxtype String representing the type of tax policy applied.
     * @param population Current population size.
     * @param satisfaction Reference to the satisfaction value that will be updated.
     */
    SatisfactionCalculator(Map* map, std::string taxtype, double population, double& satisfaction);
     /**
     * @brief Executes the satisfaction calculation command.
     * 
     * This method uses the receiver to compute satisfaction based on the provided
     * map, tax type, population, and updates the satisfaction value accordingly.
     */
    void execute();
};

#endif // SASTISFACTIONCALCULATOR_H
