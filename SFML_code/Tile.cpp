#include <SFML/Graphics.hpp>
 
#include "AnimationHandler.h"
#include "Tile.h"
#include "CityMediator.h"


Tile::Tile(const unsigned int tileSize, const unsigned int height, sf::Texture &texture,
     const std::vector<Animation> &animations,
     const TileType tileType, const unsigned int cost, const unsigned int maxPopPerLevel,
     const unsigned int maxLevels, double satisfaction, int consumption, int maxProduction)
{
    this->tileType = tileType;
    this->tileVariant = 0;
    this->regions[0] = 0;

    this->cost = cost;
    this->population = 0;
    this->maxPopPerLevel = maxPopPerLevel;
    this->maxLevels = maxLevels;
    this->production = 0;
    this->storedGoods = 0;

    this->sprite.setOrigin(sf::Vector2f(0.0f, tileSize * (height - 1)));
    this->sprite.setTexture(texture);
    this->animHandler.frameSize = sf::IntRect(0, 0, tileSize * 2, tileSize * height);
    for (auto animation : animations)
    {
        this->animHandler.addAnim(animation);
    }
    this->animHandler.update(0.0f);

    this->resources[ResourceType::ELECTRICITY] = 0;
    this->resources[ResourceType::WATER] = 0;
    this->resources[ResourceType::SEWAGE] = 0;
    this->resources[ResourceType::WASTE] = 0;

    this->maxResources[ResourceType::ELECTRICITY] = maxProduction;
    this->maxResources[ResourceType::WATER] = maxProduction;
    this->maxResources[ResourceType::SEWAGE] = maxProduction;
    this->maxResources[ResourceType::WASTE] = maxProduction;

    this->consumption = consumption;
    this->maxProduction = maxProduction;

    this->resourceMapping[ResourceType::ELECTRICITY] = TileType::POWERPLANT;
    this->resourceMapping[ResourceType::WATER] = TileType::WATERPLANT;
    this->resourceMapping[ResourceType::SEWAGE] = TileType::SEWAGEPLANT;
    this->resourceMapping[ResourceType::WASTE] = TileType::WASTEMANAGEMENT;

    this->satisfaction = satisfaction;
}

Tile::Tile(Tile* tile)
{
    this->tileType = tile->tileType;
    this->tileVariant = 0;
    this->regions[0] = 0;

    this->cost = tile->cost;
    this->population = 0;
    this->maxPopPerLevel = tile->maxPopPerLevel;
    this->maxLevels = tile->maxLevels;
    this->production = 0;
    this->storedGoods = 0;
    this->satisfaction = tile->satisfaction;

    this->sprite = tile->sprite;
    
    this->animHandler.frameSize = tile->animHandler.frameSize;
    this->animHandler = tile->animHandler;
    this->animHandler.update(0.0f);

    this->resources[ResourceType::ELECTRICITY] = 0;
    this->resources[ResourceType::WATER] = 0;
    this->resources[ResourceType::SEWAGE] = 0;
    this->resources[ResourceType::WASTE] = 0;

    this->maxResources[ResourceType::ELECTRICITY] = tile->maxProduction;
    this->maxResources[ResourceType::WATER] = tile->maxProduction;
    this->maxResources[ResourceType::SEWAGE] = tile->maxProduction;
    this->maxResources[ResourceType::WASTE] = tile->maxProduction;

    this->consumption = tile->consumption;
    this->maxProduction = tile->maxProduction;

    this->resourceMapping[ResourceType::ELECTRICITY] = TileType::POWERPLANT;
    this->resourceMapping[ResourceType::WATER] = TileType::WATERPLANT;
    this->resourceMapping[ResourceType::SEWAGE] = TileType::SEWAGEPLANT;
    this->resourceMapping[ResourceType::WASTE] = TileType::WASTEMANAGEMENT;

}

Tile* Tile::clone()
{
    return new Tile(*this);
}

void Tile::draw(sf::RenderWindow& window, float dt)
{
    /* Change the sprite to reflect the tile variant */
    this->animHandler.changeAnim(this->tileVariant);
 
    /* Update the animation */
    this->animHandler.update(dt);
 
    /* Update the sprite */
    this->sprite.setTextureRect(this->animHandler.bounds);
 
    /* Draw the tile */
    window.draw(this->sprite);
 
    return;
}
 
void Tile::update()
{
    /* If the population is at the maximum value for the tile,
     * there is a small chance that the tile will increase its
     * building stage */
    if((this->tileType == TileType::RESIDENTIAL ||
        this->tileType == TileType::COMMERCIAL ||
        this->tileType == TileType::INDUSTRIAL ||
        this->tileType == TileType::LANDMARK ||
        this->tileType == TileType::HOSPITAL ||
        this->tileType == TileType::FIRESTATION) &&
        this->population == this->maxPopPerLevel * (this->tileVariant+1) &&
        this->tileVariant < this->maxLevels)
    {
        if(rand() % int(1e4) < 1e2 / (this->tileVariant+1)) ++this->tileVariant;
    }
    else if((this->tileType == TileType::POWERPLANT ||
            this->tileType == TileType::SEWAGEPLANT ||
            this->tileType == TileType::WATERPLANT ||
            this->tileType == TileType::WASTEMANAGEMENT) &&
            this->tileVariant < this->maxLevels)
    {
        if(rand() % int(1e4) < 1e2 / (this->tileVariant+1)) ++this->tileVariant;
    }
 
}
/* Return a string containing the display cost of the tile */
std::string Tile::getCost()
{
    return std::to_string(this->cost);
}

std::string tileTypeToStr(TileType type)
{
    switch(type)
    {
        default:
        case TileType::VOID:            return "Void";
        case TileType::ROAD:           return "Road";
        case TileType::GRASS:           return "Flatten";
        case TileType::FOREST:          return "Forest";
        case TileType::WATER:           return "Water";
        case TileType::RESIDENTIAL:     return "Residential Zone";
        case TileType::COMMERCIAL:      return "Commercial Zone";
        case TileType::INDUSTRIAL:      return "Industrial Zone";
        case TileType::LANDMARK:        return "Landmark Zone";
        case TileType::FIRESTATION:     return "Fire Station";
        case TileType::HOSPITAL:        return "Hospital";
        case TileType::POWERPLANT:      return "Power Plant";
        case TileType::SEWAGEPLANT:     return "Sewage Plant";
        case TileType::WATERPLANT:      return "Water Plant";
        case TileType::WASTEMANAGEMENT: return "Waste Disposal";
    }
}

void Tile::setMediator(CityMediator* mediator){
    this->mediator = mediator;
}

void Tile::notify(TileType notification){
        if (this->mediator) {
        this->mediator->notify(this, notification);
    }
}

void Tile::addSatisfaction(double num){
    this->satisfaction += num;
}
void Tile::removeSatisfaction(double num){
    this->satisfaction -= num;
}
double Tile::getSatisfaction(){
    return satisfaction;
}
void Tile::produceResource(ResourceType resource, int amount){

    if(maxResources[resource] - resources[resource] < amount){
        resources[resource] += maxResources[resource] - resources[resource];
    }
    else 
    {
        resources[resource] += amount;
    }
}

void Tile::consumeResource(ResourceType resource, int amount){

    //Ask for more resources
    if(resources[resource] == 0){
        mediator->notify(this, resourceMapping[resource]);
        return;
    } 

    resources[resource] -= amount;
}

void Tile::setMaxResource(ResourceType resource, int amount){

    if(resources[resource] > amount){
        return;
    }
    
    maxResources[resource] = amount;
}
