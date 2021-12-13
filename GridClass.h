
#ifndef GridClass_H

#define GridClass_H
#include <vector>
#include "GridSquare.h"

using namespace std;

class Grid {

private:

    vector<vector<int> > grid;
    int rows;
    int columns;

public:

    Grid(int row, int column,bool isGridSquare);

    void Display() const;

    void RandomlyPopulate();

    int getRows() const;
    int getColumns() const;

    int FindElementAt(int x, int y);

    void SetElementAt(int x, int y, int a);

protected:
    vector<vector<GridSquare>> gridSquare;

};

#endif
