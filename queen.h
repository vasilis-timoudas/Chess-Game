//
// Created by Administrator on 16/7/2019.
//

#ifndef CHESS_QUEEN_H
#define CHESS_QUEEN_H


#include "piece.h"

class Queen : public PIECE
{
public:
    Queen(bool c, int posY, int posX);

    int checkMove(int fromY, int fromX, int toY, int toX);
};


#endif //CHESS_QUEEN_H
