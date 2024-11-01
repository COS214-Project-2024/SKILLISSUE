#ifndef CITIZENSURVEILANCESYSTEM_H
#define CITIZENSURVEILANCESYSTEM_H

class CitizenSurveilanceSystem {

private:
	vector<Citizen*> Citizens;

public:
	void addCitizen(int ID);

	void removeCitizen(int ID);

	int getPopulation();

	int getHappiness();

	void assassinate(int ID);

	void getLocation(Citizen* person);
};

#endif
