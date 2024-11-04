#include "Landmark.h"

Landmark::Landmark(sf::Texture &texture,  const std::vector<Animation> &animations)
    :Tile(8, 2, texture, animations, TileType::LANDMARK, 400, 50, 4, 200, 5, 0, 100)
{}