#ifndef HOSPITALTFACTORY_H
#define HOSPITALFACTORY_H

#include <SFML/Graphics.hpp>
#include "TileFactory.h"
#include "Hospital.h"

class HospitalFactory : public TileFactory
{
protected:
    virtual Tile* CreateTile(sf::Texture &texture, const std::vector<Animation> &animations);
public:
    Tile* Create(sf::Texture &texture, const std::vector<Animation> &animations);

    
};

#endif /* GAME_HPP */