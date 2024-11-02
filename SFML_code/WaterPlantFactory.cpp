#include "WaterPlantFactory.h"

Tile* WaterPlantFactory::CreateTile(sf::Texture &texture, const std::vector<Animation> &animations)
{
    return new WaterPlant(texture, animations);
}