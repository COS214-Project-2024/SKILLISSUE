#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "ResourceInterface.h"
#include "Resources.h"

class ResourceManager : public ResourceInterface, private Resources {
public:
  ResourceManager();
  ~ResourceManager();
  int getWater();
  int getPower();
  int getSewage();
  int getMaterial();
  void setWater(int value);
  void setPower(int value);
  void setSewage(int value);
  void setMaterial(int value);
  bool useWater(int value);
  bool usePower(int value);
  bool useSewage(int value);
  bool useMaterial(int value);
};

#endif