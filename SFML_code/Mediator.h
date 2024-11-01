#ifndef MEDIATOR_H
#define MEDIATOR_H

class Mediator {

private:
	vector<Tiles> tiles;

public:
	void connectTo(TileType tile);
};

#endif
