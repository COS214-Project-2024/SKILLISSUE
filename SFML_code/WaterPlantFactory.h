#ifndef WATERPLANTFACTORY_H
#define WATERPLANTFACTORY_H

#include <SFML/Graphics.hpp>
#include "TileFactory.h"
#include "WaterPlant.h"

class WaterPlantFactory : public TileFactory
{
protected:
    virtual Tile* CreateTile(sf::Texture &texture, const std::vector<Animation> &animations);
public:
    Tile* Create(sf::Texture &texture, const std::vector<Animation> &animations);

    
};

#endif /* GAME_HPP */
