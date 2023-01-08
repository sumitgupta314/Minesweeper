#include "Game.h"
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

Game::Game(){
    board = new Board();
}

Game::~Game(){
    delete board;
}

//commands include:
    //  help
    //  new game
    //  display board
    //  reveal cell <row# col#>
    //  toggle flag <row# col#>
// if command is invalid, print invalid command.
void Game::user_commands(string command){
    if(command == "new game"){
        delete board;
        board = new Board();
        board->display_board();
        return;
    }
    if(command == "display board"){
        board->display_board();
        return;
    }
    if(command == "help"){
        cout << "commands include:\n";
        cout << "   new game\n";
        cout << "   display board\n";
        cout << "   reveal cell <row#, col#>\n";
        cout << "   toggle flag <row#, col#>\n";
    }
    stringstream str_command(command);
    vector<string> args;
    string arg;
    while(str_command >> arg){
        args.push_back(arg);
    }
    int r;
    int c;
    if(args.size() == 4 && args[0] == "reveal" && args[1] == "cell" && args[2].size() == 1 && args[3].size() == 1){
        int r = stoi(args[2]);
        int c = stoi(args[3]);
        if(r < 0 || r >= HEIGHT || c < 0 || c >= WIDTH){
            cout << "Please enter coords within bounds" << endl;
            return;
        }else{
            board->reveal_cell(r, c);
            board->display_board();
        }
    }else if (args.size() == 4 && args[0] == "toggle" && args[1] == "flag" && args[2].size() == 1 && args[3].size() == 1){
        int r = stoi(args[2]);
        int c = stoi(args[3]);
        if(r < 0 || r >= HEIGHT || c < 0 || c >= WIDTH){
            cout << "Please enter coords within bounds" << endl;
            return;
        }else{
            board->flag_cell_toggle(r, c);
            board->display_board();
        }
    }else{
        cout << "Please enter a valid command. Type 'help' for options" << endl;
    }

}

bool Game::is_game_running(){
    return !board->is_game_over();
}