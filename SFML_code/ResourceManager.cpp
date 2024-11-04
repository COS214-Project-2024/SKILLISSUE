#include "ResourceManager.h"
#include "Resources.h"

ResourceManager::ResourceManager() {}

ResourceManager::~ResourceManager() {} 


void ResourceManager::setWater(int value) {
  // must set positive amount and must be greater than current amount
  if (value >= 0) {
    Resources::getResourcesInstance().setWater(value);
    return;
  }
}

void ResourceManager::setPower(int value) {
  // must set positive amount and must be greater than current amount
  if (value >= 0) {
    Resources::getResourcesInstance().setPower(value);
    return;
  }
}

void ResourceManager::setSewage(int value) {
  // must set positive amount and must be greater than current amount
  if (value >= 0) {
    Resources::getResourcesInstance().setSewage(value);
    return;
  }
}

void ResourceManager::setWaste(int value) {
  // must set positive amount and must be greater than current amount
  if (value >= 0) {
    Resources::getResourcesInstance().setWaste(value);
    return;
  }
}

void ResourceManager::setWaterConsumption(int value) {
  // must set positive amount and must be greater than current amount
  if (value >= 0) {
    Resources::getResourcesInstance().setWaterConsumption(value);
    return;
  }
}

void ResourceManager::setPowerConsumption(int value) {
  // must set positive amount and must be greater than current amount
  if (value >= 0) {
    Resources::getResourcesInstance().setPowerConsumption(value);
    return;
  }
}

void ResourceManager::setSewageConsumption(int value) {
  // must set positive amount and must be greater than current amount
  if (value >= 0) {
    Resources::getResourcesInstance().setSewageConsumption(value);
    return;
  }
}

void ResourceManager::setWasteConsumption(int value) {
  // must set positive amount and must be greater than current amount
  if (value >= 0) {
    Resources::getResourcesInstance().setWasteConsumption(value);
    return;
  }
}

void ResourceManager::setWaterUsage(double value) {
  // must set positive amount and must be greater than current amount
  if (value >= 0) {
    Resources::getResourcesInstance().setWaterUsage(value);
    return;
  }
}

void ResourceManager::setPowerUsage(double value) {
  // must set positive amount and must be greater than current amount
  if (value >= 0) {
    Resources::getResourcesInstance().setPowerUsage(value);
    return;
  }
}

void ResourceManager::setSewageUsage(double value) {
  // must set positive amount and must be greater than current amount
  if (value >= 0) {
    Resources::getResourcesInstance().setSewageUsage(value);
    return;
  }
}

void ResourceManager::setWasteUsage(double value) {
  // must set positive amount 
  if (value >= 0) {
    Resources::getResourcesInstance().setWasteUsage(value);
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

int ResourceManager::getWaste() {
  return Resources::getResourcesInstance().getWaste();
}

int ResourceManager::getWaterConsumption() {
  return Resources::getResourcesInstance().getWaterConsumption();
}

int ResourceManager::getPowerConsumption() {
  return Resources::getResourcesInstance().getPowerConsumption();
}

int ResourceManager::getSewageConsumption() {
  return Resources::getResourcesInstance().getSewageConsumption();
}

int ResourceManager::getWasteConsumption() {
  return Resources::getResourcesInstance().getWasteConsumption();
}

double ResourceManager::getWaterUsage() {
  return Resources::getResourcesInstance().getWaterUsage();
}

double ResourceManager::getPowerUsage() {
  return Resources::getResourcesInstance().getPowerUsage();
}

double ResourceManager::getSewageUsage() {
  return Resources::getResourcesInstance().getSewageUsage();
}

double ResourceManager::getWasteUsage() {
  return Resources::getResourcesInstance().getWasteUsage();
}