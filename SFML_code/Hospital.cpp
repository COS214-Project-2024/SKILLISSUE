#include "Hospital.h"

Hospital::Hospital(sf::Texture &texture,  const std::vector<Animation> &animations)
    :Tile(8, 2, texture, animations, TileType::HOSPITAL, 10000, 50, 3)
{}
