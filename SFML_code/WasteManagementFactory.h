#ifndef WASTEMANAGEMENTFACTORY_H
#define WASTEMANAGEMENTFACTORY_H

#include <SFML/Graphics.hpp>
#include "TileFactory.h"
#include "Residential.h"

class WasteManagementFactory : public TileFactory
{
protected:
    virtual Tile* CreateTile(sf::Texture &texture, const std::vector<Animation> &animations);
public:
    Tile* Create(sf::Texture &texture, const std::vector<Animation> &animations);

    
};

#endif /* GAME_HPP */