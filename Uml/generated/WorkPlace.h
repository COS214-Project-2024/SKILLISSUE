#ifndef WORKPLACE_H
#define WORKPLACE_H

class WorkPlace : Buildings {

private:
	int Income;
	int Expense;

public:
	void payEmployees();

	void addMoney(int amount);

	void removeMoney(int amount);
};

#endif
