#include "Board.h"
#include <iostream>
#include <stdlib.h>
#include <queue>

Board::Board(){
    game_over = false;
    flagged_cells = 0;
    //initialize each slot in board to null.
    for(int r = 0; r < HEIGHT; r++){
        for(int c = 0; c < WIDTH; c++){
            board[r][c] = nullptr;
        }
    }
    //get 10 random points on 9x9 board - numbers from 0 to 80 on board.
    while(mine_locations.size() < 10){
        mine_locations.insert(rand() % 81);
    }
    //assign a mine cell to each of those 10 points on the board.
    //at each mine cell, add a number cell around it if it's not already there and set it to 1.
    //if a number cell is already there, then increment its number by 1.
    int row, col;
    for(int location : mine_locations){
        row = location/WIDTH;
        col = location%WIDTH;
        board[row][col] = new Cell(mine, 0);
        board[row][col]->set_coords(row, col);
    }
    for(int location : mine_locations){
        row = location/WIDTH;
        col = location%WIDTH;
        for(int r=row-1; r<=row+1; r++){
            for(int c=col-1; c<=col+1; c++){
                if((r>=0 && r<=HEIGHT-1) && (c>=0 && c<=WIDTH-1) && (r!=row && c!=col)){
                    if(board[r][c] == nullptr){
                        board[r][c] = new Cell(number, 1);
                        board[r][c]->set_coords(r, c);
                    }else if(board[r][c]->get_type() == number){
                        board[r][c]->set_num(board[r][c]->get_num()+1);
                    }else{}
                }
            }
        }
    }

    //for all null slots, have it point to Cell of empty type.
    for(int r = 0; r < HEIGHT; r++){
        for(int c=0; c < WIDTH; c++){
            if(board[r][c] == nullptr){
                board[r][c] = new Cell(empty, -1);
                board[r][c]->set_coords(r, c);
            }
        }
    }

}
Board::~Board(){
    for(int r = 0; r < HEIGHT; r++){
        for(int c=0; c < WIDTH; c++){
            delete board[r][c];
        }
    }
}
// void Board::New_Game(){}

Cell** Board::get_board(){
    return &board[0][0];
}

void Board::flag_cell_toggle(int row, int col){
    if(board[row][col]->is_revealed() == false){
        if(board[row][col]->get_flag() == false){
            board[row][col]->set_flag(true);
            flagged_cells += 1;
        }else{
            board[row][col]->set_flag(false);
            flagged_cells -= 1;
        }
    }
}

void Board::reveal_cell(int row, int col){
    if(board[row][col]->is_revealed() == false &&
       board[row][col]->get_flag() == false){
        // 3 conditions: cell type number, empty, or mine
        if(board[row][col]->get_type() == number){
            board[row][col]->set_reveal(true);
        }
        //if mine is revealed, game over.
        //also reveal all other mine cells.
        if(board[row][col]->get_type() == mine){
            board[row][col]->set_reveal(true);
            game_over = true;
            int row, col;
            for(auto location : mine_locations){
                row = location/WIDTH;
                col = location%WIDTH;
                board[row][col]->set_reveal(true);
            }
        }
        if(board[row][col]->get_type() == empty){
            //use graph bfs to find all paths to empty type cells.
            //if it comes across an adjacent number type cell, reveal that too, but
            //don't add the number cell to queue.
            std::queue<Cell> cell_queue;
            board[row][col]->set_reveal(true);
            cell_queue.push(*board[row][col]);//check: creates a shallow copy of that cell.
            Cell cell;
            while(!cell_queue.empty()){
                cell = cell_queue.front();
                cell_queue.pop();
                for(int r = cell.get_row()-1; r <= cell.get_row()+1; r++){
                    for(int c = cell.get_col()-1; c <= cell.get_col()+1; c++){
                        if((r>0 && r<HEIGHT) && (c>0 && c<WIDTH) &&
                            r != cell.get_row() && c != cell.get_col()){
                            if(board[r][c]->get_type() == number && board[r][c]->is_revealed() == false){
                                board[r][c]->set_reveal(true);
                            }
                            if(board[r][c]->get_type() == empty && board[r][c]->is_revealed() == false){
                                board[r][c]->set_reveal(true);
                                cell_queue.push(*board[r][c]);
                            }
                        }
                        
                    }
                }
            }


        }
    }

}

int Board::get_num_flagged_cells(){
    return this->flagged_cells;
}

bool Board::is_game_over(){
    return this->game_over;
}

void Board::display_board(){
    for(int r = 0; r < HEIGHT; r++){
        for(int c = 0; c < WIDTH; c++){
            if(board[r][c]->is_revealed() == false){
                if(board[r][c]->get_flag() == false){
                    std::cout << '*';
                }else{
                    std::cout << 'f';
                }
            }else{
                if(board[r][c]->get_type() == number){
                    std::cout << board[r][c]->get_num();
                }
                if(board[r][c]->get_type() == empty){
                    std::cout << '_';
                }
                if(board[r][c]->get_type() == mine){
                    std::cout << 'x'; 
                }
            }
            
        }
        std::cout << "\n";
    }
}


