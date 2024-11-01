#ifndef MEMENTO_H
#define MEMENTO_H

#include "Map.h"


class Memento {

friend class City;

private:
	/**
	 * Number of residents who are not in a residential zone.
	 */
	double populationPool;
	/**
	 * Number of residents who are not currently employed but can work.
	 */
	double employmentPool;
public:
	double population;
	double employable;
private:
	double satisfaction;
public:
	/**
	 * Running total of city earnings (from tax etc) this month.
	 */
	double earnings;
	double funds;
	int day;
	Map map;

	Memento(double populationPool, double employmentPool, double population, double employable, double satisfaction, double earnings, double funds, int day, Map map);
};

#endif
