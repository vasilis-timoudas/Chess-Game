//
// Created by Administrator on 16/7/2019.
//

#ifndef CHESS_KING_H
#define CHESS_KING_H


#include "piece.h"

class King : public PIECE
{
public:
    King(bool c, int posY, int posX);

    int checkMove(int fromY, int fromX, int toY, int toX);
};


#endif //CHESS_KING_H
