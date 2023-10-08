//
// Created by Administrator on 16/7/2019.
//

#include "queen.h"

Queen::Queen(bool c, int posY, int posX) : PIECE(c, posY, posX) {
    type = (c)? 'Q' : 'q';
}

int Queen::checkMove(int fromY, int fromX, int toY, int toX) {
    int distanceY = fromY - toY, distanceX = fromX - toX;

    if(toX == fromX)  // πάνω ή κάτω
    {
        if(distanceY == 1)  // κίνηση πάνω 1 θέση
            return 1;
        if(distanceY == -1)  // κίνηση κάτω 1 θέση
            return 2;
        if(distanceY > 1)  // κίνηση πάνω distanceY θέσεις
            return 9;
        if(distanceY < 1)  // κίνηση κάτω distanceY θέσεις
            return 10;
    }
    if(toY == fromY)  // δεξιά ή αριστερά
    {
        if(distanceX == 1)  // κίνηση αριστερά 1 θέση
            return 3;
        if(distanceX == -1)  // κίνηση δεξιά 1 θέση
            return 4;
        if(distanceX > 1)  // κίνηση αριστερά distanceX θέσεις
            return 11;
        if(distanceX < 1)  // κίνηση δεξιά distanceX θέσεις
            return 12;
    }

    if(toY + 1 == fromY && toX - 1 == fromX)  // κίνηση 1 θέση πάνω δεξιά
        return 5;
    if(toY + 1 ==  fromY && toX + 1 == fromX)  // κίνηση 1 θέση πάνω αριστερά
        return 6;
    if(toY - 1 ==  fromY && toX - 1 == fromX)  // κίνηση 1 θέση κάτω δεξιά
        return 7;
    if(toY - 1 == fromY && toX + 1 == fromX)   // κίνηση 1 θέση κάτω αριστερά
        return 8;

    if(distanceY > distanceX)  // κίνηση πάνω δεξιά distanceY θέσεις
        return 13;
    if(distanceY > 0 && distanceX > 0)  // κίνηση πάνω αριστερά distanceX θέσεις
        return 14;
    if(distanceY < 0 && distanceX < 0)  // κίνηση κάτω δεξιά distanceY θέσεις
        return 15;
    if(distanceY < distanceX)  // κίνηση κάτω αριστερά distanceY θέσεις
        return  16;

    return 0;
}
