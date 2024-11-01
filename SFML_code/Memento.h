#ifndef MEMENTO_H
#define MEMENTO_H

#include "Map.h"



class Memento {

friend class City;

public:
	double populationPool;
	double satisfaction;
	double employmentPool;
	double population;
	double employable;
	double earnings;
	double funds;
	int day;
	Map* map;

	Memento(double populationPool, double employmentPool, double population, double employable, double satisfaction, double earnings, double funds, int day, Map* map);
};

#endif
