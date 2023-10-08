//
// Created by Administrator on 16/7/2019.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include "iostream"
#include "string.h"
#include "fstream"

#include "piece.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include "empty.h"


using namespace std;

class BOARD
{
private:
    static const int BOARD_SIZE = 8;

    PIECE *board[BOARD_SIZE][BOARD_SIZE];

    int piecesHasMoved[BOARD_SIZE][BOARD_SIZE];  // 1 όποτε κινήτε κάθε πιόνι αλλιώς 0

public:
    void initBoard();  // αρχικοποίηση ταμπλό
    void printBoard();  // εμφάνιση ταμπλό

    void setPieceAtBoard(PIECE *piece, int posY, int posX);
    PIECE *getPieceAtBoard(int posY, int posX);  // return το PIECE που βρίσκετε στις θέσεις posY posX στο ταμπλό

    void doMove(int fromY, int fromX, int toY, int toX);  // κίνηση

    bool isPickedRight(int playerId, int posY, int posX);  // ο παίχτης 1(Άσπρα) μπορεί να διαλέξει μόνο κεφαλαία
    bool isNotEmpty(int posY, int posX);  // true αν δεν είναι άδεια η θέση αλλιώς false
    bool isBoxEmpty(int posY, int posX);  // αν είναι ένα από τα γύρο τετράγωνα κενά τότε return true

    bool isFrontEmpty(int fromY, int fromX, int toY);  // true αν είναι η πάνω θέσεις κενές
    bool isBackEmpty(int fromY, int fromX, int toY);  // true αν είναι η κάτω θέσεις κενές
    bool isRightEmpty(int fromY, int fromX, int toX);  // true αν είναι η δεξιά θέσεις κενές
    bool isLeftEmpty(int fromY, int fromX, int toX);  // true αν είναι η αριστερά θέσεις κενές
    bool isDiagonalUpRightEmpty(int fromY, int fromX, int toY, int toX);  // true αν οι θέσεις της διαγώνιου πάνω δεξιά είναι κενές
    bool isDiagonalUpLeftEmpty(int fromY, int fromX, int toY, int toX);  // true αν οι θέσεις της διαγώνιου πάνω αριστερά είναι κενές
    bool isDiagonalDownRightEmpty(int fromY, int fromX, int toY, int toX);  // true αν οι θέσεις της διαγώνιου πάνω δεξιά είναι κενές
    bool isDiagonalDownLeftEmpty(int fromY, int fromX, int toY, int toX);  // true αν οι θέσεις της διαγώνιου κάτω αριστερά είναι κενές

    char translateYFile(int posY);  // 'μεταφραστής' μεταφράζει το ύψος του αρχείου
    char translateXFile(int posX);  // 'μεταφραστής' μεταφράζει το πλάτος του αρχείου
    char getPieceType(int posY, int posX);  // return το PIECE->type ου βρίσκετε στις θέσεις posY posX στο ταμπλό
    char translateMovedFile(int i, int j);

    void initPieceHasMoved();  // αρχικοποιήτε με 0
    void setPieceHasMoved(int posY, int posX, int value);  // όποτε κινήτε ένα πιόνι η θέση του γίνεται 1
    int getPieceHasMoved(int posY, int posX);
    void getBoardPieceHasMoved();  // εμφάνιση όλου του 8x8 board για να δούμε ποιες θέσεις κομματιών έχουν κινηθεί
};


#endif //CHESS_BOARD_H
