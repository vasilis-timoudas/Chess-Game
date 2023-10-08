//
// Created by Administrator on 16/7/2019.
//

#include "empty.h"

Empty::Empty(bool c, int posY, int posX) : PIECE(c, posY, posX) {
    type = ' ';

    // δεν παίζει ρόλο τι τιμή θα έχει το color
}

int Empty::checkMove(int fromY, int fromX, int toY, int to) {
    return 0;
}

