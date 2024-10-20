#ifndef CITY_H
#define CITY_H

class City {

private:
	string name;
	int xPos;
	int yPos;
	CityManager* cityCommunicator;
	ResourceManager* resourcesAvailable;

public:
	void consumeResouce();
};

#endif
