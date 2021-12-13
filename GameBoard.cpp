#include "GameBoard.h"
#include <iostream>



void GameBoard::DisplayBoard(const BattleshipGrid &playerGrid, const BattleshipGrid &EnemyGrid) {


    for (int i = 0; i < playerGrid.getGridSquare().size(); i++)
    {
        for (int j = 0; j < playerGrid.getGridSquare()[i].size(); j++)
        {
            playerGrid.getGridSquare()[i][j].drawTopline();
        }
        std::cout<<"   ";
        for (int j = 0; j < EnemyGrid.getGridSquare()[i].size(); j++)
        {
            EnemyGrid.getGridSquare()[i][j].drawTopline();
        }
        std::cout<<endl;

        for(int j=0; j < playerGrid.getGridSquare()[i].size(); j++){

            playerGrid.getGridSquare()[i][j].drawMidline();
        }
        std::cout<<"   ";
        for(int j=0; j < EnemyGrid.getGridSquare()[i].size(); j++){

            EnemyGrid.getGridSquare()[i][j].drawMidline();
        }
        std::cout<<endl;

        for(int j=0;j < playerGrid.getGridSquare()[i].size();j++){
            playerGrid.getGridSquare()[i][j].drawBottomline();
        }
        std::cout<<"   ";
        for(int j=0;j < EnemyGrid.getGridSquare()[i].size();j++){
            EnemyGrid.getGridSquare()[i][j].drawBottomline();
        }
        std::cout<<endl;
    }
}

