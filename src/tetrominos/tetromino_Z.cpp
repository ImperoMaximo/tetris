#include "tetromino_Z.hpp"


Tetromino_Z::Tetromino_Z() : Tetromino(0, "red", Point{}) {
    // définir les coordonnées des cases pour chaque état = rotation
    // on part de langle en haut à gauche pour noter les coordonnées
    // dans un carré de 3x3 cases.
    shapes[0][0] = {0,0};
    shapes[0][1] = {1,0};
    shapes[0][2] = {1,1};
    shapes[0][3] = {2,1};

    shapes[1][0] = {0,0};
    shapes[1][1] = {1,0};
    shapes[1][2] = {1,1};
    shapes[1][3] = {2,1};
    
    shapes[2][0] = {0,0};
    shapes[2][1] = {1,0};
    shapes[2][2] = {1,1};
    shapes[2][3] = {2,1};
    
    shapes[3][0] = {0,0};
    shapes[3][1] = {1,0};
    shapes[3][2] = {1,1};
    shapes[3][3] = {2,1};
}