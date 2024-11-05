#include "WasteManagement.h"

WasteManagement::WasteManagement(sf::Texture &texture,  const std::vector<Animation> &animations)
    :Tile(8, 2, texture, animations, TileType::WASTEMANAGEMENT, 900, 50, 2, 90, 0, 400, 400)
{}
