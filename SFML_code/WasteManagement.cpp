#include "WasteManagement.h"

WasteManagement::WasteManagement(sf::Texture &texture,  const std::vector<Animation> &animations)
    :Tile(8, 2, texture, animations, TileType::RESIDENTIAL, 900, 50, 2)
{}