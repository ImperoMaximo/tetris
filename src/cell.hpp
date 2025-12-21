#ifndef CELL
#define CELL

#include <string>
#include "point.hpp"

using namespace std;

class Cell {
    private:
    Point pos;
    bool taken;
    string color;

    public:
    Cell(Point p = {0,0}, bool t = false, string c = "grey");

    bool isTaken() const;
    string getColor() const;
    void colonize(string colour);
    void clear();   //pas sur de l'utilité de cette fonction
};
#endif