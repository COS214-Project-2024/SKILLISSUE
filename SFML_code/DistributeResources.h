#ifndef DISTRIBUTE_RESOURCES_H
#define DISTRIBUTE_RESOURCES_H

#include "DRReceiver.h"
#include "Command.h"

class DistributeResources : Command {
private:
    DRReceiver receiver;

    Map* map;
    std::vector<int>& shuffledTiles;
    CityMediator* mediator;

public:
    DistributeResources(Map* map, std::vector<int>& shuffledTiles, CityMediator* mediator);
    void execute();
};

#endif // CREATE_AND_DISTRIBUTE_GOODS_H
