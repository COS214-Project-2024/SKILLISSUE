#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Tile.h"

class Hospital : public Tile
{
public:

    /* Constructor */
    Hospital(sf::Texture &texture, const std::vector<Animation> &animations);

};

#endif /* TILE_HPP */