#include "HospitalFactory.h"

Tile* HospitalFactory::CreateTile(sf::Texture &texture, const std::vector<Animation> &animations)
{
    return new Hospital(texture, animations);
}