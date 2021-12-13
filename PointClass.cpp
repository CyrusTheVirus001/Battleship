#include "PointClass.h"

Point::Point() {
    xCO = 0;
    yCO = 0;
}

Point::Point(int x, int y) :xCO(x), yCO(y) {};


void Point::SetX(int x) {

    xCO = x;

}

void Point::SetY(int y) {

    yCO = y;

}

int Point::GetX() const {

    return xCO;

}

int Point::GetY() const {

    return yCO;

}

