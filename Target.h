//
// Created by Sheldon on 10/5/2019.
//

#ifndef TARGET_H
#define TARGET_H

#include "PointClass.h"

class Target:public Point{

private:
    bool hasBeenHit = false;

public:

    void ChangeStatus(bool newStatus);
    bool Status() const;

};


#endif //TARGET_H
