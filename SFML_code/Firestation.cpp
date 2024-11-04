#include "Firestation.h"

Firestation::Firestation(sf::Texture &texture,  const std::vector<Animation> &animations)
    :Tile(8, 2, texture, animations, TileType::FIRESTATION, 800, 8, 4, 500, 10, 0)
{}