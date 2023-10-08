//
// Created by Administrator on 16/7/2019.
//


#include "game.h"

void Game::startNewGame() {
    BOARD board;
    int from[2], to[2];

    board.initBoard();  // αρχικοποίηση ταμπλό
    board.initPieceHasMoved();  // αρχικοποίηση το ταμπλό για τα κομμάτια αν έχουν κινηθεί

    do
    {
        // αποθήκευση τρέχουσας κατάσταση ταμπλό πριν από την κίνηση του λευκού
        setData(board);  // περνάμε τις τιμές που θέλει το binary αρχείο σε struct
        writeBinaryFile("boardState.bin");  // γράψιμο σε binary αρχείο από struct
        readBinaryFile("boardState.bin");  // διάβασμα από binary αρχείο και αποθήκευση σε struct

        printBoardFromData();  // εμφάνιση ταμπλό από το struct άφου πρώτα τα έχει διαβάσει από αρχείο!



        // παίζει παίχτης 1 (άσπρα)
        selectPiece(board, 1, from);
        movePiece(board, 1, from, to);
        board.doMove(from[1], from[0], to[1], to[0]);

        board.printBoard();  // εμφάνιση ταμπλό (δεν είναι από αρχείο)

        if(isGameOver(2, board))
            break;

        // παίζει παίχτης 2 (μαύρα)
        selectPiece(board, 2, from);
        movePiece(board, 2, from, to);
        board.doMove(from[1], from[0], to[1], to[0]);

        if(isGameOver(1, board))
            break;

    } while(true);
}



void Game::selectPiece(BOARD board, int id, int from[]) {
    char fromChar[2];

    playerColor = (id == 1)? "Άσπρα)" : "Μαύρα)";

    cout << "Παίζει ο παίχτης: " << id << "(" << playerColor << endl;

    do
    {
        cout << "Διαλέξτε κομμάτι: ";
        cin >> fromChar;

        from[1] = translateY(fromChar[1]);
        from[0] = translateX(fromChar[0]);

        if(!board.isPickedRight(id, from[1], from[0]) || !isWrongCoordinates(from[1], from[0]))
            cout << "ΛΑΘΟΣ ΘΕΣΗ!" << endl;

    } while(!board.isPickedRight(id, from[1], from[0]) || !isWrongCoordinates(from[1], from[0]));

    string m = fromChar;
    addMove(m);

    cout << "Διαλέξατε " << board.getPieceType(from[1], from[0]) << endl;


}

void Game::movePiece(BOARD board, int id, int from[], int to[]) {
    char toChar[2];

    playerColor = (id == 1)? "Άσπρα)" : "Μαύρα)";

    do
    {
        cout << "Δώστε θέση: ";
        cin >> toChar;

        to[1] = translateY(toChar[1]);
        to[0] = translateX(toChar[0]);

        if(!board.getPieceAtBoard(from[1], from[0])->checkMove(from[1], from[0], to[1], to[0]))
            cout << "ΛΑΘΟΣ ΘΕΣΗ!" << endl;

    } while(!checkDistance(board, from[1], from[0], to[1], to[0]));

    string m = toChar;
    addMove(m);
}

int Game::translateY(char posY) {
    if(posY == '8') return 0;
    else if(posY == '7') return 1;
    else if(posY == '6') return 2;
    else if(posY == '5') return 3;
    else if(posY == '4') return 4;
    else if(posY == '3') return 5;
    else if(posY == '2') return 6;
    else if(posY == '1') return 7;

    return 8;  // error return
}

int Game::translateX(char posX) {
    if(posX == 'a') return 0;
    else if(posX == 'b') return 1;
    else if(posX == 'c') return 2;
    else if(posX == 'd') return 3;
    else if(posX == 'e') return 4;
    else if(posX == 'f') return 5;
    else if(posX == 'g') return 6;
    else if(posX == 'h') return 7;

    return 8;  // error return
}

bool Game::isWrongCoordinates(int posY, int posX) {
    if((0 <= posY && posY <= 7) && (0 <= posX && posX <= 7))
        return true;

    return false;
}

void Game::addMove(string m){
    moves.push_back(m);
}

void Game::showAllMoves(){
    int size = moves.size();  // μέγεθος vector

    for(int i=0; i<size; i++)
        cout << moves.at(i) << endl;
}

