//
// Created by Administrator on 16/7/2019.
//

#ifndef CHESS_KNIGHT_H
#define CHESS_KNIGHT_H


#include "piece.h"
#include "board.h"

class Knight : public PIECE
{
public:
    Knight(bool c, int posY, int posX);

    int checkMove(int fromY, int fromX, int toY, int toX);
};


#endif //CHESS_KNIGHT_H
