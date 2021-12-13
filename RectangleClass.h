#ifndef RectangleClass_H
#define RectangleClass_H
#include "PointClass.h"


class Rectangle {

public:
    Rectangle();
    Rectangle(Point p, int w, int l);

    void SetRectangle(Point p, int w, int l);

    int GetWidth() const;
    int GetLength() const;

    Point GetTopLeftPoint() const;
    Point GetTopRightPoint() const;
    Point GetBottomLeftPoint() const;
    Point GetBottomRightPoint() const;

    void RectInfo();

private:

    Point topLeft;
    Point topRight;
    Point bottomLeft;
    Point bottomRight;
    int  length;
    int width;

    Point FindBottomLeftPoint(Point p, int l) const;
    Point FindBottomRightPoint(Point p, int w, int l) const;
    Point FindTopRightPoint(Point p, int w) const;
};
#endif
