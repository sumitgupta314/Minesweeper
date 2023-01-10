#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include <iostream>

using namespace std;

class Game {

public:
    Game();
    ~Game();
    //commands include:
    //  new game
    //  display board
    //  reveal cell <row# col#>
    //  toggle flag <row# col#>
    void user_commands(string command);

    //display board by printing it in console
    void display_board();
    
    bool is_game_running();
    bool game_won();

private:
    Board* board;
};

#endif