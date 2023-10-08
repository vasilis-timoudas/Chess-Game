//
// Created by Administrator on 16/7/2019.
//

#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H


#include "piece.h"

class Pawn : public PIECE
{
private:
    bool hasFirstMove = true;  // (δεν υλοποιήθηκε)

public:
    Pawn(bool c, int posY, int posX);

    int checkMove(int fromY, int fromX, int toY, int toX);

};


#endif //CHESS_PAWN_H
