#ifndef SD_RECEIVER_H
#define SD_RECEIVER_H

#include "Map.h"
#include "Tile.h"
#include <vector>

class SCReceiver {

public:
    
    SCReceiver();

    void Calculate(Map* map, std::vector<int>& shuffledTiles,std::string taxtype);

};

#endif // SD_RECEIVER_H
