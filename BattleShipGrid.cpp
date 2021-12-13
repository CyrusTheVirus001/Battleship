#include "BattleShipGrid.h"
#include <iostream>

BattleshipGrid::BattleshipGrid(int row, int column):Grid(row,column, true) {
    gridSquare[0][0].setData(' ');
    char c = 'A';
    char C = '1';
    for(int i = 1; i < gridSquare[0].size(); i++){
        gridSquare[0][i].setData(c);
        gridSquare[i][0].setData(C);
        c++;
        C++;
    }
    gridSquare[10][0].setData('0');
}

BattleshipGrid::BattleshipGrid():Grid(11,11,true) {
    gridSquare[0][0].setData(' ');
    char c = 'A';
    char C = '1';
    for(int i = 1; i < gridSquare[0].size(); i++){
        gridSquare[0][i].setData(c);
        gridSquare[i][0].setData(C);
        c++;
        C++;
    }
    gridSquare[10][0].setData('0');
}

void BattleshipGrid::DisplaySquare(int x, int y) {

    gridSquare[y][x].drawSquare();

}

void BattleshipGrid::setData(const int &x,const int &y, const char &c)  {
    gridSquare[x][y].setData(c);
}

void BattleshipGrid::DisplayGrid() {
    for (int i = 0; i < gridSquare.size(); i++)
    {
        for (int j = 0; j < gridSquare[i].size(); j++)
        {
            gridSquare[i][j].drawTopline();
        }
        std::cout<<endl;
        for(int j=0; j < gridSquare[i].size(); j++){

            gridSquare[i][j].drawMidline();
        }
        std::cout<<endl;
        for(int j=0;j < gridSquare[i].size();j++){
            gridSquare[i][j].drawBottomline();
        }
        std::cout<<endl;
    }
}

void BattleshipGrid::PopulateGrid(Ship &carrier, Ship &battleship,Ship &submarine,
            Ship &cruiser, Ship &destroyer){

try {
    checkPosition(carrier,0);
    gridSquare[carrier.RetrieveTargets()[0].GetY()][carrier.RetrieveTargets()[0].GetX()].setData('C');
    checkPosition(carrier,1);
    gridSquare[carrier.RetrieveTargets()[1].GetY()][carrier.RetrieveTargets()[1].GetX()].setData('C');
    checkPosition(carrier,2);
    gridSquare[carrier.RetrieveTargets()[2].GetY()][carrier.RetrieveTargets()[2].GetX()].setData('C');
    checkPosition(carrier,3);
    gridSquare[carrier.RetrieveTargets()[3].GetY()][carrier.RetrieveTargets()[3].GetX()].setData('C');
    checkPosition(carrier,4);
    gridSquare[carrier.RetrieveTargets()[4].GetY()][carrier.RetrieveTargets()[4].GetX()].setData('C');
    checkPosition(battleship,0);
    gridSquare[battleship.RetrieveTargets()[0].GetY()][battleship.RetrieveTargets()[0].GetX()].setData('B');
    checkPosition(battleship,1);
    gridSquare[battleship.RetrieveTargets()[1].GetY()][battleship.RetrieveTargets()[1].GetX()].setData('B');
    checkPosition(battleship,2);
    gridSquare[battleship.RetrieveTargets()[2].GetY()][battleship.RetrieveTargets()[2].GetX()].setData('B');
    checkPosition(battleship,3);
    gridSquare[battleship.RetrieveTargets()[3].GetY()][battleship.RetrieveTargets()[3].GetX()].setData('B');
    checkPosition(submarine,0);
    gridSquare[submarine.RetrieveTargets()[0].GetY()][submarine.RetrieveTargets()[0].GetX()].setData('S');
    checkPosition(submarine,1);
    gridSquare[submarine.RetrieveTargets()[1].GetY()][submarine.RetrieveTargets()[1].GetX()].setData('S');
    checkPosition(submarine,2);
    gridSquare[submarine.RetrieveTargets()[2].GetY()][submarine.RetrieveTargets()[2].GetX()].setData('S');
    checkPosition(cruiser,0);
    gridSquare[cruiser.RetrieveTargets()[0].GetY()][cruiser.RetrieveTargets()[0].GetX()].setData('c');
    checkPosition(cruiser,1);
    gridSquare[cruiser.RetrieveTargets()[1].GetY()][cruiser.RetrieveTargets()[1].GetX()].setData('c');
    checkPosition(cruiser,2);
    gridSquare[cruiser.RetrieveTargets()[2].GetY()][cruiser.RetrieveTargets()[2].GetX()].setData('c');
    checkPosition(destroyer,0);
    gridSquare[destroyer.RetrieveTargets()[0].GetY()][destroyer.RetrieveTargets()[0].GetX()].setData('D');
    checkPosition(destroyer,1);
    gridSquare[destroyer.RetrieveTargets()[1].GetY()][destroyer.RetrieveTargets()[1].GetX()].setData('D');
}
catch(OverLapError){
    cout<<"One or More of Your Ships Overlap! Please Correct This Issue and Try Again..."<<endl;
    exit(0);
}
catch(OutofBoundsError){
    cout<<"One or More of Your Ships do not fit within Grid! Please Correct This Issue and Try Again..."<<endl;
    exit(0);
}
}

char BattleshipGrid::FindElementAt(const int& x,const int& y) const{

   return gridSquare[x][y].getData();

}

void BattleshipGrid::checkPosition( Ship& ship, int value){
    if (ship.RetrieveTargets()[value].GetX() > getRows()-1 || ship.RetrieveTargets()[value].GetY() > getColumns()-1 ||
        ship.RetrieveTargets()[value].GetX() <= 0 || ship.RetrieveTargets()[value].GetY() <= 0) {
        throw OutofBoundsError();
    }
    if (FindElementAt(ship.RetrieveTargets()[value].GetY(), ship.RetrieveTargets()[value].GetX()) != ' ') {
        throw OverLapError();
    }
}

vector<vector<GridSquare>> BattleshipGrid::getGridSquare() const {
    return gridSquare;
}