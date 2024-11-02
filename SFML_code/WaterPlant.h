#ifndef WATERPLANT_H
#define WATERPLANT_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Tile.h"

class WaterPlant : public Tile
{
public:

    /* Constructor */
    WaterPlant(sf::Texture &texture, const std::vector<Animation> &animations);

};

#endif /* TILE_HPP */