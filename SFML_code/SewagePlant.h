#ifndef SEWAGEPLANT_H
#define SEWAGEPLANT_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Tile.h"

class SewagePlant : public Tile
{
public:

    /* Constructor */
    SewagePlant(sf::Texture &texture, const std::vector<Animation> &animations);

};

#endif /* TILE_HPP */