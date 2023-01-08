#include <iostream>
#include "Game.h"

using namespace std;

int main(){
    string input = "";
    Game game;
    while(game.is_game_running() == true){
        game.user_commands(input);
        cin >> input;
    }

    return 0;
}