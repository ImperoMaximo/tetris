#include "tetromino.h"

Tetromino::Tetromino() {
    abs_pos = 0;
    state = 0;
    for(int i =0;i<4;i++) {
        pos_register[i] = new Point[4];
        for(int j=0;j<4;j++)
            pos_register[i][j] = {0,0};
    }
}

Tetromino::Tetromino(const Tetromino &T) {
    abs_pos = T.abs_pos;
    state = T.state;
    for(int i =0;i<4;i++) {
        pos_register[i] = new Point[4];
        for(int j=0;j<4;j++)
            pos_register[i][j] = T.pos_register[i][j];
    }
}

Tetromino::~Tetromino() {
    for(int i =0;i<4;i++)
        delete[] pos_register[i];
    delete[] pos_register;
}

int Tetromino::getState() { return state; }

int Tetromino::getAbsPos() { return abs_pos; }

void Tetromino::setAbsPos(int h) { abs_pos = h; }

Tetromino Tetromino::rotate() const {
    Tetromino temp(*this);
    temp.state = (temp.state + 1) % 4;
    return temp;
}

void Tetromino::rotate() { this->state=(this->state+1) % 4; }

Point *Tetromino::operator[](const int i) const { return pos_register[i]; }
