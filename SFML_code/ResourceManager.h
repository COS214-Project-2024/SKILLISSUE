#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER__H

#include "ResourceInterface.h"
#include "Resources.h"

class ResourceManager : public ResourceInterface 
{
private:
	Resources resources;

public:
	ResourceManager();
	int getWater(int value);
	int getPower(int value);
	int getSewage(int value);
	int getMaterial(int value);
	void setWater(int value);
	void setPower(int value);
	void setSewage(int value);
	void setMaterial(int value);
};

#endif