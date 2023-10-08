//
// Created by Administrator on 16/7/2019.
//

#include "rook.h"

Rook::Rook(bool c, int posY, int posX) : PIECE(c, posY, posX) {
    type = (c)? 'R' : 'r';
}


int Rook::checkMove(int fromY, int fromX, int toY, int toX) {
   int distanceY = fromY - toY, distanceX = fromX - toX;

   if(toX == fromX)  // πάνω ή κάτω
   {
        if(distanceY == 1)  // κίνηση πάνω 1 θέση
            return 1;
        if(distanceY == -1)  // κίνηση κάτω 1 θέση
            return 2;
        if(distanceY > 1)  // κίνηση πάνω distanceY θέσεις
            return 5;
        if(distanceY < 1)  // κίνηση κάτω distanceY θέσεις
            return 6;
   }
   if(toY == fromY)  // δεξιά ή αριστερά
   {
       if(distanceX == 1)  // κίνηση αριστερά 1 θέση
           return 3;
       if(distanceX == -1)  // κίνηση δεξιά 1 θέση
           return 4;
       if(distanceX > 1)  // κίνηση αριστερά distanceX θέσεις
           return 7;
       if(distanceX < 1)  // κίνηση δεξιά distanceX θέσεις
           return 8;
   }

    return 0;
}

