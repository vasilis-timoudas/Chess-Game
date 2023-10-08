//
// Created by Administrator on 16/7/2019.
//

#include "pawn.h"

Pawn::Pawn(bool c, int posY, int posX) : PIECE(c, posY, posX){
    type = (c)? 'P' : 'p';

    //hasFirstMove = true;
}

int Pawn::checkMove(int fromY, int fromX, int toY, int toX) {
    if(this->color)  // άσπρο πιόνι
    {
        if(toX == fromX && toY + 1 == fromY)  // 1 θέση πάνω
            return 1;
        if(toX - 1 == fromX && toY + 1 == fromY)   // επίθεση 1 θέση πάνω δεξιά
            return 2;
        if(toX + 1 == fromX && toY + 1 == fromY)  // επίθεση 1 θέση πάνω αριστερά
            return 3;

       /* if((this->hasFirstMove))
        {
            this->hasFirstMove = false;
            if(toX == fromX && toY + 2 == fromY)
                return 4;
        }  */
    }
    else  // μαύρο πιόνι
    {
        if(toX == fromX && toY - 1 == fromY)  // 1 θέση κάτω
            return 5;
        if(toX + 1 == fromX && toY - 1 == fromY)  // επίθεση 1 θέση κάτω δεξιά
            return 6;
        if(toX - 1 == fromX && toY - 1 == fromY)  // επίθεση 1 θέση κάτω αριστερά
            return 7;

        /* if((this->hasFirstMove))
      {
          this->hasFirstMove = false;
          if(toX == fromX && toY - 2 == fromY)
              return 8;
      }  */

    }

    return 0;
}

