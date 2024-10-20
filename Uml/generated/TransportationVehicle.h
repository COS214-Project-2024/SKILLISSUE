#ifndef TRANSPORTATIONVEHICLE_H
#define TRANSPORTATIONVEHICLE_H

class TransportationVehicle : City {

private:
	vector<City*> occupants;
	int speed;
	int capacity;
	TransportationRouting* route;
	int cost;
	int fuel;

public:
	/**
	 * Will Change the x and y pos of a city object.
	 * vector will be cleared once all positions updated
	 */
	void Travel(int pointA, int pointB);

	void addOccupant(City* occ);
};

#endif
