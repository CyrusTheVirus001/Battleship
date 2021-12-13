#include "Target.h"

void Target::ChangeStatus(bool newStatus){
    hasBeenHit = newStatus;
}

bool Target::Status() const{
    return hasBeenHit;
}


