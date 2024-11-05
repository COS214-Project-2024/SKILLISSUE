#ifndef CITY_H
#define CITY_H

#include <vector>
#include <map>

#include "Map.h"
#include "Tile.h"

#include "TaxPolicy.h"
#include "LowTax.h"
#include "MidTax.h"
#include "HighTax.h"
#include "Memento.h"
#include "CityMediator.h"
#include "Command.h"
#include "DistributePopulation.h"
#include "SatisfactionCalculator.h"
#include "CreateAndDistributeGoods.h"
#include "DistributeResources.h"

// Forward declaration
class Memento;      
class Caretaker;   
class cityMediator; 

/**
 * @class City
 * @brief Represents a city with its population, tax policies, and economic properties.
 * 
 * The City class manages various attributes such as population, employment, tax revenue,
 * and allows interactions through the Mediator and Memento patterns.
 */
class City
{
protected:
    /** @brief The current time in the simulation. */
    float currentTime;
    
    /** @brief Time duration that represents one day in the simulation. */
    float timePerDay;

    /** @brief Pointer to a mediator for coordinating actions within the city. */
    CityMediator* mediator;

    /** @brief The city's current tax policy. */
    TaxPolicy* taxPolicy;

    /** @brief Vector containing shuffled tile indices for resource distribution. */
    std::vector<int> shuffledTiles;

    /** @brief Number of residents who are not in a residential zone. */
    double populationPool;

    /** @brief Number of residents who are unemployed but capable of working. */
    double employmentPool;

    /** @brief Proportion of citizens capable of working. */
    float propCanWork;

    /** @brief Birth rate of the city's population per day. */
    double birthRate;

    /** @brief Death rate of the city's population per day. */
    double deathRate;

    /** @brief Helper function to distribute resources from a pool to a tile. */
    double distributePool(double &pool, Tile *tile, double rate);

    /** @brief The day when the last memento was created. */
    int lastMementoDay;

    /** @brief Pointer to the caretaker managing mementos for state restoration. */
    Caretaker* caretaker;
    
public:
    /**
    * @brief Grants the CityMediator class access to City’s private and protected members.
    * 
    * Declaring CityMediator as a friend class allows it to directly access and modify
    * private and protected members of City, facilitating coordinated interactions and 
    * communication between the city and mediator.
    */
    friend class CityMediator;

    /** @brief Pointer to the city's map containing all tiles. */
    Map* map;

    /** @brief Total population of the city. */
    double population;

    /** @brief Total number of citizens eligible for employment. */
    double employable;

    /** @brief Overall satisfaction score of the city's population. */
    double satisfaction;

    /** @brief Earnings of the city from tax and other sources, calculated monthly. */
    double earnings;

    /** @brief City's available funds for spending and development. */
    double funds;

    /** @brief The current day in the city's simulation timeline. */
    int day;

    /**
     * @brief Default constructor initializing default city parameters.
     * 
     * Sets initial rates, pools, and the default tax policy.
     */
    City()
    {
        this->birthRate = 0.00055;
        this->deathRate = 0.00023;
        this->propCanWork = 0.50;
        this->populationPool = 0;
        this->population = populationPool;
        this->employmentPool = 0;
        this->employable = employmentPool;
        this->earnings = 0;
        this->funds = 0;
        this->currentTime = 0.0;
        this->timePerDay = 0.7;
        this->day = 0;
        this->taxPolicy = new LowTax();
        this->map = new Map();
        this->satisfaction=0;
    }

    /**
     * @brief Parameterized constructor for initializing a city with a given map.
     * 
     * @param cityName Name of the city to load.
     * @param tileSize Size of each tile on the map.
     * @param tileAtlas Map of tile types used within the city.
     */
    City(std::string cityName, int tileSize, std::map<std::string, Tile*> &tileAtlas) : City()
    {
        this->map->tileSize = tileSize;
        load(cityName, tileAtlas);
    }

    /**
     * @brief Loads city data from a saved state.
     * 
     * @param cityName Name of the city to load.
     * @param tileAtlas Reference map of tile types used in the city.
     */
    void load(std::string cityName, std::map<std::string, Tile*> &tileAtlas);

     /**
     * @brief Saves the current state of the city.
     * 
     * @param cityName Name of the city to save.
     */
    void save(std::string cityName);

    /**
     * @brief Updates the city simulation by advancing time.
     * 
     * @param dt Time delta representing the elapsed time since the last update.
     */
    void update(float dt);

    /**
     * @brief Demolishes the specified tile in the city.
     * 
     * @param tile The tile to bulldoze.
     */
    void bulldoze(Tile &tile);

     /**
     * @brief Randomly shuffles tiles for distributing resources.
     */
    void shuffleTiles();

    /**
     * @brief Notifies the city that a tile has changed.
     */
    void tileChanged();

    /**
     * @brief Retrieves the current homeless population count.
     * 
     * @return The number of homeless residents.
     */
    double getHomeless() { return this->populationPool; }

    /**
     * @brief Retrieves the current unemployed population count.
     * 
     * @return The number of unemployed residents.
     */
    double getUnemployed() { return this->employmentPool; }

    /**
     * @brief Sets the city's tax policy.
     * 
     * @param policy Pointer to the TaxPolicy to be applied.
     */
    void setTaxPolicy(TaxPolicy* policy);

     /**
     * @brief Retrieves the name of the current tax policy.
     * 
     * @return The name of the tax policy as a string.
     */
    std::string getTaxPolicy();


/**
 * @brief Sets the caretaker for the Memento.
 * 
 * This function sets a pointer to a `Caretaker` object, which is responsible 
 * for handling the Memento's lifecycle.
 * 
 * @param caretaker Pointer to a `Caretaker` object.
 */
void setCaretaker(Caretaker* caretaker);

/**
 * @brief Creates a new memento representing the current state.
 * 
 * This function generates a `Memento` object that encapsulates the 
 * current state, enabling the state to be restored at a later time.
 * 
 * @return A pointer to the newly created `Memento` object.
 */
Memento* createMemento();

/**
 * @brief Restores the state from a memento.
 * 
 * This function loads the state encapsulated in a given `Memento` object.
 * The `Memento` should have been created by `createMemento()`.
 * 
 * @param memento Pointer to the `Memento` object containing the state to restore.
 */
void loadMemento(Memento* memento);

/**
 * @brief Undoes the current state by reverting to a previous memento.
 * 
 * This function takes a `Memento` object and undoes the current changes by 
 * restoring the state from the specified `Memento`.
 * 
 * @param memento The `Memento` object containing the state to revert to.
 */
void undo(Memento memento);

/**
 * @brief Sets the mediator for the city.
 * 
 * This function sets a pointer to a `CityMediator` object, enabling communication 
 * between different city components through the mediator.
 * 
 * @param md Pointer to a `CityMediator` object.
 */
void setMediator(CityMediator* md);
};

#endif /* CITY_HPP */
