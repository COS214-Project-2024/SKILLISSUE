#include "ResourceManager.h"

int ResourceManager::getWater() { return water; }

int ResourceManager::getPower() { return power; }

int ResourceManager::getSewage() { return sewage; }

int ResourceManager::getMaterial() { return materials; }

void ResourceManager::setWater(int value) { water = value; }

void ResourceManager::setPower(int value) { power = value; }

void ResourceManager::setSewage(int value) { sewage = value; }

void ResourceManager::setMaterial(int value) { materials = value; }

ResourceManager::ResourceManager() {}

ResourceManager &ResourceManager::getResourceManagerInstance() {
  static ResourceManager onlyInstance;
  return onlyInstance;
}
