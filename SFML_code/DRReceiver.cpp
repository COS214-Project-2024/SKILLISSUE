#include "DistributeResources.h"
#include <iostream>

DRReceiver::DRReceiver()
{}

void DRReceiver::Distribute(Map* map, std::vector<int>& shuffledTiles)
{
    for (int i = 0; i < map->tiles.size(); ++i) {
        Tile* tile = map->tiles[shuffledTiles[i]];
        if (tile && tile->tileType == TileType::POWERPLANT)
        {
            tile->produceResource(ResourceType::ELECTRICITY, tile->maxProduction);
        }
        else if (tile && tile->tileType == TileType::WATERPLANT)
        {
            tile->produceResource(ResourceType::WATER, tile->maxProduction);
        }
        else if (tile && tile->tileType == TileType::SEWAGEPLANT)
        {
            tile->produceResource(ResourceType::SEWAGE, tile->maxProduction);
        }
        else if (tile && tile->tileType == TileType::WASTEMANAGEMENT)
        {
            tile->produceResource(ResourceType::WASTE, tile->maxProduction);
        }
    }

    for (int i = 0; i < map->tiles.size(); ++i) {
        Tile* tile = map->tiles[shuffledTiles[i]];
        if (tile && (tile->tileType == TileType::INDUSTRIAL || tile->tileType == TileType::COMMERCIAL || tile->tileType == TileType::RESIDENTIAL ||
                    tile->tileType == TileType::FIRESTATION || tile->tileType == TileType::HOSPITAL || tile->tileType == TileType::LANDMARK)) {
            if(tile->resources[ResourceType::ELECTRICITY] <= 0)
            {
                tile->notify(TileType::POWERPLANT);
                std::cout << tile->resources[ResourceType::ELECTRICITY] << '\n';
            }
            if(tile->resources[ResourceType::WATER] <= 0)
            {
                tile->notify(TileType::WATERPLANT);
            }
            if(tile->resources[ResourceType::SEWAGE] <= 0)
            {
                tile->notify(TileType::SEWAGEPLANT);
            }
            if(tile->resources[ResourceType::WASTE] <= 0)
            {
                tile->notify(TileType::WASTEMANAGEMENT);
            }
        }
    }

    double powerProduced = 0;
    double waterProduced = 0;
    double sewageProduced = 0;
    double wasteProduced = 0;

    int powerConsumed = 0;
    int waterConsumed = 0;
    int sewageConsumed = 0;
    int wasteConsumed = 0;

    double powerUsed = 0;
    double waterUsed = 0;
    double sewageUsed = 0;
    double wasteUsed = 0;

    for (int i = 0; i < map->tiles.size(); ++i) {
        Tile* tile = map->tiles[shuffledTiles[i]];
        if (tile && (tile->tileType == TileType::INDUSTRIAL || tile->tileType == TileType::COMMERCIAL || tile->tileType == TileType::RESIDENTIAL ||
                    tile->tileType == TileType::FIRESTATION || tile->tileType == TileType::HOSPITAL || tile->tileType == TileType::LANDMARK)) 
        {
            powerConsumed += tile->consumption;
            waterConsumed += tile->consumption;
            sewageConsumed += tile->consumption;
            wasteConsumed += tile->consumption;

            powerUsed += tile->resources[ResourceType::ELECTRICITY];
            waterUsed += tile->resources[ResourceType::WATER];
            sewageUsed += tile->resources[ResourceType::SEWAGE];
            wasteUsed += tile->resources[ResourceType::WASTE];
        }
        else if (tile && tile->tileType == TileType::POWERPLANT)
        {
            powerProduced += tile->maxProduction;
        }
        else if (tile && tile->tileType == TileType::WATERPLANT)
        {
            waterProduced += tile->maxProduction;
        }
        else if (tile && tile->tileType == TileType::SEWAGEPLANT)
        {
            sewageProduced += tile->maxProduction;
        }
        else if (tile && tile->tileType == TileType::WASTEMANAGEMENT)
        {
            wasteProduced += tile->maxProduction;
        }
    }

    proxy.setPower(powerProduced);
    proxy.setWater(waterProduced);
    proxy.setSewage(sewageProduced);
    proxy.setWaste(wasteProduced);

    proxy.setPowerConsumption(powerConsumed);
    proxy.setWaterConsumption(waterConsumed);
    proxy.setSewageConsumption(sewageConsumed);
    proxy.setWasteConsumption(wasteConsumed);

    proxy.setPowerUsage((powerUsed/powerProduced)*100.0);
    proxy.setWaterUsage((waterUsed/waterProduced)*100.0);
    proxy.setSewageUsage((sewageUsed/sewageProduced)*100.0);
    proxy.setWasteUsage((wasteUsed/wasteProduced)*100.0);

    // std::cout << powerUsed << '\n';
    // std::cout << (powerUsed/powerProduced)*100.0 << '\n';



    for (int i = 0; i < map->tiles.size(); ++i) {
        Tile* tile = map->tiles[shuffledTiles[i]];
        if (tile && (tile->tileType == TileType::INDUSTRIAL || tile->tileType == TileType::COMMERCIAL || tile->tileType == TileType::RESIDENTIAL ||
                    tile->tileType == TileType::FIRESTATION || tile->tileType == TileType::HOSPITAL || tile->tileType == TileType::LANDMARK)) {
            tile->consumeResource(ResourceType::ELECTRICITY, tile->consumption);
            tile->consumeResource(ResourceType::WATER, tile->consumption);
            tile->consumeResource(ResourceType::SEWAGE, tile->consumption);
            tile->consumeResource(ResourceType::WASTE, tile->consumption);
        }
    }






}