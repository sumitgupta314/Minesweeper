#include "Cell.h"

using namespace std;

Cell::Cell(){

}

Cell::Cell(cell_type type, int cell_num){
    this->type = type;
    this->num = cell_num;
}

void Cell::set_type(cell_type type){
    this->type = type;
}

cell_type Cell::get_type(){
    return this->type;
}

void Cell::set_reveal(bool reveal){
    this->revealed = reveal;
}
bool Cell::is_revealed(){
    return this->revealed;
}
void Cell::set_flag(bool flag){
    this->flagged = flag;
}
bool Cell::get_flag(){
    return this->flagged;
}
void Cell::set_num(int num){
    this->num = num;
}
int Cell::get_num(){
    return this->num;
}

void Cell::set_coords(int row, int col){
    this->row = row;
    this->col = col;
}

int Cell::get_row(){
    return this->row;
}

int Cell::get_col(){
    return this->col;
}