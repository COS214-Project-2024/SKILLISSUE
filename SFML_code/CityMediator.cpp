#include "CityMediator.h"

#include <string>
#include <iostream>
#include <random>

CityMediator::CityMediator(City* gameCity) : city(gameCity ){};

CityMediator::CityMediator(){}

void CityMediator::notify(Tile* tile, TileType notification){

    //Check if house is connected to a firestation
    if(notification == TileType::FIRESTATION && tile->tileType == TileType::RESIDENTIAL){
        burnHouse(tile);
    }
    //Ask for Electricity
    else if(notification == TileType::POWERPLANT && tile->tileType == TileType::RESIDENTIAL)
    {
        getPower(tile);
    }
    //Ask for Electricity
    else if(notification == TileType::WATERPLANT && tile->tileType == TileType::RESIDENTIAL){
        getWater(tile);
    }
    //Ask for Electricity
    else if(notification == TileType::SEWAGEPLANT && tile->tileType == TileType::RESIDENTIAL){
        treatSewage(tile);
    }
    //Ask for Electricity
    else if(notification == TileType::WASTEMANAGEMENT && tile->tileType == TileType::RESIDENTIAL){
        disposeWaste(tile);
    }
    //Ask for Electricity
    else if(notification == TileType::SEWAGEPLANT && tile->tileType == TileType::INDUSTRIAL){
        treatSewage(tile);
    }
    //Ask for Electricity
    else if(notification == TileType::WASTEMANAGEMENT && tile->tileType == TileType::COMMERCIAL){
        
        disposeWaste(tile);
    }

}

void CityMediator::burnHouse(Tile* tile){
    //check if house is connnected to a fireStation
    //if not destroy house and add to population pool, dec from population (later)

    if(tile == NULL){
        return;
    }

    bool fireStationFound = false;

    for (Tile *tile2 : this->city->map->tiles){
        if (tile2->tileType == TileType::FIRESTATION && tile2->regions[0] == tile->regions[0]){
            fireStationFound = true;
        }
    }
    
    if(fireStationFound){return;}
    tile->tileVariant = 0;
    //okay for now, more complex logic later
}

void CityMediator::getPower(Tile* tile){
    for(Tile *tile2 : this->city->map->tiles){
        if (tile2->tileType == TileType::POWERPLANT && tile2->regions[0] == tile->regions[0]){
            //Tile is connected to a powerplant
            
            //check if powerplant has enough power
            if(tile2->resources[ResourceType::ELECTRICITY] >= tile->consumption){
                tile2->consumeResource(ResourceType::ELECTRICITY, tile->consumption);
                tile->produceResource(ResourceType::ELECTRICITY, tile->consumption);
                return; //House Serviced return
                //Will continue looking for other powerstation if it's not serviced
            }
        }
    }
    return;
}

void CityMediator::getWater(Tile* tile){
    for(Tile *tile2 : this->city->map->tiles){
        if (tile2->tileType == TileType::WATERPLANT && tile2->regions[0] == tile->regions[0]){
            //Tile is connected to a waterplant
            
            //check if waterplant has enough power
            if(tile2->resources[ResourceType::WATER] >= tile->consumption){
                tile2->consumeResource(ResourceType::WATER, tile->consumption);
                tile->produceResource(ResourceType::WATER, tile->consumption);
                return; //House Serviced return
                //Will continue looking for other powerstation if it's not serviced
            }
        }
    }
    return;
}

void CityMediator::disposeWaste(Tile* tile){
    for(Tile *tile2 : this->city->map->tiles){
        if (tile2->tileType == TileType::WASTEMANAGEMENT && tile2->regions[0] == tile->regions[0]){

            //move waste from tile to waste disposal if enough space
            if(tile2->maxResources[ResourceType::WASTE] - tile2->resources[ResourceType::WASTE] >= tile->consumption){
                tile->consumeResource(ResourceType::WASTE, tile->consumption);
                tile2->produceResource(ResourceType::WASTE, tile->consumption);
                return; //House Serviced return
            }
        }
    }
    return;
}

void CityMediator::treatSewage(Tile* tile){
    std::cout << "DISPOSING SEWAGE STARTED!";
    for(Tile *tile2 : this->city->map->tiles){
        if (tile2->tileType == TileType::SEWAGEPLANT && tile2->regions[0] == tile->regions[0]){
            //current-max
            if(tile2->maxResources[ResourceType::SEWAGE] - tile2->resources[ResourceType::SEWAGE] >= tile->consumption){
                tile->consumeResource(ResourceType::SEWAGE, tile->consumption);
                tile2->produceResource(ResourceType::SEWAGE, tile->consumption);
                return; //House Serviced return
            }
        }
    }
    return;
}