#include "Resources.h"

int Resources::getWater() { return water; }

int Resources::getPower() { return power; }

int Resources::getSewage() { return sewage; }

int Resources::getMaterial() { return materials; }

void Resources::setWater(int value) { water = value; }

void Resources::setPower(int value) { power = value; }

void Resources::setSewage(int value) { sewage = value; }

void Resources::setMaterial(int value) { materials = value; }

void Resources::consumeWater(int value) { water -= value; }

void Resources::consumePower(int value) { power -= value; }

void Resources::consumeSewage(int value) { sewage -= value; }

void Resources::consumeMaterial(int value) { materials -= value; }

Resources::Resources() {}

Resources &Resources::getResourcesInstance() {
  static Resources onlyInstance;
  return onlyInstance;
}
