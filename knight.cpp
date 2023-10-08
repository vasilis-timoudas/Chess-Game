//
// Created by Administrator on 16/7/2019.
//

#include "knight.h"

Knight::Knight(bool c, int posY, int posX) : PIECE(c, posY, posX) {
    type = (c)? 'N' : 'n';
}

int Knight::checkMove(int fromY, int fromX, int toY, int toX) {
    if(toY + 1 == fromY && toX - 2 == fromX)  // 1 θέση πάνω και 2 θέσεις δεξιά
        return 1;
    if(toY + 1 == fromY && toX + 2 == fromX)  // 1 θέση πάνω και 2 θέσεις αριστερά
        return 2;
    if(toY - 1 == fromY && toX + 2 == fromX)  // 1 θέση κάτω και 2 θέσεις δεξιά
        return 3;
    if(toY - 1 == fromY && toX - 2 == fromX)  // 1 θέση κάτω και 2 θέσεις αριστερά
        return 4;

    if(toY + 2 == fromY && toX - 1 == fromX)  // 2 θέσεις πάνω και 1 θέση δεξιά
        return 5;
    if(toY + 2 == fromY && toX + 1 == fromX)  // 2 θέσεις πάνω 1 θέση αριστερά
        return 6;
    if(toY - 2 == fromY && toX - 1 == fromX)  // 2 θέσεις κάτω 1 θέση δεξιά
        return 7;
    if(toY - 2 == fromY && toX + 1 == fromX)  // 2 θέσεις κάτω 1 θέση αριστερά
        return 8;

    return 0;
}
