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
	int getWater(int value);

	int getPower(int value);

	int getSewage(int value);

	int getMaterial(int value);

	void setWater(int value);

	void setPower(int value);

	void setSewage(int value);

	void setMaterial(int value);

    int consumeWater(int value);

	int consumePower(int value);

	int consumeSewage(int value);

	int consumeMaterial(int value);

public:
	Resources();

	static Resources getResources();
};

#endif