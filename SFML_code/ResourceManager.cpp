#include "ResourceManager.h"

ResourceManager::ResourceManager() {
    resources=resources.getResources();
}

int ResourceManager::getWater(int value) {
    //Must request less than 20% of water available
    if(value< (0.2 * resources.getWater(value))) {
        return resources.consumeWater(value);
    }else{ return -1;}
}

int ResourceManager::getPower(int value) {
    //Must request less than 40% of power available
    if(value< (0.4 * resources.getPower(value))) {
        return resources.consumePower(value);
    }else{ return -1;}
}

int ResourceManager::getSewage(int value) {
    //Must request less than 60% of power available
    if(value< (0.6 * resources.getSewage(value))) {
        return resources.consumeSewage(value);
    }else{ return -1;}
}

int ResourceManager::getMaterial(int value) {
   //Must request less than 80% of water available
    if(value< (0.8 * resources.getWater(value))) {
        return resources.consumeWater(value);
    }else{ return -1;}
}

void ResourceManager::setWater(int value) {
    //must set positive amount and must be greater than current amount
	if(value > 0 and value>= resources.getWater(value)){
        resources.setWater(value);
        return;
    }
}

void ResourceManager::setPower(int value) {
    //must set positive amount and must be greater than current amount
	if(value > 0 and value>= resources.getPower(value)){
        resources.setPower(value);
        return;
    }
}

void ResourceManager::setSewage(int value) {
    //must set positive amount and must be greater than current amount
	if(value > 0 and value>= resources.getSewage(value)){
        resources.setSewage(value);
        return;
    }
}

void ResourceManager::setMaterial(int value) {
    //must set positive amount and must be greater than current amount
	if(value > 0 and value>= resources.getMaterial(value)){
        resources.setMaterial(value);
        return;
    }
}