#ifndef CITYMANAGER_H
#define CITYMANAGER_H

class CityManager : City {

private:
	vector<City*> cityObjects;
	Map* gameMap;

public:
	void addObject(City* cityObejct, City* cityObject);

	City* getObect(int index);

	City* getObject(string name);

	void notify(City* cityObject, string request);

	void reactToNotification();

	void removeObject(City* cityObject);
};

#endif
