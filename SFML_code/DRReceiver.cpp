#include "DistributeResources.h"

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
        if (tile && tile->tileType == TileType::WATERPLANT)
        {
            tile->produceResource(ResourceType::WATER, tile->maxProduction);
        }
        if (tile && tile->tileType == TileType::SEWAGEPLANT)
        {
            tile->produceResource(ResourceType::SEWAGE, tile->maxProduction);
        }
        if (tile && tile->tileType == TileType::WASTEMANAGEMENT)
        {
            tile->produceResource(ResourceType::WASTE, tile->maxProduction);
        }
    }

    for (int i = 0; i < map->tiles.size(); ++i) {
        Tile* tile = map->tiles[shuffledTiles[i]];
        if (tile && tile->tileType == TileType::INDUSTRIAL || tile->tileType == TileType::COMMERCIAL || tile->tileType == TileType::RESIDENTIAL ||
                    tile->tileType == TileType::FIRESTATION || tile->tileType == TileType::HOSPITAL || tile->tileType == TileType::LANDMARK) {
            if(tile->resources[ResourceType::ELECTRICITY] <= 0)
            {
                tile->notify(TileType::POWERPLANT);
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

    // for (int i = 0; i < map->tiles.size(); ++i) {
    //     Tile* tile = map->tiles[shuffledTiles[i]];
    //     if (tile && tile->tileType == TileType::INDUSTRIAL || tile->tileType == TileType::COMMERCIAL || tile->tileType == TileType::RESIDENTIAL ||
    //                 tile->tileType == TileType::FIRESTATION || tile->tileType == TileType::HOSPITAL || tile->tileType == TileType::LANDMARK) 
    //     {
    //         if(tile->resources[ResourceType::ELECTRICITY] <= 0)
    //         {
    //             tile->sprite.setTexture()
    //         }
    //         else if(tile->resources[ResourceType::WATER] <= 0)
    //         {
    //             tile->notify(TileType::WATERPLANT);
    //         }
    //         else if(tile->resources[ResourceType::SEWAGE] <= 0)
    //         {
    //             tile->notify(TileType::SEWAGEPLANT);
    //         }
    //         else if(tile->resources[ResourceType::WASTE] <= 0)
    //         {
    //             tile->notify(TileType::WASTEMANAGEMENT);
    //         }
    //     }
    // }

    for (int i = 0; i < map->tiles.size(); ++i) {
        Tile* tile = map->tiles[shuffledTiles[i]];
        if (tile && tile->tileType == TileType::INDUSTRIAL || tile->tileType == TileType::COMMERCIAL || tile->tileType == TileType::RESIDENTIAL ||
                    tile->tileType == TileType::FIRESTATION || tile->tileType == TileType::HOSPITAL || tile->tileType == TileType::LANDMARK) {
            tile->consumeResource(ResourceType::ELECTRICITY, tile->consumption);
            tile->consumeResource(ResourceType::WATER, tile->consumption);
            tile->consumeResource(ResourceType::SEWAGE, tile->consumption);
            tile->consumeResource(ResourceType::WASTE, tile->consumption);
        }
    }




}