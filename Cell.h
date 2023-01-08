#ifndef CELL_H
#define CELL_H

enum cell_type {number, empty, mine};

class Cell {
public:
    Cell();
    Cell(cell_type type, int cell_num);
    //Operator overloading (+, -)
    //Copy assignment operator
    //Copy constructor
    //Destructor
    void set_type(cell_type type);
    cell_type get_type();
    void set_reveal(bool reveal);
    bool is_revealed();
    void set_flag(bool flag);
    bool get_flag();
    void set_num(int num);
    int get_num();
    void set_coords(int row, int col);
    //std::pair<int,int> get_coords();
    int get_row();
    int get_col();

private:
    cell_type type;
    bool revealed;
    bool flagged;
    int num;
    int row;
    int col;
};

#endif