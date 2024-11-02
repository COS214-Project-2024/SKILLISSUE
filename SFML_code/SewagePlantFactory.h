#ifndef SEWAGEPLANTFACTORY_H
#define SEWAGEPLANTFACTORY_H

#include <SFML/Graphics.hpp>
#include "TileFactory.h"
#include "SewagePlant.h"

class SewagePlantFactory : public TileFactory
{
protected:
    virtual Tile* CreateTile(sf::Texture &texture, const std::vector<Animation> &animations);
public:
    Tile* Create(sf::Texture &texture, const std::vector<Animation> &animations);

    
};

#endif /* GAME_HPP */