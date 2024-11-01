#ifndef RESOURCES_H
#define RESOURCES_H

#include "ResourceInterface.h"

class Resources : public ResourceInterface
{

private:
	int Water;
	int Power;
	int Sewage;
	int Materials;
	static Resources* Instance;

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
	Resources();

	static Resources* getResources();
};

#endif