#ifndef UNTITLED_ENEMY_H
#define UNTITLED_ENEMY_H
#include "Ship.h"
#include "PointClass.h"
#include "PointClass.h"

class Enemy{
private:
    Ship Carrier;
    Ship Battleship;
    Ship Cruiser;
    Ship Submarine;
    Ship Destroyer;

public:
    vector<Point> BoardData;
    void PopulateShips();
    void RandomizeNumbers(int& x, int& y, Point& p, bool& v);
    Ship& getShip(string ShipName);
    void CheckShipPositions(Ship& ship, int& x, int& y, Point& temp, bool& v,vector<Target>& tempTargets);
    Point MakeGuessSimple();
    void UpdateData(const Point& p);
};

#endif //UNTITLED_ENEMY_H
