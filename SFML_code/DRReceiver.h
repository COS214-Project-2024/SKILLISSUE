// DRReceiver.h
#ifndef DR_RECEIVER_H
#define DR_RECEIVER_H

#include "Tile.h"
#include "Map.h"
#include <vector>
#include "ResourceInterface.h"
#include "ResourceManager.h"


class DRReceiver {

public:

    ResourceManager proxy;

    DRReceiver();
    void Distribute(Map* map);
};

#endif // D_RECEIVER_H