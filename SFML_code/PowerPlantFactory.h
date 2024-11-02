#ifndef POWERLANTFACTORY_H
#define POWERPLANTFACTORY_H

#include <SFML/Graphics.hpp>
#include "TileFactory.h"
#include "PowerPlant.h"

class PowerPlantFactory : public TileFactory
{
protected:
    virtual Tile* CreateTile(sf::Texture &texture, const std::vector<Animation> &animations);
public:
    Tile* Create(sf::Texture &texture, const std::vector<Animation> &animations);

    
};

#endif /* GAME_HPP */