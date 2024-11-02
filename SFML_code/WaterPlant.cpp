#include "WaterPlant.h"

WaterPlant::WaterPlant(sf::Texture &texture,  const std::vector<Animation> &animations)
    :Tile(8, 2, texture, animations, TileType::RESIDENTIAL, 1000, 50, 3)
{}