//
// Created by Administrator on 16/7/2019.
//

#ifndef CHESS_BISHOP_H
#define CHESS_BISHOP_H


#include "piece.h"
#include "board.h"

class Bishop : public PIECE
{
public:
    Bishop(bool c, int posY, int posX);

    int checkMove(int fromY, int fromX, int toY, int toX);
};


#endif //CHESS_BISHOP_H
