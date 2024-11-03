#include "SLReceiver.h"

void SLReceiver::update(double satisfaction){
    if(this->cty){
        this->cty->satisfaction = satisfaction;  // Update the city's satisfaction level
    }
}