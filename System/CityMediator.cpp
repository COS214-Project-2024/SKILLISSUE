#include "CityMediator.h"

#include <string>
#include <iostream>
#include <random>

CityMediator::CityMediator(City* gameCity) : city(gameCity ){};

CityMediator::CityMediator(){}

void CityMediator::notify(Tile* tile, TileType notification){


    if(notification == TileType::FIRESTATION && tile->tileType == TileType::RESIDENTIAL)//Check if house is connected to a firestation
    {
        burnHouse(tile);
    }
    else if(notification == TileType::POWERPLANT)//Ask for Electricity
    {
        getPower(tile);
    }
    //Ask for Electricity
    else if(notification == TileType::WATERPLANT)
    {
        getWater(tile);
    }
    //Ask for Electricity
    else if(notification == TileType::SEWAGEPLANT)
    {
        treatSewage(tile);
    }
    //Ask for Electricity
    else if(notification == TileType::WASTEMANAGEMENT)
    {
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

            //current - max > 10, then store max
            if(tile2->resources[ResourceType::WASTE] >= tile->consumption){
                tile2->consumeResource(ResourceType::WASTE, tile->consumption);
                tile->produceResource(ResourceType::WASTE, tile->consumption);
                return; //House Serviced return
                //Will continue looking for other powerstation if it's not serviced
            }
        }
    }
    return;
}

void CityMediator::treatSewage(Tile* tile){
    for(Tile *tile2 : this->city->map->tiles){
        if (tile2->tileType == TileType::SEWAGEPLANT && tile2->regions[0] == tile->regions[0]){
            //current-max
            if(tile2->resources[ResourceType::SEWAGE] >= tile->consumption){
                tile2->consumeResource(ResourceType::SEWAGE, tile->consumption);
                tile->produceResource(ResourceType::SEWAGE, tile->consumption);
                return; //House Serviced return
                //Will continue looking for other powerstation if it's not serviced
            }
        }
    }
    return;
}