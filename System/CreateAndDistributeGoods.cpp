#include "CreateAndDistributeGoods.h"

CreateAndDistributeGoods::CreateAndDistributeGoods(Map* map, std::vector<int>& shuffledTiles, double& industrialRevenue,
               double& commercialRevenue, double taxRate)
        : map(map), shuffledTiles(shuffledTiles), industrialRevenue(industrialRevenue),
          commercialRevenue(commercialRevenue), taxRate(taxRate){}

void CreateAndDistributeGoods::execute() {
        receiver.createAndDistributeGoods(map, shuffledTiles, industrialRevenue, commercialRevenue, taxRate);
    }