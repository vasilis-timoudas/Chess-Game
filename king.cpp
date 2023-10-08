//
// Created by Administrator on 16/7/2019.
//

#include "king.h"

King::King(bool c, int posY, int posX) : PIECE(c, posY, posX) {
    type = (c)? 'K' : 'k';
}

int King::checkMove(int fromY, int fromX, int toY, int toX) {
    if((toX == fromX) && (toY + 1 == fromY))  // 1 θέση πάνω
        return 1;
    if((toX - 1 == fromX) && (toY + 1 == fromY))  // 1 θέση πάνω δεξιά
        return 2;
    if((toX + 1 == fromX) && (toY + 1 == fromY))  //  1 θέση πάνω αριστερά
        return 3;
    if((toY == fromY) && (toX == fromX + 1))  // 1 θέση δεξιά
        return 4;
    if((toY == fromY) && (toX == fromX - 1))  // 1 θέση αριστερά
        return 5;
    if((toX == fromX) && (toY - 1 == fromY))  // 1 θέση κάτω
        return 6;
    if((toX + 1 == fromX) && (toY - 1 == fromY))  // 1 θέση κάτω δεξιά
        return 7;
    if((toX - 1 == fromX) && (toY - 1 == fromY))  // 1 θέση κάτω αριστερά
        return 8;

    return 0;
}
