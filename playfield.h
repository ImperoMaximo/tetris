#ifndef PLAYFIELD
#define PLAYFIELD

#include <string>
#include <iostream>
#include "cell.h"

using namespace std;

struct Point{
    int x;
    int y;
};

class Playfield {
    private:
    int width, height;
    Cell ***grid;

    public:
    Playfield(int w, int h);
    ~Playfield();

    Cell* getCell(Point pos);
    void setCell(Point pos, Cell* cell);
    int eraseFullRows();
    void display();

};
#endif