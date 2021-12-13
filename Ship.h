//
// Created by Sheldon on 10/5/2019.
//

#ifndef UNTITLED_SHIP_H
#define UNTITLED_SHIP_H

#include "RectangleClass.h"
#include "Target.h"
#include "PointClass.h"
#include <vector>
#include <string>
using namespace std;

class Ship:public Rectangle{

private:
    string ShipName;
    vector<Target> targets;
    bool status = false;
    void InstantiateTargets(const Point& p,int l);
    bool isVertical = false;

public:
    Ship();
    Ship(string name, Point p, bool isVert);//string name, Position of ship, alignment horizontal=false, vertical = true
    void Build(string name,Point p, bool isVert);
    string getName()const;
    void setName(string name);
    vector<Target>& RetrieveTargets();
    void hitTarget(Target& t);
    void checkStatus_1();//game variant requiring all targets
    void checkStatus_2();//game variant requiring one target
    bool Destroyed() const ;
    void RemoveTargets();

};


#endif //UNTITLED_SHIP_H
