#include "tetromino.h"

Tetromino::Tetromino(int state, string color, Point pos) : pos(pos), state(state), color(color), shapes{} {}

Tetromino::Tetromino(const Tetromino &T) : pos(T.pos), state(T.state), shapes(T.shapes), color(T.color) {}

int Tetromino::getState() { return state; }

Point Tetromino::getPos() { return pos; }

void Tetromino::setPos(Point p) { pos = p; }

void Tetromino::rotateLeft() { state = (state + 3) % 4; }

void Tetromino::rotateRight() { state = (state + 1) % 4; }

array<Point, 4> Tetromino::operator[](const int i) const { return shapes[i]; }