void Game::repeatGame() {
    if (moves.empty()) {
        cout << endl << "Δεν έχει παιχτεί παρτίδα!" << endl << endl;
        return;
    }

    cout << endl << "Επαναλαμβάνεται η παρτίδα!" << endl << endl;

    BOARD board;
    int size = moves.size(), from[2], to[2], c = 1;
    char fromChar[2], toChar[2];

    board.initBoard();
    board.printBoard();

    for(int i=0; i<size; i+=2)
    {
       cout << c <<"ος γύρος" << endl;
       c++;

       strcpy(fromChar, moves.at(i).c_str());
       from[0] = translateY(fromChar[1]);
       from[1] = translateX(fromChar[0]);

       strcpy(toChar, moves.at(i + 1).c_str());
       to[0] = translateY(toChar[1]);
       to[1] = translateX(toChar[0]);

       board.doMove(from[0], from[1], to[0], to[1]);

       board.printBoard();
    }

    cout << "Τέλος!" << endl;
}

bool Game::isFriendlyPieceThere(BOARD board, int fromY, int fromX, int toY, int toX) {
    // δεν χρησιμοποιώ την συνάρτηση getColor() γιατί και τα Empty έχουν color οπότε μπορεί να θεωρήσει φιλικό κομμάτι το Empty!
    char ptFrom = board.getPieceType(fromY, fromX), ptTo = board.getPieceType(toY, toX);

    if(!islower(ptFrom) && !islower(ptTo))  // δεν είναι πεζά και τα 2 οπότε είναι κεφαιλαία και είναι φιλικά
        return true;
    if(islower(ptFrom) && islower(ptTo))
        return true;

    return false;
}

bool Game::isEnemyPieceThere(BOARD board, int fromY, int fromX, int toY, int toX) {
    // δεν χρησιμοποιώ την συνάρτηση getColor() γιατί και τα Empty έχουν color οπότε μπορεί να θεωρήσει φιλικό κομμάτι το Empty!
    char ptFrom = board.getPieceType(fromY, fromX), ptTo = board.getPieceType(toY, toX);

    if(!islower(ptFrom) && islower(ptTo))  // το ptFrom είναι κεφαλαίο και το ptTo είναι πεζό άρα είναι αντίπαλα
        return true;
    if(!isupper(ptFrom) && isupper(ptTo))
        return true;

    return false;
}

