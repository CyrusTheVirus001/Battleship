#include "Ship.h"
#include "PointClass.h"
#include "RectangleClass.h"

/*
Ship Constructor, Requires Exact Name, Location, Alignment; will then Create Correct Type of Ship
*/
Ship::Ship():Rectangle(){};


Ship::Ship(string name, Point p, bool isVert ):Rectangle(){

    ShipName = name;
    isVertical = isVert;

    if(ShipName == "Carrier"){
        if(isVertical){
            SetRectangle(p,5,0);
            InstantiateTargets(p,5);
        }
        else{
            SetRectangle(p,0,5);
            InstantiateTargets(p,5);
        }
    }
    else if(ShipName == "Battleship"){
        if(isVertical){
            SetRectangle(p,4,0);
            InstantiateTargets(p,4);
        }
        else{
            SetRectangle(p,0,4);
            InstantiateTargets(p,4);
        }
    }
    else if(ShipName == "Cruiser"){
        if(isVertical){
            SetRectangle(p,3,0);
            InstantiateTargets(p,3);
        }
        else{
            SetRectangle(p,0,3);
            InstantiateTargets(p,3);
        }
    }
    else if(ShipName == "Submarine"){
        if(isVertical){
            SetRectangle(p,3,0);
            InstantiateTargets(p,3);
        }
        else{
            SetRectangle(p,0,3);
            InstantiateTargets(p,3);
        }
    }
    else if(ShipName == "Destroyer"){
        if(isVertical){
            SetRectangle(p,2,0);
            InstantiateTargets(p,2);
        }
        else{
            SetRectangle(p,0,2);
            InstantiateTargets(p,2);
        }
    }


}

void Ship::Build(string name, Point p, bool isVert ){

    ShipName = name;
    isVertical = isVert;

    if(ShipName == "Carrier"){
        if(isVertical){
            SetRectangle(p,0,4);
            InstantiateTargets(p,5);
        }
        else{
            SetRectangle(p,4,0);
            InstantiateTargets(p,5);
        }
    }
    else if(ShipName == "Battleship"){
        if(isVertical){
            SetRectangle(p,0,3);
            InstantiateTargets(p,4);
        }
        else{
            SetRectangle(p,3,0);
            InstantiateTargets(p,4);
        }
    }
    else if(ShipName == "Cruiser"){
        if(isVertical){
            SetRectangle(p,0,2);
            InstantiateTargets(p,3);
        }
        else{
            SetRectangle(p,2,0);
            InstantiateTargets(p,3);
        }
    }
    else if(ShipName == "Submarine"){
        if(isVertical){
            SetRectangle(p,0,2);
            InstantiateTargets(p,3);
        }
        else{
            SetRectangle(p,2,0);
            InstantiateTargets(p,3);
        }
    }
    else if(ShipName == "Destroyer"){
        if(isVertical){
            SetRectangle(p,0,1);
            InstantiateTargets(p,2);
        }
        else{
            SetRectangle(p,1,0);
            InstantiateTargets(p,2);
        }
    }


}

/*
Will Create All targets for Ship
*/

void Ship::InstantiateTargets(const Point& p, int l) {
    Target t;
    for(int i=0;i<l;i++){
        if(!isVertical) {
            t.SetX(p.GetX() + i);
            t.SetY(p.GetY());
            targets.push_back(t);
        }
        else{
            t.SetX(p.GetX());
            t.SetY(p.GetY()+i);
            targets.push_back(t);
        }
    }
}

string Ship::getName() const {
    return ShipName;
}

void Ship::setName(string name){
    ShipName = name;
}

vector<Target>& Ship::RetrieveTargets()  {
    return targets;
}

void Ship::hitTarget(Target &t) {
    t.ChangeStatus(true);
}

/*
Cycles Through Each Target and Determines whether the Ship has been Destroyed
*/

void Ship::checkStatus_1()  {
    int count = 0;
    for(int i=0;i<targets.size();i++){
        if(targets[i].Status()){
            count++;
        }
    }
    if(count == targets.size()){
        status = true;

    }

}

void Ship::checkStatus_2() {
    for(int i=0;i<targets.size();i++){
        if(targets[i].Status()){
            status = true;
        }
    }
}

/*
Returns Status of the Ship i.e. been destroyed? true for yes, false for no
*/

bool Ship::Destroyed() const{
    return status;
}

void Ship::RemoveTargets() {
    targets.clear();
    Point p(0,0);
    SetRectangle(p,0,0);
}
