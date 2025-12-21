#ifndef TETROMINO
#define TETROMINO

#include <string>
#include <array>
#include "point.hpp"

using namespace std;

class Tetromino{
    protected:
    int state;
    string color;
    array<array<Point,4>,4> shapes;
    Point pos;
    //pourquoi une donnée de vitesse dans le diagr de classes ?

    public:
    Tetromino(int state=0, string color="grey", Point pos=Point{});
    Tetromino(const Tetromino& T);

    int getState();
    Point getPos();
    void setPos(Point p);
    void rotateLeft();
    void rotateRight();
    array<Point,4> operator[](const int i) const;
};
#endif