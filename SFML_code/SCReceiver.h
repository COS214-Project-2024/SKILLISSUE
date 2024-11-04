#ifndef SC_RECEIVER_H
#define SC_RECEIVER_H

#include "Map.h"
#include "Tile.h"
#include <vector>

class SCReceiver 
{
public:
    SCReceiver();
    void Calculate(Map* map, std::string taxtype, double population, double& satisfaction);

};

#endif // SD_RECEIVER_H
