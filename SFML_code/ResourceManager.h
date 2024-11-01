#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

class ResourceManager : Subject {

private:
	int Water;
	int Power;
	int Sewage;
	int Materials;
	static ResourceManager* Instance;

public:
	int getWater();

	int getPower();

	int getSewage();

	int getMaterial();

	void setWater(int value);

	void setPower(int value);

	void setSewage(int value);

	void setMaterial(int value);

public:
	ResourceManager();

	static ResourceManager* getResourceManager();
};

#endif
