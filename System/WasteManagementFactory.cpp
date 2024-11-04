#include "WasteManagementFactory.h"

Tile* WasteManagementFactory::CreateTile(sf::Texture &texture, const std::vector<Animation> &animations)
{
    return new WasteManagement(texture, animations);
}