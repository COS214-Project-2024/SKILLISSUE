// DReceiver.cpp
#include "DReceiver.h"
#include <cstdlib> // for rand()

// Constructor implementation
DReceiver::DReceiver(Map* map, std::vector<int>& shuffledTiles, double& populationPool, double& employmentPool, 
                     double& popTotal, double birthRate, double deathRate, double commercialTax, 
                     double industrialTax, double population)
    : map(map), shuffledTiles(shuffledTiles), populationPool(populationPool), 
      employmentPool(employmentPool), popTotal(popTotal), birthRate(birthRate), 
      deathRate(deathRate), commercialTax(commercialTax), industrialTax(industrialTax), 
      population(population) {}

// Update method implementation
void DReceiver::update() {
    for (int i = 0; i < map->tiles.size(); ++i) {
        Tile *tile = map->tiles[shuffledTiles[i]];
        if (tile != nullptr) {
            if (tile->tileType == TileType::RESIDENTIAL) {
                distributePool(populationPool, tile, birthRate - deathRate);
                popTotal += tile->population;
            }
            else if (tile->tileType == TileType::COMMERCIAL || tile->tileType == TileType::FIRESTATION) {
                if (rand() % 100 < 15 * (1.0 - commercialTax)) {
                    distributePool(employmentPool, tile, 0.00);
                }
            }
            else if (tile->tileType == TileType::INDUSTRIAL) {
                if (map->resources[i] > 0 && rand() % 100 < population) {
                    ++tile->production;
                    --map->resources[i];
                }
                if (rand() % 100 < 15 * (1.0 - industrialTax)) {
                    distributePool(employmentPool, tile, 0.0);
                }
            }
            else if (tile->tileType == TileType::LANDMARK) {
                distributePool(populationPool, tile, birthRate - deathRate);
                popTotal += tile->population;
            }

            tile->update();
        }
    }
}

// Distribute pool method implementation
double DReceiver::distributePool(double& pool, Tile* tile, double rate) {
     const static int moveRate = 4;

    unsigned int maxPop = tile->maxPopPerLevel * (tile->tileVariant + 1);

    /* If there is room in the zone, move up to 4 people from the
     * pool into the zone */
    if (pool > 0)
    {
        int moving = maxPop - tile->population;
        if (moving > moveRate)
            moving = moveRate;
        if (pool - moving < 0)
            moving = pool;
        pool -= moving;
        tile->population += moving;
    }

    /* Adjust the tile population for births and deaths */
    tile->population += tile->population * rate;

    /* Move population that cannot be sustained by the tile into
     * the pool */
    if (tile->population > maxPop)
    {
        pool += tile->population - maxPop;
        tile->population = maxPop;
    }

    return tile->population;
}
