#ifndef POINT
#define POINT

struct Point {
    int x;
    int y;

    //constructeur par défaut
    Point(int x=0, int y=0) : x(x), y(y) {}
};

#endif