bool Game::checkDistance(BOARD board, int fromY, int fromX, int toY, int toX) {
    char ptFrom = board.getPieceType(fromY, fromX);
    int cMove = board.getPieceAtBoard(fromY, fromX)->checkMove(fromY, fromX, toY, toX);

    if(ptFrom == 'P')  // άσπρο πιόνι
    {
        if(cMove == 1 && !board.isNotEmpty(toY, toX))  // κίνηση 1 θέση πάνω
            return true;
        if(cMove == 2 && isEnemyPieceThere(board, fromY, fromX, toY, toX))  // επίθεση 1 θέση πάνω δεξιά
            return true;
        if(cMove == 3 && isEnemyPieceThere(board, fromY, fromX, toY, toX))  // επίθεση 1 θέση πάνω αριστερά
            return true;
        //$
    }
    else if(ptFrom == 'p')  // μαύρο πιόνι
    {
        if(cMove == 5 && !board.isNotEmpty(toY, toX))  // κίνηση 1 θέση κάτω
            return true;
        if(cMove == 6 && isEnemyPieceThere(board, fromY, fromX, toY, toX))  // επίθεση 1 θέση κάτω δεξιά
            return true;
        if(cMove == 7 && isEnemyPieceThere(board, fromY, fromX, toY, toX))  // επίθεση 1 θέση κάτω αριστερά
            return true;
        //$
    }
    else if(ptFrom == 'N' || ptFrom == 'n')
    {
        if(cMove == 1 || cMove == 2 || cMove == 3 || cMove == 4 || cMove == 5 || cMove == 6 || cMove == 7 || cMove == 8)
            if(isEnemyPieceThere(board, fromY, fromX, toY, toX) || !board.isNotEmpty(toY, toX))
                return true;
    }
    else if(ptFrom == 'K' || ptFrom == 'k')
    {
        if(cMove == 1 || cMove == 2 || cMove == 3 || cMove == 4 || cMove == 5 || cMove == 6 || cMove == 7 || cMove == 8)
            if(isEnemyPieceThere(board, fromY, fromX, toY, toX) || !board.isNotEmpty(toY, toX))
                return true;
    }
    else if(ptFrom == 'R' || ptFrom == 'r')
    {
        if(cMove == 1 || cMove == 2 || cMove == 3 || cMove == 4)
            if(isEnemyPieceThere(board, fromY, fromX, toY, toX) || !board.isNotEmpty(toY, toX))
                return true;
        if(cMove == 5)
            if((isEnemyPieceThere(board, fromY, fromX, toY, toX) || !board.isNotEmpty(toY, toX)) && board.isFrontEmpty(fromY, fromX, toY))
                return true;
        if(cMove == 6)
            if((isEnemyPieceThere(board, fromY, fromX, toY, toX) || !board.isNotEmpty(toY, toX)) && board.isBackEmpty(fromY, fromX, toY))
                return true;
        if(cMove == 7)
            if((isEnemyPieceThere(board, fromY, fromX, toY, toX) || !board.isNotEmpty(toY, toX)) && board.isLeftEmpty(fromY, fromX, toX))
                return true;
        if(cMove == 8)
            if((isEnemyPieceThere(board, fromY, fromX, toY, toX) || !board.isNotEmpty(toY, toX)) && board.isRightEmpty(fromY, fromX, toX))
                return true;
    }
    else if(ptFrom == 'B' || ptFrom == 'b')
    {
        if(cMove == 1 || cMove == 2 || cMove == 3 || cMove == 4)
            if(isEnemyPieceThere(board, fromY, fromX, toY, toX) || !board.isNotEmpty(toY, toX))
                return true;
        if(cMove == 5)
            if((isEnemyPieceThere(board, fromY, fromX, toY, toX) || !board.isNotEmpty(toY, toX)) && board.isDiagonalUpRightEmpty(fromY, fromX, toY, toX))
                return true;
        if(cMove == 6)
            if((isEnemyPieceThere(board, fromY, fromX, toY, toX) || !board.isNotEmpty(toY, toX)) && board.isDiagonalUpLeftEmpty(fromY, fromX, toY, toX))
                return true;
        if(cMove == 7)
            if((isEnemyPieceThere(board, fromY, fromX, toY, toX) || !board.isNotEmpty(toY, toX)) && board.isDiagonalDownRightEmpty(fromY, fromX, toY, toX))
                return true;
        if(cMove == 8)
            if((isEnemyPieceThere(board, fromY, fromX, toY, toX) || !board.isNotEmpty(toY, toX)) && board.isDiagonalDownLeftEmpty(fromY, fromX, toY, toX))
                return true;
    }
    else if(ptFrom == 'Q' || ptFrom == 'q')
    {
        if(cMove == 1 || cMove == 2 || cMove == 3 || cMove == 4 || cMove == 5 || cMove == 6 || cMove == 7 || cMove == 8)
            if(isEnemyPieceThere(board, fromY, fromX, toY, toX) || !board.isNotEmpty(toY, toX))
                return true;
        if(cMove == 9)
            if((isEnemyPieceThere(board, fromY, fromX, toY, toX) || !board.isNotEmpty(toY, toX)) && board.isFrontEmpty(fromY, fromX, toY))
                return true;
        if(cMove == 10)
            if((isEnemyPieceThere(board, fromY, fromX, toY, toX) || !board.isNotEmpty(toY, toX)) && board.isBackEmpty(fromY, fromX, toY))
                return true;
        if(cMove == 11)
            if((isEnemyPieceThere(board, fromY, fromX, toY, toX) || !board.isNotEmpty(toY, toX)) && board.isLeftEmpty(fromY, fromX, toX))
                return true;
        if(cMove == 12)
            if((isEnemyPieceThere(board, fromY, fromX, toY, toX) || !board.isNotEmpty(toY, toX)) && board.isRightEmpty(fromY, fromX, toX))
                return true;
        if(cMove == 13)
            if((isEnemyPieceThere(board, fromY, fromX, toY, toX) || !board.isNotEmpty(toY, toX)) && board.isDiagonalUpRightEmpty(fromY, fromX, toY, toX))
                return true;
        if(cMove == 14)
            if((isEnemyPieceThere(board, fromY, fromX, toY, toX) || !board.isNotEmpty(toY, toX)) && board.isDiagonalUpLeftEmpty(fromY, fromX, toY, toX))
                return true;
        if(cMove == 15)
            if((isEnemyPieceThere(board, fromY, fromX, toY, toX) || !board.isNotEmpty(toY, toX)) && board.isDiagonalDownRightEmpty(fromY, fromX, toY, toX))
                return true;
        if(cMove == 16)
            if((isEnemyPieceThere(board, fromY, fromX, toY, toX) || !board.isNotEmpty(toY, toX)) && board.isDiagonalDownLeftEmpty(fromY, fromX, toY, toX))
                return true;
    }

    return false;
}

void Game::save(ofstream &of) {
    int c = 0;

    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            of.write((char *) &data[c].y, sizeof(data[c].y));
            of.write((char *) &data[c].x, sizeof(data[c].x));
            of.write((char *) &data[c].type, sizeof(data[c].type));
            of.write((char *) &data[c].moved, sizeof(data[c].moved));  // endl

            c++;
        }
    }
}

