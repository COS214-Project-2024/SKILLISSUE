#ifndef CD_RECEIVER_H
#define CD_RECEIVER_H

#include "Map.h"
#include "Tile.h"
#include <vector>

class CDReceiver {

public:
    // Constructor that takes references to map, shuffledTiles, and tax/revenue variables
    CDReceiver();

    void createAndDistributeGoods(Map* map, std::vector<int>& shuffledTiles, double& industrialRevenue,
               double& commercialRevenue, double taxRate);
};

#endif // CD_RECEIVER_H
