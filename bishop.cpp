//
// Created by Administrator on 16/7/2019.
//

#include "bishop.h"

Bishop::Bishop(bool c, int posY, int posX) : PIECE(c, posY, posX) {
    type = (c)? 'B' : 'b';
}

int Bishop::checkMove(int fromY, int fromX, int toY, int toX) {
    if(toY + 1 == fromY && toX - 1 == fromX)  // κίνηση 1 θέση πάνω δεξιά
        return 1;
    if(toY + 1 ==  fromY && toX + 1 == fromX)  // κίνηση 1 θέση πάνω αριστερά
        return 2;
    if(toY - 1 ==  fromY && toX - 1 == fromX)  // κίνηση 1 θέση κάτω δεξιά
        return 3;
    if(toY - 1 == fromY && toX + 1 == fromX)   // κίνηση 1 θέση κάτω αριστερά
        return 4;

    int distanceY = fromY - toY, distanceX = fromX - toX;

    if(distanceY > distanceX)  // κίνηση πάνω δεξιά distanceY θέσεις
        return 5;
    if(distanceY > 0 && distanceX > 0)  // κίνηση πάνω αριστερά distanceX θέσεις
        return 6;
    if(distanceY < 0 && distanceX < 0)  // κίνηση κάτω δεξιά distanceY θέσεις
        return 7;
    if(distanceY < distanceX)  // κίνηση κάτω αριστερά distanceY θέσεις
        return 8;

    return 0;
}
