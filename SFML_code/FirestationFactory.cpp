#include "FirestationFactory.h"

Tile* FirestationFactory::CreateTile(sf::Texture &texture, const std::vector<Animation> &animations)
{
    return new Firestation(texture, animations);
}