#ifndef CELL
#define CELL

#include <string>

using namespace std;

struct Point{
    int x;
    int y;
};

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
    void clear();

};
#endif