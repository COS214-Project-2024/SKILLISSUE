#ifndef GOVERNMENT_H
#define GOVERNMENT_H

class Government : City {

private:
	int spendingBudget;
	CitizenSurveilanceSystem* CitizenSurveyor;
	double companyTaxRate;

	Policy* policy;

public:
	void updateBudget(int Sector, int amount);

	void getSpendingBudget();

	void executePolicy();
};

#endif
