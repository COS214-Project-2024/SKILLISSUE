#ifndef FIRESTATION_H
#define FIRESTATION_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Tile.h"

class Firestation : public Tile
{
public:

    /* Constructor */
    Firestation(sf::Texture &texture, const std::vector<Animation> &animations);

};

#endif /* TILE_HPP */