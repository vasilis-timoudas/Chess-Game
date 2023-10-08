//
// Created by Administrator on 16/7/2019.
//

#ifndef CHESS_ROOK_H
#define CHESS_ROOK_H


#include "piece.h"

class Rook : public PIECE
{
public:
    Rook(bool c, int posY, int posX);

    int checkMove(int fromY, int fromX, int toY, int toX);
};


#endif //CHESS_ROOK_H
