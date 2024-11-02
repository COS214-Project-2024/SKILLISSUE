#include "WaterPlant.h"

WaterPlant::WaterPlant(sf::Texture &texture,  const std::vector<Animation> &animations)
    :Tile(8, 2, texture, animations, TileType::WATERPLANT, 1000, 50, 3)
{}
