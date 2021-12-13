
#ifndef UNTITLED_BATTLESHIPGRID_H
#define UNTITLED_BATTLESHIPGRID_H
#include "GridClass.h"
#include "Ship.h"

class BattleshipGrid:public Grid{
public:
    BattleshipGrid(int row,int column);
    BattleshipGrid();
    void DisplaySquare(int x, int y);
    void setData(const int &x,const int &y,const char &c) ;
    void DisplayGrid();
    void PopulateGrid( Ship &carrier, Ship &battleship, Ship &submarine, Ship &cruiser, Ship &destroyer);
    char FindElementAt(const int& x,const int& y) const;
    void checkPosition( Ship& ship, int value);
    vector<vector<GridSquare>> getGridSquare() const;
};

class OverLapError{};
class OutofBoundsError{};



#endif //UNTITLED_BATTLESHIPGRID_H
