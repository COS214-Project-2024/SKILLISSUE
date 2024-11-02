#ifndef POWERPLANT_H
#define POWERPLANT_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Tile.h"

class PowerPlant : public Tile
{
public:

    /* Constructor */
    PowerPlant(sf::Texture &texture, const std::vector<Animation> &animations);

};

#endif /* TILE_HPP */