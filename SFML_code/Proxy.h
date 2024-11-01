#ifndef PROXY_H
#define PROXY_H

#include "Subject.h"

class Proxy : Subject 
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
