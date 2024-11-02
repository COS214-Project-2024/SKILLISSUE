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
    // if(notification == TileType::POWERPLANT && tile->tileType == TileType::RESIDENTIAL){
    //     getPower(tile);
    // }

    // if(notification == TileType::WASTEMANAGEMENT && tile->tileType == TileType::COMMERCIAL){
    //     getPower(tile);
    // }

    // if(notification == TileType::SEWAGEPLANT && tile->tileType == TileType::INDUSTRIAL){
    //     treatSewage(tile);
    // }
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
            if(tile2->resources[ResourceType::ELECTRCITY] >= 10){
                tile2->consumeResource(ResourceType::ELECTRCITY, 10);
                tile->produceResource(ResourceType::ELECTRCITY, 10);
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

            //current - max > 10, then store max
            if(tile2->resources[ResourceType::WASTE] - tile2->maxResources[ResourceType::WASTE] > 10){
                tile->consumeResource(ResourceType::WASTE, 10);
                tile2->produceResource(ResourceType::WASTE, 10);
                return; 
            }
        }
    }
    return;
}

void CityMediator::treatSewage(Tile* tile){
    for(Tile *tile2 : this->city->map->tiles){
        if (tile2->tileType == TileType::SEWAGEPLANT && tile2->regions[0] == tile->regions[0]){
            //current-max
            if(tile2->resources[ResourceType::SEWAGE] - tile2->maxResources[ResourceType::SEWAGE] > 10){
                tile->consumeResource(ResourceType::SEWAGE, 10);
                tile2->produceResource(ResourceType::SEWAGE, 10);
                return;
            }
        }
    }
    return;
}