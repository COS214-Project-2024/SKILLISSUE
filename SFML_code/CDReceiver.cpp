#include "CDReceiver.h"
#include <cstdlib>  // for rand()

void CDReceiver::update() {
    // First pass: Industrial tile resource management
    for (int i = 0; i < map->tiles.size(); ++i) {
        Tile* tile = map->tiles[shuffledTiles[i]];
        if (tile && tile->tileType == TileType::INDUSTRIAL) {
            int receivedResources = 0;
            for (Tile* tile2 : map->tiles) {
                if (tile2->regions[0] == tile->regions[0] && tile2->tileType == TileType::INDUSTRIAL && tile2->production > 0) {
                    ++receivedResources;
                    --tile2->production;
                    if (receivedResources >= tile->tileVariant + 1) break;
                }
            }
            tile->storedGoods += (receivedResources + tile->production) * (tile->tileVariant + 1);
        }
    }

    // Second pass: Commercial tile goods distribution
    for (int i = 0; i < map->tiles.size(); ++i) {
        Tile* tile = map->tiles[shuffledTiles[i]];
        if (tile && tile->tileType == TileType::COMMERCIAL) {
            int receivedGoods = 0;
            double maxCustomers = 0.0;
            for (Tile* tile2 : map->tiles) {
                if (tile2->regions[0] == tile->regions[0] && tile2->tileType == TileType::INDUSTRIAL && tile2->storedGoods > 0) {
                    while (tile2->storedGoods > 0 && receivedGoods != tile->tileVariant + 1) {
                        --tile2->storedGoods;
                        ++receivedGoods;
                        industrialRevenue += 100 * (1.0 - industrialTax);
                    }
                } else if (tile2->regions[0] == tile->regions[0] && tile2->tileType == TileType::RESIDENTIAL) {
                    maxCustomers += tile2->population;
                }
                if (receivedGoods == tile->tileVariant + 1) break;
            }
            tile->production = (receivedGoods * 100.0 + rand() % 20) * (1.0 - commercialTax);
            double revenue = tile->production * maxCustomers * tile->population / 100.0;
            commercialRevenue += revenue;
        }
    }
}
