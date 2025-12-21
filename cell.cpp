#include "cell.h"

Cell::Cell(Point pos, bool t, string colour) : pos(pos), taken(t), color(colour) {}

bool Cell::isTaken() const { return taken; }

string Cell::getColor() const { return color; }

void Cell::colonize(string colour) {
    taken = true;
    color = colour;
}

void Cell::clear() {
    taken = false;
    color = "grey";
}   //pas sur qu'on ait besoin de clear si on fait juste "descendre" les autres cellules ou non
