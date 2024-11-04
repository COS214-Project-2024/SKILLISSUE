#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <map>

#include "AnimationHandler.h"
//#include "CityMediator.h"
class CityMediator;

/**
 * @enum TileType
 * @brief Enumeration representing various types of tiles.
 * 
 * TileType includes different categories of tiles, such as residential, commercial,
 * industrial, utility, and environmental tiles, each serving a unique function.
 */
enum class TileType
{
    VOID,
    GRASS,
    FOREST,
    WATER,
    RESIDENTIAL,
    COMMERCIAL,
    INDUSTRIAL,
    LANDMARK,
    ROAD,
    FIRESTATION,
    HOSPITAL,
    POWERPLANT,
    SEWAGEPLANT,
    WATERPLANT,
    WASTEMANAGEMENT
};

/**
 * @enum ResourceType
 * @brief Enumeration representing different types of resources managed by tiles.
 * 
 * ResourceType includes resources like electricity, water, sewage, and waste, which
 * are produced or consumed by specific tile types.
 */
enum class ResourceType
{
    ELECTRICITY,
    WATER,
    SEWAGE,
    WASTE
};

/**
 * @brief Converts a TileType to a string representation.
 * 
 * @param type The TileType to convert.
 * @return A string representing the TileType.
 */
std::string tileTypeToStr(TileType type);

/**
 * @class Tile
 * @brief Base class representing a single tile in the simulation.
 * 
 * The Tile class manages attributes such as type, resources, cost, population, 
 * satisfaction, and production. It also includes methods for updating, drawing,
 * and interacting with other tiles.
 */
class Tile
{
private:
    /**
     * @brief Copy constructor for cloning tiles.
     * 
     * @param tile Pointer to the tile to be cloned.
     */
    Tile(Tile* tile);

    /** @brief Mapping of resources to required tile types for specific resources. */
    std::map<ResourceType, TileType> resourceMapping;

public:
    /** @brief Mediator for handling interactions with other city components. */
    CityMediator* mediator;

    /**
     * @brief Sets the mediator for the tile.
     * 
     * @param mediator Pointer to the CityMediator handling interactions.
     */
    void setMediator(CityMediator* mediator);
    
    /**
     * @brief Notifies the mediator of a specific event for this tile.
     * 
     * @param notification Type of event or notification to send.
     */
    void notify(TileType notification);
    
    /** @brief Resources available at this tile, mapped by ResourceType. */
    std::map<ResourceType,int> resources;

    /** @brief Maximum allowed resources at this tile, with default of 100 each. */
    std::map<ResourceType,int> maxResources;
    
    /**
     * @brief Produces a specified amount of a given resource.
     * 
     * @param resource The type of resource to produce.
     * @param amount The amount of resource to add.
     */
    void produceResource(ResourceType resource, int amount);

    /**
     * @brief Consumes a specified amount of a given resource.
     * 
     * @param resource The type of resource to consume.
     * @param amount The amount of resource to deduct.
     */
    void consumeResource(ResourceType resource, int amount);

    /**
     * @brief Sets the maximum amount for a specific resource.
     * 
     * @param resource The type of resource.
     * @param amount The maximum allowable amount.
     */
    void setMaxResource(ResourceType resource, int amount);

    /** @brief Animation handler for the tile's animation sequence. */
    AnimationHandler animHandler;

    /** @brief Sprite representing the visual appearance of the tile. */
    sf::Sprite sprite;

    /** @brief Type of tile (e.g., residential, industrial, etc.). */
    TileType tileType;

    /** @brief Variant for different appearances of the same tile type. */
    int tileVariant;

    /** @brief Region IDs to identify connectivity; first is for transport. */
    unsigned int regions[1];

    /** @brief Cost of placing the tile in the simulation. */
    unsigned int cost;

    /** @brief Current population residing or employed on this tile. */
    double population;

    /** @brief Maximum population per growth stage. */
    unsigned int maxPopPerLevel;

    /** @brief Maximum number of building levels for the tile. */
    unsigned int maxLevels;

    /** @brief Production output per worker or customer per day. */
    float production;

    /** @brief Goods stored by the tile. */
    float storedGoods;
    
    /** @brief Satisfaction level of the tile. */
    double satisfaction;

    /** @brief Resource consumption rate. */
    int consumption;

    /** @brief Maximum production capacity of the tile. */
    int maxProduction;

    /**
     * @brief Default constructor for Tile.
     */
    Tile() {}

    /**
     * @brief Parameterized constructor to initialize a Tile with attributes.
     * 
     * @param tileSize Size of the tile in pixels.
     * @param height Height of the tile in pixels.
     * @param texture Texture applied to the tile.
     * @param animations Vector of animations associated with the tile.
     * @param tileType Type of the tile.
     * @param cost Placement cost of the tile.
     * @param maxPopPerLevel Maximum population per growth stage.
     * @param maxLevels Maximum number of building levels.
     * @param satisfaction Initial satisfaction level.
     * @param consumption Rate of resource consumption.
     * @param maxProduction Maximum production capacity.
     */
    Tile(const unsigned int tileSize, const unsigned int height, sf::Texture &texture,
         const std::vector<Animation> &animations,
         const TileType tileType, const unsigned int cost, const unsigned int maxPopPerLevel,
         const unsigned int maxLevels, double satisfaction, int consumption, int maxProduction);

    /**
     * @brief Draws the tile on the specified window.
     * 
     * @param window The render window.
     * @param dt Delta time for frame-based updates.
     */
    void draw(sf::RenderWindow &window, float dt);

    /**
     * @brief Updates the tile's state.
     */
    void update();

    /**
     * @brief Returns the displayable cost of the tile as a string.
     * 
     * @return A string representing the tile's cost.
     */
    std::string getCost();

    /**
     * @brief Increases the satisfaction level of the tile.
     * 
     * @param num Amount to increase satisfaction by.
     */
    void addSatisfaction(double num);

    /**
     * @brief Decreases the satisfaction level of the tile.
     * 
     * @param num Amount to decrease satisfaction by.
     */
    void removeSatisfaction(double num);
    
    /**
     * @brief Retrieves the current satisfaction level of the tile.
     * 
     * @return The satisfaction level as a double.
     */
    double getSatisfaction();

    /**
     * @brief Retrieves the current satisfaction level of the tile.
     * 
     * @return The satisfaction level as a double.
     */
    Tile* clone();
};

#endif /* TILE_HPP */
