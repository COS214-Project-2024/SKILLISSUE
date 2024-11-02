#include "SewagePlant.h"

SewagePlant::SewagePlant(sf::Texture &texture,  const std::vector<Animation> &animations)
    :Tile(8, 2, texture, animations, TileType::SEWAGEPLANT, 1500, 50, 3)
{}
