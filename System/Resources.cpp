#include "Resources.h"
#include <iostream>


int Resources::getWater() { return waterProduced; }

int Resources::getPower() { return powerProduced; }

int Resources::getSewage() { return sewageProduced; }

int Resources::getWaste() { return wasteProduced; }

int Resources::getWaterConsumption() { return waterConsumption; }

int Resources::getPowerConsumption() { return powerConsumption; }

int Resources::getSewageConsumption() { return sewageConsumption; }

int Resources::getWasteConsumption() { return wasteConsumption; }

double Resources::getWaterUsage() { return waterUsage; }

double Resources::getPowerUsage() { return powerUsage; }

double Resources::getSewageUsage() { return sewageUsage; }

double Resources::getWasteUsage() { return wasteUsage; }

void Resources::setWater(int value) { waterProduced = value; }

void Resources::setPower(int value) { powerProduced = value; }

void Resources::setSewage(int value) { sewageProduced = value; }

void Resources::setWaste(int value) { wasteProduced = value; }

void Resources::setWaterConsumption(int value) { waterConsumption = value; }

void Resources::setPowerConsumption(int value) { powerConsumption = value; }

void Resources::setSewageConsumption(int value) { sewageConsumption = value; }

void Resources::setWasteConsumption(int value) { wasteConsumption = value; }

void Resources::setWaterUsage(double value) { waterUsage = value; }

void Resources::setPowerUsage(double value) { powerUsage = value; }

void Resources::setSewageUsage(double value) { sewageUsage = value; }

void Resources::setWasteUsage(double value) { wasteUsage = value; }


Resources::Resources() {}

Resources& Resources::getResourcesInstance() {
    static Resources onlyInstance;
    return onlyInstance;
}