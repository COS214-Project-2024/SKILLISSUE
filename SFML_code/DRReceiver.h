// DRReceiver.h
#ifndef DR_RECEIVER_H
#define DR_RECEIVER_H

#include "Tile.h"
#include "Map.h"
#include <vector>

class DRReceiver {

public:
    DRReceiver();
    void Distribute(Map* map, std::vector<int>& shuffledTiles, CityMediator* mediator);
};

#endif // D_RECEIVER_H