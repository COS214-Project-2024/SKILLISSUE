#include "PowerPlantFactory.h"

Tile* PowerPlantFactory::CreateTile(sf::Texture &texture, const std::vector<Animation> &animations)
{
    return new PowerPlant(texture, animations);
}