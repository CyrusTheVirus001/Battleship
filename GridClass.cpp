#include "GridClass.h"
#include <iostream>
#include <vector>

using namespace std;

//Constructor
Grid::Grid(int row, int column, bool isGridSqaure)
{
    rows = row;
    columns = column;
if(!isGridSqaure) {
    for (int i = 0; i < rows; i++) {

        vector<int> PopulateRow;

        for (int j = 0; j < columns; j++) {

            PopulateRow.push_back(0);

        }

        grid.push_back(PopulateRow);

    }
}
else {
    for (int i = 0; i < rows; i++) {

        vector<GridSquare> PopulateRow;

        for (int j = 0; j < columns; j++) {

            PopulateRow.push_back(GridSquare());

        }

        gridSquare.push_back(PopulateRow);

    }
}

}



//Displays Grid on Screen
void Grid::Display() const {

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            cout << grid[i][j]<<" ";
        }
        cout << endl;
    }

}

//Randomly assigns 1 or 0 to each element of Grid
void Grid::RandomlyPopulate() {

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            grid[i][j] = rand() % 2;
        }
    }
}

//Get Function
int Grid::FindElementAt(int x, int y){
    return grid[x][y];
}

//SetFunction
void Grid::SetElementAt(int x, int y, int a) {
    grid[x][y] = a;
}

//GetFunctions
int Grid::getRows() const {
    return rows;
}

int Grid::getColumns() const {
    return columns;
}
