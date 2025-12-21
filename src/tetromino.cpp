#include "tetromino.hpp"

Tetromino::Tetromino(int state, string color, Point pos) : state(state), color(color), shapes{}, pos(pos) {}

Tetromino::Tetromino(const Tetromino &T) : state(T.state), color(T.color), shapes(T.shapes), pos(T.pos) {}

int Tetromino::getState() { return state; }

Point Tetromino::getPos() { return pos; }

void Tetromino::setPos(Point p) { pos = p; }

void Tetromino::rotateLeft() { state = (state + 3) % 4; }

void Tetromino::rotateRight() { state = (state + 1) % 4; }

array<Point, 4> Tetromino::operator[](const int i) const { return shapes[i]; }
