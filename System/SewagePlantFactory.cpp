#include "SewagePlantFactory.h"

Tile* SewagePlantFactory::CreateTile(sf::Texture &texture, const std::vector<Animation> &animations)
{
    return new SewagePlant(texture, animations);
}