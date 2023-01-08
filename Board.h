#ifndef BOARD_H
#define BOARD_H

#include "Cell.h"
#include <unordered_set>

#define WIDTH 9
#define HEIGHT 9

class Board {
public:
    Board();
    ~Board();
    //void New_Game();
    Cell** get_board();
    void flag_cell_toggle(int row, int col);
    void reveal_cell(int row, int col);
    int get_num_flagged_cells();
    bool is_game_over();
    void display_board();

private:
    int flagged_cells;
    std::unordered_set<int> mine_locations;
    Cell* board[WIDTH][HEIGHT];
    bool game_over;

};

#endif