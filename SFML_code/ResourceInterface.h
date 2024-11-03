#ifndef RESOURCEINTERFACE_H
#define RESOURCEINTERFACE_H

class ResourceInterface {

public:
	virtual int getWater() = 0;

	virtual int getPower() = 0;

	virtual int getSewage() = 0;

	virtual int getMaterial() = 0;

	virtual void setWater(int value) = 0;

	virtual void setPower(int value) = 0;

	virtual void setSewage(int value) = 0;

	virtual void setMaterial(int value) = 0;

    virtual bool useWater(int value) = 0;

    virtual bool usePower(int value) = 0;

    virtual bool useSewage(int value) = 0;

    virtual bool useMaterial(int value) = 0;
};

#endif