#ifndef CD_RECEIVER_H
#define CD_RECEIVER_H

#include "Map.h"
#include "Tile.h"
#include <vector>

class CDReceiver {
private:
    Map& map;
    std::vector<int>& shuffledTiles;
    double& industrialRevenue;
    double& commercialRevenue;
    double commercialTax;
    double industrialTax;

public:
    // Constructor that takes references to map, shuffledTiles, and tax/revenue variables
    CDReceiver(Map& map, std::vector<int>& shuffledTiles, double& industrialRevenue,
               double& commercialRevenue, double commercialTax, double industrialTax)
        : map(map), shuffledTiles(shuffledTiles), industrialRevenue(industrialRevenue),
          commercialRevenue(commercialRevenue), commercialTax(commercialTax), industrialTax(industrialTax) {}

    void update();
};

#endif // CD_RECEIVER_H
