#ifndef MEDIATOR_H
#define MEDIATOR_H

#include "Map.h"
#include "Tile.h"
#include <vector>

class Mediator {

private:
	std::vector<Tile*> tiles;

public:
	void connectTo(TileType tile);
};

#endif
