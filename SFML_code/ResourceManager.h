#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "ResourceInterface.h"
#include "Resources.h"

class ResourceManager : public ResourceInterface {
private:    
  Resources* resources;

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
  bool consumeWater(int value);
  bool consumePower(int value);
  bool consumeSewage(int value); 
  bool consumeMaterial(int value);
};

#endif
