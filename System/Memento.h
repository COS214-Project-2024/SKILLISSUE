#ifndef MEMENTO_H
#define MEMENTO_H

#include "Map.h"
class City;      // Forward declaration
class Caretaker; // Forward declaration

/**
 * @brief The Memento class stores the state of a City, allowing it to be saved and restored.
 */
class Memento {
    friend class City;  ///< Grant City access to private members for state manipulation.

private:
    double populationPool;   ///< Holds the current population pool of the city.
    double employmentPool;   ///< Holds the current employment pool of the city.
    double population;       ///< Current population count of the city.
    double employable;       ///< Number of employable citizens in the city.
    double satisfaction;     ///< Represents the satisfaction level of the city's citizens.
    double earnings;         ///< Current earnings of the city.
    double funds;            ///< Total available funds of the city.
    int day;                 ///< Current simulation day.
    Map* map;                ///< Pointer to the Map object representing the city's structure.

public:
    /**
     * @brief Constructor for the Memento class.
     * @param populationPool Current population pool.
     * @param employmentPool Current employment pool.
     * @param population Current population count.
     * @param employable Number of employable citizens.
     * @param satisfaction Satisfaction level of the citizens.
     * @param earnings Current earnings of the city.
     * @param funds Available funds of the city.
     * @param day Current day in the simulation.
     * @param map Pointer to the Map object representing the city's structure.
     */
    Memento(double populationPool, double employmentPool, double population, double employable,
            double satisfaction, double earnings, double funds, int day, Map* map = nullptr );

    /**
     * @brief Gets the population pool of the city.
     * @return The population pool.
     */
    double getPopulationPool() const { return populationPool; }

    /**
     * @brief Gets the employment pool of the city.
     * @return The employment pool.
     */
    double getEmploymentPool() const { return employmentPool; }

    /**
     * @brief Gets the current population count of the city.
     * @return The population count.
     */
    double getPopulation() const { return population; }

    /**
     * @brief Gets the number of employable citizens in the city.
     * @return The number of employable citizens.
     */
    double getEmployable() const { return employable; }

    /**
     * @brief Gets the satisfaction level of the city's citizens.
     * @return The satisfaction level.
     */
    double getSatisfaction() const { return satisfaction; }

    /**
     * @brief Gets the current earnings of the city.
     * @return The earnings.
     */
    double getEarnings() const { return earnings; }

    /**
     * @brief Gets the available funds of the city.
     * @return The available funds.
     */
    double getFunds() const { return funds; }

    /**
     * @brief Gets the current day in the simulation.
     * @return The day.
     */
    int getDay() const { return day; }

    /**
     * @brief Gets the map of the city.
     * @return Pointer to the Map object.
     */
    Map* getMap() const { return map; }
};

#endif // MEMENTO_H
