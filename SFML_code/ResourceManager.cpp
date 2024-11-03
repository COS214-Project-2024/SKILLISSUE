#include "ResourceManager.h"
#include "Resources.h"

ResourceManager::ResourceManager() {
    resources = Resources::getResourcesInstance();
}

ResourceManager::~ResourceManager() {} //won't delete resources since using singleton

bool ResourceManager::consumeWater(int value) {
  // Must request less than 20% of water available
  if (value < (0.2 * resources->getWater())) {
    resources->consumeWater(value);
    return true;
  }
  return false;
}

bool ResourceManager::consumePower(int value) {
  // Must request less than 40% of power available
  if (value < (0.4 * resources->getPower())) {
    resources->consumePower(value);
    return true;
  }
  return false;
}

bool ResourceManager::consumeSewage(int value) {
  // Must request less than 60% of power available
  if (value < (0.6 * resources->getSewage())) {
    resources->consumeSewage(value);
    return true;
  }
  return false;
}

bool ResourceManager::consumeMaterial(int value) {
  // Must request less than 80% of water available
  if (value < (0.8 * resources->getMaterial())) {
    resources->consumeMaterial(value);
    return true;
  }
  return false;
}

void ResourceManager::setWater(int value) {
  // must set positive amount and must be greater than current amount
  if (value > 0 and value >= resources->getWater()) {
    resources->setWater(value);
    return;
  }
}

void ResourceManager::setPower(int value) {
  // must set positive amount and must be greater than current amount
  if (value > 0 and value >= resources->getPower()) {
    resources->setPower(value);
    return;
  }
}

void ResourceManager::setSewage(int value) {
  // must set positive amount and must be greater than current amount
  if (value > 0 and value >= resources->getSewage()) {
    resources->setSewage(value);
    return;
  }
}

void ResourceManager::setMaterial(int value) {
  // must set positive amount and must be greater than current amount
  if (value > 0 and value >= resources->getMaterial()) {
    resources->setMaterial(value);
    return;
  }
}

int ResourceManager::getWater() {
  return resources->getWater();
}

int ResourceManager::getPower() {
  return resources->getPower();
}

int ResourceManager::getSewage() {
  return resources->getSewage();
}

int ResourceManager::getMaterial() {
  return resources->getMaterial();
}