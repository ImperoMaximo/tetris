#ifndef TETROMINO
#define TETROMINO

// #include "point.h"
struct Point{
    int x;
    int y;
};

class Tetromino{
    protected:
    int abs_pos, state;
    Point **pos_register = new Point*[4];
    public:
    Tetromino();
    Tetromino(const Tetromino& T);
    ~Tetromino();
    int getState();
    int getAbsPos();
    void setAbsPos(int i);
    Tetromino rotate() const;
    void rotate();
    Point* operator[](const int i) const;
};
#endif