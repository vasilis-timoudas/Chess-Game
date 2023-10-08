#include <iostream>

using namespace std;

#include "game.h"


int main()
{
    char option;
    Game game;

    cout << "Εργασία Εξαμήνου ΣΚΑΚΙ" << endl << "ΑΜ: 171066" << endl << "Ονοματεπώνυμο: Βασίλης Τιμούδας" << endl;

    game.startNewGame();

    cout << "Θέλετε να ξαναεπαναληφθεί η παρτίδα σας? [Y/N]: ";
    cin >> option;

    if(option == 'Y')
        game.repeatGame();

    return 0;
}
