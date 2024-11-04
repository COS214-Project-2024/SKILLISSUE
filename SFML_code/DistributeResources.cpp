#include "DistributeResources.h"

DistributeResources::DistributeResources(Map* map, std::vector<int>& shuffledTiles)
    : map(map), shuffledTiles(shuffledTiles)
{}
    
void DistributeResources::execute()
{
    receiver.Distribute(map,shuffledTiles);
}