#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

class ResourceManager {

private:
	int Contents_of_map;
	int water;
	int funds;
	int energy;
	int wood;
	int sewage;
	int pollution;
	int fuel;

public:
	void increaseResource(sting name, int amount);

	void consumeResource(sting name, int amount);

	void addToResourceMap(sting name, int amount);
};

#endif
