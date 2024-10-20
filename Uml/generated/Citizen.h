#ifndef CITIZEN_H
#define CITIZEN_H

class Citizen : City {

private:
	int hp;
	int age;
	string name;
	int ID;
	int SocialCredit;
	int Satisfaction;
	int Happiness;
	Residentual* Home;
	RoadVehicle* Vehicle;
	int Money;
	string job;
	Bulding* jobLocation;

public:
	void incrementAge();

	void addSocialCredit(int sc);

	void removeSocialCredit(int sc);

	void addMoney(int amount);

	void removeMoney(int amount);

	void incrementHappiness();

	void decrementHappiness();

	void buyHome(Residentual* house);

	void sellHome();

	void buyCar(RoadVehicle* car);

	void sellCar();

	void reactToMediatorFunctions();

	void travel(City* location);

	void travel(int x, int y);
};

#endif
