#ifndef TETROMINO
#define TETROMINO

#include <string>

using namespace std;

struct Point{
    int x;
    int y;
};

class Tetromino{
    protected:
    int state;
    string color;
    Point **shapes = new Point*[4], pos;
    //pourquoi une donnée de vitesse dans le diagr de classes ?

    public:
    Tetromino();
    Tetromino(const Tetromino& T);
    ~Tetromino();

    int getState();
    int getAbsPos();
    Point* getShape();
    void rotateLeft();
    void rotateRight();
    Point* operator[](const int i) const;
};
#endif