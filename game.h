//
// Created by Administrator on 16/7/2019.
//

#ifndef CHESS_GAME_H
#define CHESS_GAME_H

#include "iostream"
#include "vector"
#include "fstream"

#include "board.h"
#include "string"
#include "string.h"


using namespace std;

class Game
{
private:
    int whiteKingPos[2], blackKingPos[2];
    string playerColor;  // για 'Άσπρα' και 'Μαύρα'

    vector<string> moves;  // για καταγραφή όλων των κινήσεων στο παιχνίδι

    struct Data  // εδώ αποθηκεύονται οι τιμές από το αρχείο (είναι 4 byte το καθένα)
    {
        char y, x, type, moved;
    };

    Data *data = new Data[64];

public:
    void startNewGame();  // ξεκινάει το παιχνίδι!

    void selectPiece(BOARD board, int id, int from[]);  // για να διαλέξουμε κομμάτι
    void movePiece(BOARD board, int id, int from[], int to[]);  // για να δώσουμε θέση κίνησης του κομματιού

    int translateY(char posY);  // "μεταφραστής" πχ. δίνει ο χρήστης 'a' και επιστρέφει 0
    int translateX(char posX);  // "μεταφραστής" πχ. δίνει ο χρήστης '5' και επιστρέφει 4
    bool isWrongCoordinates(int posY, int posX);  // έλεγχος ορθότητας συντεταγμένων

    void addMove(string m);  // προσθέτουμε κίνηση
    void showAllMoves();  // εμφάνιση όλων των κινήσεων
    void repeatGame();  // για να επαναλάβει την παρτίδα

    bool isFriendlyPieceThere(BOARD board, int fromY, int fromX, int toY, int toX);  // αν υπάρχει φιλικό piece true
    bool isEnemyPieceThere(BOARD board, int fromY, int fromX, int toY, int toX);  // αν υπάρχει αντίπαλο piece true
    bool checkDistance(BOARD board, int fromY, int fromX, int toY, int toX);  // για έλεγχω σωστής κίνησης piece

    void save(ofstream &of);  // αποθήκευση σε binary αρχείο
    void writeBinaryFile(string strFile);  // γράψιμο σε binary αρχείο
    void readBinaryFile(string strFile);  // διάβασμα από binary αρχείο

    void setData(BOARD board);  // αρχικοποιούμε το struct Data
    void printData();  // εμφάνιση των περιεχομένων του struct Data

    int translateFromDataY(char posY);  // 'μεταφραστής' για το ύψος από το struct Data
    int translateFromDataX(char posX);  // 'μεταφραστής' για το πλάτος από το struct Data
    void printBoardFromData();  // εμφάνιση ταμπλό απο το struct Data αφού πρώτα έχει περαστεί από αρχείο

    void findWhiteKingPos(BOARD board);  // εύρεση άσπρου βασιλιά
    void findBlackKingPos(BOARD board);  // εύρεση μαύρου βασιλιά

    int getWhiteKingPosY();  //  return ύψος άσπρου βασιλιά
    int getWhiteKingPosX();  //  return πλάτος άσπρου βασιλιά
    int getBlackKingPosY();  //  return ύψος μαύρου βασιλιά
    int getBlackKingPosX();  //  return πλάτος μαύρου βασιλιά

    bool isThreated(int playerId, BOARD board, int posY, int posX);  // αν απειλείται ο βασιλιάς true (δεν υλοποιήθηκε)
    bool isGameOver(int playerId, BOARD board);  // αν τερματίζει το παιχνίδι (δεν υλοποιήθηκε πλήρως)
};


#endif //CHESS_GAME_H