void Game::writeBinaryFile(string strFile) {
    ofstream fs;

    fs.open(strFile, ios::out | ios::binary | ios::trunc);

    if(!fs.is_open())
        return;
    else
        this->save(fs);

    fs.close();
}

void Game::readBinaryFile(string strFile) {
    int c = 0;

    ifstream binaryFile;

    binaryFile.open(strFile, ios::in | ios::binary);

    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            binaryFile.read(reinterpret_cast<char *> (&data[c].y), sizeof(data[c].y));
            binaryFile.read(reinterpret_cast<char *> (&data[c].x), sizeof(data[c].x));
            binaryFile.read(reinterpret_cast<char *> (&data[c].type), sizeof(data[c].type));
            binaryFile.read(reinterpret_cast<char *> (&data[c].moved), sizeof(data[c].moved));

            c++;
        }
    }

    // αν θέλουμε να τα εμφανίσουμε
    /*c = 0;

    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            cout << data[c].y << data[c].x << data[c].type << data[c].moved << "\t";

            c++;
        }
        cout << endl;
    } */
}

void Game::setData(BOARD board) {
    int c = 0;

    for(int i=0; i<8; i++)
        for(int j=0; j<8; j++)
        {
            data[c].y = board.translateYFile(i);
            data[c].x = board.translateXFile(j);
            data[c].type = board.getPieceType(i, j);
            data[c].moved = board.translateMovedFile(i, j);

            c++;
        }
}

void Game::printData() {
    int c = 0;

    for(int i=0; i<8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << data[c].y;
            cout << data[c].x;
            cout << data[c].type;
            cout << data[c].moved << " ";
            c++;
        }
        cout << endl;
    }
}

int Game::translateFromDataY(char posY) {
    if(posY == '8') return 0;
    else if(posY == '7') return 1;
    else if(posY == '6') return 2;
    else if(posY == '5') return 3;
    else if(posY == '4') return 4;
    else if(posY == '3') return 5;
    else if(posY == '2') return 6;
    else if(posY == '1') return 7;

    return 0;
}

int Game::translateFromDataX(char posX) {
    if(posX == '1') return 0;
    else if(posX == '2') return 1;
    else if(posX == '3') return 2;
    else if(posX == '4') return 3;
    else if(posX == '5') return 4;
    else if(posX == '6') return 5;
    else if(posX == '7') return 6;
    else if(posX == '8') return 7;

    return 0;
}

void Game::printBoardFromData() {
    char row = '8', column = 'a';
    int c = 0;

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
            {
                cout << "   |   " << data[c].type;
                c++;
            }


            cout << "   |    " << endl;
        }
    }

    cout << "    " << endl << endl;

}

void Game::findWhiteKingPos(BOARD board) {
    for(int i=0; i<8; i++)
        for(int j=0; j<8; j++)
            if(board.getPieceType(i, j) == 'K')
            {
                whiteKingPos[0] = i;
                whiteKingPos[1] = j;
            }
}

void Game::findBlackKingPos(BOARD board) {
    for(int i=0; i<8; i++)
        for(int j=0; j<8; j++)
            if(board.getPieceType(i, j) == 'k')
            {
                blackKingPos[0] = i;
                blackKingPos[1] = j;
            }
}

int Game::getWhiteKingPosY() {
    return whiteKingPos[0];
}

int Game::getWhiteKingPosX() {
    return whiteKingPos[1];
}

int Game::getBlackKingPosY() {
    return blackKingPos[0];
}

int Game::getBlackKingPosX() {
    return blackKingPos[1];
}

bool Game::isThreated(int playerId, BOARD board, int posY, int posX) {
    // έπρεπε να χρησιμοποιήσω την συνάρτηση checkMove() αλλά δεν ξέρω πως!

    return false;
}

bool Game::isGameOver(int playerId, BOARD board) {
    bool cantMove = false;
   int y, x;

   if(playerId == 2)
   {
       y = getBlackKingPosY();
       x = getBlackKingPosX();
       cantMove = board.isBoxEmpty(y, x);

       if(isThreated(2, board, y, x) && cantMove)
           cout << "Checkmate νίκησε ο παίχτης 1!" << endl;
   }
   else if(playerId == 1)
   {
       y = getWhiteKingPosY();
       x = getWhiteKingPosX();
       cantMove = board.isBoxEmpty(y, x);

       if(isThreated(1, board, y, x) && cantMove)
           cout << "Checkmate νίκησε ο παίχτης 2!" << endl;
   }

    return false;
}

