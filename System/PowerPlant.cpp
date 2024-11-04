#include "PowerPlant.h"

PowerPlant::PowerPlant(sf::Texture &texture,  const std::vector<Animation> &animations)
    :Tile(8, 2, texture, animations, TileType::POWERPLANT, 2000, 50, 4, 200, 0, 100, 100)
{}
