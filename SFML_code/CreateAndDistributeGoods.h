#ifndef CREATE_AND_DISTRIBUTE_GOODS_H
#define CREATE_AND_DISTRIBUTE_GOODS_H

#include "CDReceiver.h"

class CreateAndDistributeGoods {
private:
    CDReceiver receiver;

    Map* map;
    std::vector<int>& shuffledTiles;
    double& industrialRevenue;
    double& commercialRevenue;
    double taxRate;

public:
    CreateAndDistributeGoods(Map* map, std::vector<int>& shuffledTiles, double& industrialRevenue,
               double& commercialRevenue, double taxRate);

    void execute();
};

#endif // CREATE_AND_DISTRIBUTE_GOODS_H
