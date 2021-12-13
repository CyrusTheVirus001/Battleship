#include "Ship.h"
#include "Player.h"
#include "Target.h"
#include "PointClass.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include "Enemy.h"

void Enemy::PopulateShips() {
    int x,y;
    int counter;
    Point temp;
    bool isVertical;
    vector<Target> tempTargets;

            RandomizeNumbers(x, y, temp, isVertical);
            Carrier.Build("Carrier", temp, isVertical);
            CheckShipPositions(Carrier, x, y, temp, isVertical, tempTargets);

            RandomizeNumbers(x, y, temp, isVertical);
            Battleship.Build("Battleship", temp, isVertical);
            CheckShipPositions(Battleship, x, y, temp, isVertical, tempTargets);

            RandomizeNumbers(x, y, temp, isVertical);
            Cruiser.Build("Cruiser", temp, isVertical);
            CheckShipPositions(Cruiser, x, y, temp, isVertical, tempTargets);

            RandomizeNumbers(x, y, temp, isVertical);
            Submarine.Build("Submarine", temp, isVertical);
            CheckShipPositions(Submarine, x, y, temp, isVertical, tempTargets);

            RandomizeNumbers(x, y, temp, isVertical);
            Destroyer.Build("Destroyer", temp, isVertical);
            CheckShipPositions(Destroyer, x, y, temp, isVertical, tempTargets);

}

void Enemy::RandomizeNumbers(int& x, int& y, Point& p, bool& v){
    x = (rand() % 10) + 1;
    y = (rand() % 10) + 1;
    if(rand() % 100 < 50){
        v = true;
    }
    else{
        v = false;
    }
    p.SetX(x);
    p.SetY(y);
}

Ship& Enemy::getShip(string ShipName) {
    if(ShipName == "Carrier"){
        return Carrier;
    }
    else if(ShipName == "Battleship"){
        return Battleship;
    }
    else if(ShipName == "Submarine"){
        return Submarine;
    }
    else if(ShipName == "Cruiser"){
        return Cruiser;
    }
    else if(ShipName == "Destroyer"){
        return Destroyer;
    }
}

void Enemy::CheckShipPositions(Ship& ship, int& x, int& y, Point& temp, bool& v, vector<Target>& tempTargets) {
    int n = ship.RetrieveTargets().size();
    bool placementGood;

    placementGood = true;


    if(ship.RetrieveTargets()[n-1].GetX() > 10 || ship.RetrieveTargets()[n-1].GetY() > 10){

        RandomizeNumbers(x,y,temp,v);
        ship.RemoveTargets();

        ship.Build(ship.getName(),temp,v);
        return CheckShipPositions(ship,x,y,temp,v,tempTargets);
    }
    for(int i=0; i<ship.RetrieveTargets().size(); i++){
        for(int j = 0; j < tempTargets.size();j++){
            if(tempTargets[j].GetX() == ship.RetrieveTargets()[i].GetX() && tempTargets[j].GetY() == ship.RetrieveTargets()[i].GetY()){
                cout<<tempTargets[j].GetX()<<" ' "<<tempTargets[j].GetY()<<endl;
                cout<<tempTargets.size()<<endl;
                placementGood = false;
                break;
            }
        }
        if(!placementGood){
            break;
        }
    }
    if(!placementGood){

        RandomizeNumbers(x,y,temp,v);
        ship.RemoveTargets();
        ship.Build(ship.getName(),temp,v);
        return CheckShipPositions(ship,x,y,temp,v,tempTargets);
    }
    else {
        for (int i = 0; i < ship.RetrieveTargets().size(); i++) {
            tempTargets.push_back(ship.RetrieveTargets()[i]);
        }
    }

}

Point Enemy::MakeGuessSimple() {
    int x = (rand() % 10) + 1;
    int y = (rand() % 10) + 1;
    Point temp(x,y);
    for(int i=0;i<BoardData.size();i++){
        if(temp.GetX() == BoardData[i].GetX() && temp.GetY() == BoardData[i].GetY()){
            return MakeGuessSimple();
        }
    }
    cout<<"The Enemy Has Attacked Position ("<<temp.GetX()<<","<<temp.GetY()<<")"<<endl;
    //BoardData.push_back(temp);
    return temp;
}

void Enemy::UpdateData(const Point &p) {
    BoardData.push_back(p);
}