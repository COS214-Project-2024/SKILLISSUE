#include "ResourceManager.h"
#include "Resources.h"

ResourceManager::ResourceManager() {}

bool ResourceManager::useWater(int value) {
  // Must request less than 20% of water available
  if (value < (0.2 * Resources::getResourcesInstance().getWater(value))) {
    Resources::getResourcesInstance().consumeWater(value);
    return true;
  }
  return -1;
}

bool ResourceManager::usePower(int value) {
  // Must request less than 40% of power available
  if (value < (0.4 * Resources::getResourcesInstance().getPower(value))) {
    Resources::getResourcesInstance().consumePower(value);
    return true;
  }
  return false;
}

bool ResourceManager::useSewage(int value) {
  // Must request less than 60% of power available
  if (value < (0.6 * Resources::getResourcesInstance().getSewage(value))) {
    Resources::getResourcesInstance().consumeSewage(value);
    return true;
  }
  return false;
}

bool ResourceManager::useMaterial(int value) {
  // Must request less than 80% of water available
  if (value < (0.8 * Resources::getResourcesInstance().getWater())) {
    Resources::getResourcesInstance().consumeWater(value);
    return true;
  }
  return false;
}

void ResourceManager::setWater(int value) {
  // must set positive amount and must be greater than current amount
  if (value > 0 and value >= Resources::getResourcesInstance().getWater()) {
    Resources::getResourcesInstance().setWater(value);
    return;
  }
}

void ResourceManager::setPower(int value) {
  // must set positive amount and must be greater than current amount
  if (value > 0 and value >= Resources::getResourcesInstance().getPower()) {
    Resources::getResourcesInstance().setPower(value);
    return;
  }
}

void ResourceManager::setSewage(int value) {
  // must set positive amount and must be greater than current amount
  if (value > 0 and value >= Resources::getResourcesInstance().getSewage()) {
    Resources::getResourcesInstance().setSewage(value);
    return;
  }
}

void ResourceManager::setMaterial(int value) {
  // must set positive amount and must be greater than current amount
  if (value > 0 and value >= Resources::getResourcesInstance().getMaterial()) {
    Resources::getResourcesInstance().setMaterial(value);
    return;
  }
}

int ResourceManager::getWater() {
  return Resources::getResourcesInstance().getWater();
}

int ResourceManager::getPower() {
  return Resources::getResourcesInstance().getPower();
}

int ResourceManager::getSewage() {
  return Resources::getResourcesInstance().getSewage();
}

int ResourceManager::getMaterial() {
  return Resources::getResourcesInstance().getMaterial();
}
