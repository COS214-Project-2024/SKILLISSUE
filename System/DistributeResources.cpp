#include "DistributeResources.h"

DistributeResources::DistributeResources(Map* map)
    : map(map)
{}
    
void DistributeResources::execute()
{
    receiver.Distribute(map);
}