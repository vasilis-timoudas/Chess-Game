//
// Created by Administrator on 16/7/2019.
//

#include "piece.h"

PIECE::PIECE(bool c, int posY, int posX){
    color = c;
    y = posY;
    x = posX;
}

PIECE::~PIECE() { }

void PIECE::setColor(bool c) {
    color = c;
}

void PIECE::setType(char t) {
    type = t;
}

void PIECE::setY(int posY) {
    y = posY;
}

void PIECE::setX(int posX) {
    x = posX;
}

bool PIECE::getColor() {
    return color;
}

char PIECE::getType() {
    return type;
}

int PIECE::getY() {
    return y;
}

int PIECE::getX() {
    return x;
}


