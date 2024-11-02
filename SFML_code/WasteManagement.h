#ifndef WASTEMANAGEMENT_H
#define WASTEMANAGEMENT_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Tile.h"

class WasteManagement : public Tile
{
public:

    /* Constructor */
    WasteManagement(sf::Texture &texture, const std::vector<Animation> &animations);

};

#endif /* TILE_HPP */