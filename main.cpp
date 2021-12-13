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
#include "GameBoard.h"
#include "BattleShipGame.h"

using namespace std;



int main() {
    srand(time(0));
    BattleShipGame Game;

    Game.Menu();
    return 0;
}