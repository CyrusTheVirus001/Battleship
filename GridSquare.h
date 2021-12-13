//
// Created by Sheldon on 10/18/2019.
//

#ifndef UNTITLED_GRIDSQUARE_H
#define UNTITLED_GRIDSQUARE_H

class GridSquare{

private:
    char data = ' ';
    char tr = 187;
    char br = 188;
    char tl = 201;
    char bl = 200;
    char vl = 186;
    char hl = 205;
public:
    void drawSquare();
    void drawTopline();
    void drawMidline();
    void drawBottomline();
    void setData(const char& c );
    char getData() const;
};

#endif //UNTITLED_GRIDSQUARE_H
