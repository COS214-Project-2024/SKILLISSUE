#ifndef CITYMEDIATOR_H
#define CITYMEDIATOR_H


#include "Tile.h"
#include "City.h"

#include <string>

class CityMediator{
    private:
    City* city;
    void react();

    public:
    CityMediator();
    CityMediator(City* city);


    void setCity(City* city);
    void getCity(City city);
    void notify(Tile* tile, TileType notification);

    void burnHouse(Tile* tile);

    // void getPower(Tile* tile);
    // void disposeWaste(Tile* tile);
    // void treatSewage(Tile* tile);

};

#endif