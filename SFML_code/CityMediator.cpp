#include "CityMediator.h"

#include <string>
#include <random>

CityMediator::CityMediator(City* gameCity) : city(gameCity ){};

CityMediator::CityMediator(){}

void CityMediator::notify(Tile* tile, std::string notification){

    if(notification == "fireAlert" && tile->tileType == TileType::RESIDENTIAL){
        burnHouse(tile);
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
        if (tile2->tileType == TileType::FIRESTATION && tile2->regions[0] == tile2->regions[0]){
            fireStationFound = true;
        }
    }
    
    if(fireStationFound){return;}

    tile->tileVariant = 0;
    //okay for now, more complex logic later
}