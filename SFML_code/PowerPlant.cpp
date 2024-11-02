#include "PowerPlant.h"

PowerPlant::PowerPlant(sf::Texture &texture,  const std::vector<Animation> &animations)
    :Tile(8, 2, texture, animations, TileType::RESIDENTIAL, 2000, 50, 4)
{}