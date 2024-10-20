#ifndef BUILDINGS_H
#define BUILDINGS_H

class Buildings : City {

private:
	int cost;
	vector<Citizens> cuurentOccupants;
	vector<Citizen> owner;

public:
	void addCitizen(Citizen* citizen);

	void removeCitizen(Citizen* citizen);

	void consumeResources();

	void buy(Citizen newOwner);
};

#endif
