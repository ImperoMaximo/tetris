#include "tetromino_Z.h"


Tetromino_Z::Tetromino_Z() {
    state = 0;
    abs_pos = 0;
    for(int i =0;i<4;i++)
        pos_register[i] = new Point[4];

    // définir les coordonnées des cases pour chaque état = rotation
    // on part de langle en haut à gauche pour noter les coordonnées
    pos_register[0][0] = {0,0};
    pos_register[0][1] = {1,0};
    pos_register[0][2] = {1,1};
    pos_register[0][3] = {2,1};

    pos_register[1][0] = {0,0};
    pos_register[1][1] = {1,0};
    pos_register[1][2] = {1,1};
    pos_register[1][3] = {2,1};
    
    pos_register[2][0] = {0,0};
    pos_register[2][1] = {1,0};
    pos_register[2][2] = {1,1};
    pos_register[2][3] = {2,1};
    
    pos_register[3][0] = {0,0};
    pos_register[3][1] = {1,0};
    pos_register[3][2] = {1,1};
    pos_register[3][3] = {2,1};
}