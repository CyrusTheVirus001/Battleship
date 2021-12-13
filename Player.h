#ifndef Player_H
#define Player_H

#include "Ship.h"
#include "PointClass.h"
#include "BattleShipGrid.h"

class Player{
private:
    Ship Carrier;
    Ship Battleship;
    Ship Cruiser;
    Ship Submarine;
    Ship Destroyer;

public:
    void PopulateShipsFromFile();
    Point ConvertCoordinate(string s);
    Ship& getShip(string ShipName);
    Point MakeGuess();
};

class ShipNameError{};
class ShipPlacementError{};
class AlignmentError{};


#endif //PLAYER_H
