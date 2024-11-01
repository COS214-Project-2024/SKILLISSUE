#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER__H

#include "ResourceInterface.h"

class ResourceManager : public ResourceInterface 
{
public:
	int getPower();
	int getSewage();
	int getMaterial();
	void setWater(int value);
	void setPower(int value);
	void setSewage(int value);
	void setMaterial(int value);
};

#endif