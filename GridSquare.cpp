#include "GridSquare.h"
#include <iostream>
using namespace std;
void GridSquare::drawSquare() {

    cout<<tl<<hl<<hl<<hl<<tr<<"   "<<endl;
    cout<<vl<<" "<<data<<" "<<vl<<"   "<<endl;
    cout<<bl<<hl<<hl<<hl<<br<<"   "<<endl;


}

void GridSquare::drawTopline() {
    cout<<tl<<hl<<hl<<hl<<tr<<" ";
}

void GridSquare::drawMidline() {
    cout<<vl<<" "<<data<<" "<<vl<<" ";
}

void GridSquare::drawBottomline() {
    cout<<bl<<hl<<hl<<hl<<br<<" ";
}

void GridSquare::setData(const char &c) {
    data = c;
}

char GridSquare::getData() const {
    return data;
}



