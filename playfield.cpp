#include "playfield.h"

Playfield::Playfield(int w, int h) : width(w), height(h) {
    grid = new Cell**[height];
    for (int i = 0; i < height; i++) {
        grid[i] = new Cell*[width];
        for (int j = 0; j < width; j++) {
            grid[i][j] = new Cell({j, i});
        }
    }
}

Playfield::~Playfield() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            delete grid[i][j];
        }
        delete[] grid[i];
    }
    delete[] grid;
}

Cell* Playfield::getCell(Point p) {
    return grid[p.y][p.x];
}

void Playfield::setCell(Point pos, Cell *cell)
{
    if (pos.x >= 0 && pos.x < width && pos.y >= 0 && pos.y < height)
        grid[pos.y][pos.x] = cell;
}

void Playfield::display() {
    for (int i = 0; i < height; i++) {
        cout<<'[';
        for (int j = 0; j < width; j++)
            cout << grid[i][j]->getColor()[0];
        cout << "]\n";
    }
    for(int i=0; i<width; i++)
        cout<<'-';
}
