#ifndef MAP_H
#define MAP_H

class Map {

private:
	City map[][];
	int length;
	int width;

public:
	void AddCityObject(City* cityObject);

	void RemoveCityObject(City* cityObject);
};

#endif
