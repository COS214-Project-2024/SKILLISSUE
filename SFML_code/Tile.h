#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <map>

#include "AnimationHandler.h"
//#include "CityMediator.h"
class CityMediator;

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

enum class ResourceType
{
    ELECTRCITY,
    WATER,
    SEWAGE,
    WASTE
};

std::string tileTypeToStr(TileType type);

class Tile
{
private:
    Tile(Tile* tile);
    std::map<ResourceType, TileType> resourceMapping;

public:
    CityMediator* mediator;
    void setMediator(CityMediator* mediator);
    void notify(TileType notification);
    
    std::map<ResourceType,int> resources;
    std::map<ResourceType,int> maxResources; //defaults to 100 each
    void produceResource(ResourceType resource, int amount);
    void consumeResource(ResourceType resource, int amount);
    void setMaxResource(ResourceType resource, int amount);

    int satisfaction;

    AnimationHandler animHandler;
    sf::Sprite sprite;

    TileType tileType;

    /* Tile variant, allowing for different looking versions of the
     * same tile */
    int tileVariant;

    /* Region IDs of the tile, tiles in the same region are connected.
     * First is for transport */
    unsigned int regions[1];

    /* Placement cost of the tile */
    unsigned int cost;

    /* Current residents / employees */
    double population;
    /* Maximum population per growth stage / tile variant */
    unsigned int maxPopPerLevel;
    /* Maximum number of building levels */
    unsigned int maxLevels;
    /* Production output per customer/worker per day, either monetary or goods */
    float production;
    /* Goods stored */
    float storedGoods;
    /* satisfaction of building */
    int satisfaction;

    /* Constructor */
    Tile() {}
    Tile(const unsigned int tileSize, const unsigned int height, sf::Texture &texture,
         const std::vector<Animation> &animations,
         const TileType tileType, const unsigned int cost, const unsigned int maxPopPerLevel,
         const unsigned int maxLevels, const unsigned int satisfaction);

    void draw(sf::RenderWindow &window, float dt);

    void update();

    /* Return a string containing the display cost of the tile */
    std::string getCost();

    void addSatisfaction(int num);
    void removeSatisfaction(int num);
    int getSatisfaction();

    Tile* clone();
};

#endif /* TILE_HPP */
