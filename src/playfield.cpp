#include "playfield.hpp"

Playfield::Playfield(int w, int h) : width(w), height(h) {
    grid = new Cell**[height];
    for (int i = 0; i < height; i++) {
        grid[i] = new Cell*[width];
        for (int j = 0; j < width; j++)
            grid[i][j] = new Cell(Point{j, i});
    }
}

Playfield::~Playfield() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++)
            delete grid[i][j];
        delete[] grid[i];
    }
    delete[] grid;
}

Cell* Playfield::getCell(Point p) {
    return grid[p.y][p.x];
}

void Playfield::setCell(Point pos, Cell *cell) {
    if (pos.x >= 0 && pos.x < width && pos.y >= 0 && pos.y < height)
        grid[pos.y][pos.x] = cell;
}

void Playfield::eraseFullRow(int row_y) {
    for (int j = 0; j < width; j++)
        delete grid[row_y][j];
    delete[] grid[row_y];       //libérer la ligne

    for (int i = row_y; i > 0; i--)
        grid[i] = grid[i-1];    //faire glisser les lignes

    grid[0] = new Cell*[width]; //ajouter une ligne vide
    for (int j = 0; j < width; j++)
        grid[0][j] = new Cell(Point{j, 0});
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
