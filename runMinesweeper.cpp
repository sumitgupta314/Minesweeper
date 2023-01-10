#include <iostream>
#include "Game.h"

using namespace std;

int main(){
    string input;
    Game game;
    game.display_board();
    while(game.is_game_running() && !game.game_won()){
        //cin >> input;
        getline(cin, input);
        game.user_commands(input);
    }
    if(game.game_won()){
        cout << "Congratulations! You won!" << endl;
    }else{
        cout << "You revealed a mine. You lost." << endl;
    }

    return 0;
}