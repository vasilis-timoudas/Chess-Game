//
// Created by Administrator on 16/7/2019.
//

#include "board.h"

void BOARD::initBoard() {
    // Αρχικοποίηση και δημιουργία Μαύρων κομματιών στο ταμπλό
    for(int i=0; i<8; i++)
        board[1][i] = new Pawn(false, 1, i);

    board[0][0] = new Rook(false, 0, 0);
    board[0][7] = new Rook(false, 0, 7);

    board[0][1] = new Knight(false, 0, 1);
    board[0][6] = new Knight(false, 0, 6);

    board[0][2] = new Bishop(false, 0, 2);
    board[0][5] = new Bishop(false, 0, 5);

    board[0][3] = new King(false, 0, 3);
    board[0][4] = new Queen(false, 0, 4);

    // Αρχικοποίηση και δημιουργία Άσπρων κομματιών στο ταμπλό
    for(int i=0; i<8; i++)
        board[6][i] = new Pawn(true, 6, i);

    board[7][0] = new Rook(true, 7, 0);
    board[7][7] = new Rook(true, 7, 7);

    board[7][1] = new Knight(true, 7, 1);
    board[7][6] = new Knight(true, 7, 6);

    board[7][2] = new Bishop(true, 7, 2);
    board[7][5] = new Bishop(true, 7, 5);

    board[7][3] = new King(true, 7, 3);
    board[7][4] = new Queen(true, 7, 4);

    // Αρχικοποίηση και δημιουργία κενών στο ταμπλό
    for(int i=2; i<6; i++)
        for(int j=0; j<8; j++)
            board[i][j] = new Empty(false, i, j);
}


void BOARD::printBoard() {
    char row = '8', column = 'a';

    cout << endl << "   ";

    for(int i=0; i<8; i++)
        cout << "       " << column++;

    cout << endl;

    for(int i=0; i<=8; i++)
    {
        cout << "   ";

        for(int j=0; j<9; j++) cout << "   |    ";

        cout << endl << "   ";

        for(int j=0; j<71; j++)
            cout << "-";

        cout << endl << "   ";

        for(int j=0; j<9; j++)
            cout << "   |    ";

        cout << endl;

        if(i != 8)
        {
            cout << row-- << "  ";

            for(int j=0; j<8; j++)
                cout << "   |   " << getPieceType(i, j);

            cout << "   |    " << endl;
        }
    }

    cout << "    " << endl << endl;
}

void BOARD::setPieceAtBoard(PIECE *piece, int posY, int posX) {
    board[posY][posX] = piece;

    piece->setY(posY);
    piece->setX(posX);
}

char BOARD::getPieceType(int posY, int posX) {
    return board[posY][posX]->getType();
}

PIECE *BOARD::getPieceAtBoard(int posY, int posX) {
    return board[posY][posX];
}

bool BOARD::isPickedRight(int playerId, int posY, int posX) {
    char type = board[posY][posX]->getType();

    if((playerId == 1) && (type == 'P' || type == 'R' || type == 'N' || type == 'B' || type == 'Q' || type == 'K'))
        return true;
    else if((playerId == 2) && (type == 'p' || type == 'r' || type == 'n' || type == 'b' || type == 'q' || type == 'k'))
        return true;

    return false;
}

void BOARD::doMove(int fromY, int fromX, int toY, int toX) {
    PIECE *temp[1][1];

    if(this->board[toY][toX]->getType() == ' ')  // κάνει κίνηση σε άδεια θέση
    {
        // swap
        temp[0][0] = board[fromY][fromX];
        board[fromY][fromX] = board[toY][toX];
        board[toY][toX] = temp[0][0];
    }
    else  // δεν είναι άδεια η θέση (υπάρχει αντίπαλο πιόνι)
    {
        // swap
        temp[0][0] = board[fromY][fromX];
        board[fromY][fromX] = board[toY][toX];
        board[toY][toX] = temp[0][0];

        getPieceAtBoard(fromY, fromX)->~PIECE();  // διαγράφεται από την μνήμη εφόσον 'πεθαίνει' στο παιχνίδι

        board[fromY][fromX] = new Empty(true, fromY, fromX);  // στην θέση αυτού δημιουργείται κενό
    }
}

bool BOARD::isNotEmpty(int posY, int posX) {
    if(board[posY][posX]->getType() != ' ')
        return true;

    return false;
}

bool BOARD::isFrontEmpty(int fromY, int fromX, int toY) {
    int distanceToCheck = fromY - toY - 1, check = 0;

    for(int i=fromY-1; i>toY; i--)
        if(board[i][fromX]->getType() == ' ')
            check++;

     if(check == distanceToCheck)
         return true;

    return false;
}

