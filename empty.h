//
// Created by Administrator on 16/7/2019.
//

#ifndef CHESS_EMPTY_H
#define CHESS_EMPTY_H


#include "piece.h"

class Empty : public PIECE
{
public:
    Empty(bool c, int posY, int posX);

    int checkMove(int fromY, int fromX, int toY, int toX);
};


#endif //CHESS_EMPTY_H
