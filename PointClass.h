#ifndef PointClass_H
#define PointClass_H

class Point {

public:

    Point();
    Point(int x, int y);

    void SetX(int x);
    void SetY(int y);
    int GetX() const;
    int GetY() const;

private:

    int xCO;
    int yCO;

};

#endif
