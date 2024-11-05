#ifndef CITYMEDIATOR_H
#define CITYMEDIATOR_H


#include "Tile.h"
#include "City.h"
#include <string>

/**
 * @class CityMediator
 * @brief Acts as a mediator for coordinating actions within the city.
 * 
 * The CityMediator class facilitates communication between the city and its tiles,
 * reacting to changes in tile states and providing city services like power, water, and waste management.
 */
class CityMediator{
    private:
    /** @brief Pointer to the city that this mediator serves. */
    City* city;

    /**
     * @brief Internal function that reacts to changes in the city or tile states.
     * 
     * This function defines the behavior of the mediator in response to notifications
     * or state changes within the city.
     */
    void react();

    public:

    /**
     * @brief Default constructor for the CityMediator class.
     * 
     * Initializes an instance of the CityMediator without assigning a city.
     */
    CityMediator();

    /**
     * @brief Parameterized constructor that assigns a city to the mediator.
     * 
     * @param city Pointer to the City object that the mediator will manage.
     */
    CityMediator(City* city);

    /**
     * @brief Assigns a city to the mediator.
     * 
     * @param city Pointer to the City object to be managed by this mediator.
     */
    void setCity(City* city);

    /**
     * @brief Retrieves a copy of the current city.
     * 
     * @param city Reference to the City object to populate with the current city data.
     */
    void getCity(City city);

    /**
     * @brief Notifies the mediator of a change in a specific tile.
     * 
     * This function processes notifications from tiles, adjusting city services or
     * performing reactions based on the type of notification.
     * 
     * @param tile Pointer to the Tile that triggered the notification.
     * @param notification The type of notification related to the tile's change.
     */
    void notify(Tile* tile, TileType notification);

    /**
     * @brief Initiates action to handle a house fire on the specified tile.
     * 
     * @param tile Pointer to the Tile where the house fire is located.
     */
    void burnHouse(Tile* tile);

    /**
     * @brief Supplies power to the specified tile.
     * 
     * @param tile Pointer to the Tile that requires power.
     */
    void getPower(Tile* tile);

    /**
     * @brief Supplies water to the specified tile.
     * 
     * @param tile Pointer to the Tile that requires water.
     */
    void getWater(Tile* tile);

    /**
     * @brief Handles waste disposal for the specified tile.
     * 
     * @param tile Pointer to the Tile that requires waste disposal.
     */
    void disposeWaste(Tile* tile);
    /**
     * @brief Treats sewage for the specified tile.
     * 
     * @param tile Pointer to the Tile that requires sewage treatment.
     */
    void treatSewage(Tile* tile);
    //add more later
};

#endif