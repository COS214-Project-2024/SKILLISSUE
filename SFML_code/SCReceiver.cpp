#include "SCReceiver.h"

SCReceiver::SCReceiver()
{}


void SCReceiver::Calculate(Map* map, std::string taxtype, double population, double& satisfaction)
{
    for (int i = 0; i < map->tiles.size(); ++i) {
        Tile *tile = map->tiles[i];
        satisfaction += tile->getSatisfaction();
    }

    satisfaction = satisfaction/population*100*100;
    if(taxtype == "low")
    {
        satisfaction *= 0.95;
    }
    else if(taxtype == "mid")
    {
        satisfaction *= 0.85;
    }
    else if(taxtype == "high")
    {
        satisfaction *= 0.70;
    }

}