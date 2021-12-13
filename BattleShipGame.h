#ifndef UNTITLED_BATTLESHIPGAME_H
#define UNTITLED_BATTLESHIPGAME_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Ship.h"
#include "Player.h"
#include "GridSquare.h"
#include "GridClass.h"
#include "BattleShipGrid.h"
#include "Enemy.h"
#include <time.h>

class BattleShipGame{
private:
    vector<Point> PlayerData;
    bool simpleVersion = false;
    bool testMode = false;
public:
    Player *playerOne = new Player;
    Enemy *enemy = new Enemy;
    BattleshipGrid *PG = new BattleshipGrid;
    BattleshipGrid *EG = new BattleshipGrid;

    void PlayGame();
    void InitializePlayerStates();
    void Menu();
    void PlayersTurn();
    void EnemyTurn();

    bool checkForWinners();
};



#endif //UNTITLED_BATTLESHIPGAME_H