bool BOARD::isBackEmpty(int fromY, int fromX, int toY) {
    int distanceToCheck = toY - fromY - 1, check = 0;

    for(int i=fromY+1; i<toY; i++)
        if(board[i][fromX]->getType() == ' ')
            check++;

    if(check == distanceToCheck)
        return true;

    return false;
}

bool BOARD::isRightEmpty(int fromY, int fromX, int toX) {
    int distanceToCheck = toX - fromX - 1, check = 0;

    for(int i=fromX+1; i<toX; i++)
        if(board[fromY][i]->getType() == ' ')
            check++;

    if(check == distanceToCheck)
        return true;

    return false;
}

bool BOARD::isLeftEmpty(int fromY, int fromX, int toX) {
    int distanceToCheck = fromX - toX - 1, check = 0;

    for(int i=fromX-1; i>toX; i--)
        if(board[fromY][i]->getType() == ' ')
            check++;

    if(check == distanceToCheck)
        return true;

    return false;
}

bool BOARD::isDiagonalUpRightEmpty(int fromY, int fromX, int toY, int toX) {
    int distanceY = fromY - toY - 1, distanceX = fromX - toX + 1;

    int i = fromY - 1, j = fromX + 1, check = 0;

    while(i>toY && j<toX)
    {
       if(board[i][j]->getType() == ' ')
           check++;

       i--;
       j++;
    }

    if(check == distanceY && check == abs(distanceX))
        return true;

    return false;
}

bool BOARD::isDiagonalUpLeftEmpty(int fromY, int fromX, int toY, int toX) {
    int distanceY = fromY - toY - 1, distanceX = fromX - toX - 1;

    int i = fromY - 1, j = fromX - 1, check = 0;

    while(i>toY && j>toX)
    {
        cout << i << " " << j << endl;

        if(board[i][j]->getType() == ' ')
            check++;

        i--;
        j--;
    }

    if(check == distanceY && check == distanceX)
        return true;

    return false;
}

bool BOARD::isDiagonalDownRightEmpty(int fromY, int fromX, int toY, int toX) {
    int distanceY = fromY - toY + 1, distanceX = fromX - toX + 1;

    int i = fromY + 1, j = fromX + 1, check = 0;

    while(i<toY && j<toX)
    {
        cout << i << " " << j << endl;

        if(board[i][j]->getType() == ' ')
            check++;

        i++;
        j++;
    }

    if(check == abs(distanceY) && check == abs(distanceX))
        return true;

    return false;
}

bool BOARD::isDiagonalDownLeftEmpty(int fromY, int fromX, int toY, int toX) {
    int distanceY = fromY - toY + 1, distanceX = fromX - toX - 1;

    int i = fromY + 1, j = fromX - 1, check = 0;

    while(i<toY && j>toX)
    {
        if(board[i][j]->getType() == ' ')
            check++;

        i++;
        j--;
    }

    if(check == abs(distanceY) && check == distanceX)
        return true;

    return false;
}

char BOARD::translateYFile(int posY) {
    if(posY == 0) return '8';
    else if(posY == 1) return '7';
    else if(posY == 2) return '6';
    else if(posY == 3) return '5';
    else if(posY == 4) return '4';
    else if(posY == 5) return '3';
    else if(posY == 6) return '2';
    else if(posY == 7) return '1';

    return '0';  // error return
}

char BOARD::translateXFile(int posX) {
    if(posX == 0) return '1';
    else if(posX == 1) return '2';
    else if(posX == 2) return '3';
    else if(posX == 3) return '4';
    else if(posX == 4) return '5';
    else if(posX == 5) return '6';
    else if(posX == 6) return '7';
    else if(posX == 7) return '8';

    return '0';  // error return
}

void BOARD::initPieceHasMoved() {
    for(int i=0; i<BOARD_SIZE; i++)
        for(int j=0; j<BOARD_SIZE; j++)
            piecesHasMoved[i][j] = 0;
}

void BOARD::setPieceHasMoved(int posY, int posX, int value) {
    piecesHasMoved[posY][posX] = value;
}

int BOARD::getPieceHasMoved(int posY, int posX) {
    return piecesHasMoved[posY][posX];
}

void BOARD::getBoardPieceHasMoved() {
    for(int i=0; i<BOARD_SIZE; i++)
    {
        for(int j=0; j<BOARD_SIZE; j++)
            cout << piecesHasMoved[i][j] << " ";
        cout << endl;
    }
}

char BOARD::translateMovedFile(int i, int j) {
    if(piecesHasMoved[i][j] == 1)
        return '1';

    return '0';
}

bool BOARD::isBoxEmpty(int posY, int posX) {
    if(isFrontEmpty(posY, posX, posY - 1) || isFrontEmpty(posY, posX, posY + 1) ||
        isLeftEmpty(posY, posX, posX + 1) || isRightEmpty(posY, posX, posX - 1))
        return true;
// $
    return false;
}















