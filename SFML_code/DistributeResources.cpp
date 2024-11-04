#include "DistributeResources.h"

DistributeResources::DistributeResources(Map* map, std::vector<int>& shuffledTiles, CityMediator* mediator)
    : map(map), shuffledTiles(shuffledTiles), mediator(mediator)
{}
    
void DistributeResources::execute()
{
    receiver.Distribute(map,shuffledTiles, mediator);
}