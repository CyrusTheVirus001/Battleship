#include "PointClass.h"
#include "RectangleClass.h"
#include <iostream>



Rectangle::Rectangle() {

    length = 0;
    width = 0;

}

Rectangle::Rectangle(Point p, int w, int l) {

    topLeft = p;
    width = w;
    length = l;
    topRight = FindTopRightPoint(topLeft, width);
    bottomLeft = FindBottomLeftPoint(topLeft, length);
    bottomRight = FindBottomRightPoint(topLeft, width, length);

}

Point Rectangle::FindBottomLeftPoint(Point p, int l) const {

    p.SetY(p.GetY() - l);

    return p;

}

Point Rectangle::FindBottomRightPoint(Point p, int w, int l) const {

    p.SetY(p.GetY() - l);
    p.SetX(p.GetX() + w);

    return p;

}

Point Rectangle::FindTopRightPoint(Point p, int w) const {

    p.SetX(p.GetX() + w);

    return p;

}

void Rectangle::SetRectangle(Point p, int w, int l) {

    topLeft = p;
    width = w;
    length = l;
    topRight = FindTopRightPoint(topLeft, width);
    bottomLeft = FindBottomLeftPoint(topLeft, length);
    bottomRight = FindBottomRightPoint(topLeft, width, length);

}

void Rectangle::RectInfo() {

    std::cout << "(" << GetTopLeftPoint().GetX() << "," << GetTopLeftPoint().GetY() << "), "
              << "(" << GetTopRightPoint().GetX() << "," << GetTopRightPoint().GetY() << "), "
              << "(" << GetBottomLeftPoint().GetX() << "," << GetBottomLeftPoint().GetY() << "), "
              << "(" << GetBottomRightPoint().GetX() << "," << GetBottomRightPoint().GetY() << ") ";


}
int Rectangle::GetLength() const {
    return length;
}

int Rectangle::GetWidth() const {
    return width;
}

Point Rectangle::GetTopLeftPoint() const {
    return topLeft;
}

Point Rectangle::GetBottomLeftPoint() const {
    return bottomLeft;
}

Point Rectangle::GetTopRightPoint() const {
    return topRight;
}

Point Rectangle::GetBottomRightPoint() const {
    return bottomRight;
}


