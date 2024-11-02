#include "Hospital.h"

Hospital::Hospital(sf::Texture &texture,  const std::vector<Animation> &animations)
    :Tile(8, 2, texture, animations, TileType::RESIDENTIAL, 10000, 50, 3)
{}