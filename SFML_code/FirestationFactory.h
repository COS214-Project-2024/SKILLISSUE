#ifndef FIRESTATIONFACTORY_H
#define FIRESTATIONFACTORY_H

#include <SFML/Graphics.hpp>
#include "TileFactory.h"
#include "Firestation.h"

class FirestationFactory : public TileFactory
{
protected:
    virtual Tile* CreateTile(sf::Texture &texture, const std::vector<Animation> &animations);
public:
    Tile* Create(sf::Texture &texture, const std::vector<Animation> &animations);

    
};

#endif /* GAME_HPP */