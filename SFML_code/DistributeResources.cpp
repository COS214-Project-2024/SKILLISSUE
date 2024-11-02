#include "DistributeResources.h"

void DistributeResources::execute() {
    receiver->update();  // Calls the receiver's update function
}
