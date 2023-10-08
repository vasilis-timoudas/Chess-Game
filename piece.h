//
// Created by Administrator on 16/7/2019.
//

#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H



class PIECE
{
protected:
    bool color;  // true = άσπρα , false = μαύρα
    char type;  // τύπος πχ. για Pawn με color=true type = 'P'
    int y, x;  // συνεταγμένες στο ταμπλό

public:
    PIECE(bool c, int posY, int posX);
    ~PIECE();

    void setColor(bool c);
    void setType(char t);
    void setY(int posY);
    void setX(int posX);

    bool getColor();
    char getType();
    int getY();
    int getX();

    // κάθε κομμάτι έχει διαφορετικό checkMove
    virtual int checkMove(int fromY, int fromX, int toY, int toX) = 0;
};


#endif //CHESS_PIECE_H
