#include "Industrial.h"

Industrial::Industrial(sf::Texture &texture,  const std::vector<Animation> &animations)
    :Tile(8, 2, texture, animations, TileType::INDUSTRIAL, 300, 50, 4, 50, 50, 0, 100)
{}