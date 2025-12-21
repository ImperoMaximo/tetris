#ifndef PLAYFIELD
#define PLAYFIELD

#include <string>
#include <iostream>
#include "cell.hpp"

using namespace std;

class Playfield {
    private:
    int width, height;
    Cell ***grid;

    public:
    Playfield(int w = 10, int h = 20);
    ~Playfield();

    Cell* getCell(Point pos);
    void setCell(Point pos, Cell* cell);
    void eraseFullRow(int row_y);
    void display();
};
#endif