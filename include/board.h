#ifndef SUDOKU_BOARD_H
#define SUDOKU_BOARD_H
#include <vector>


namespace sudoku{

class Board{
public:
    Board();
    ~Board()=default;

    void set_number(int row, int col, int num);
    int get_number(int row, int col);
    int get_number(int sub, int row, int col);
    bool get_isFixed(int row, int col);

    

    bool isRowComplete(int row);
    bool isColComplete(int col);
    bool isSubSquareComplete(int subsquare);

    bool isValid(int row, int col, int num);

    void initialize(int level);

    std::vector<int> get_shuffled_numbers();
    bool solve();
    void remove_numbers(int nums_to_remove);


private:
    const int Nrows = 9;
    const int Ncols = 9;
    const int NSubSquare = Nrows;
    const int total_size = Nrows*Ncols;
    std::vector<int> board;
    std::vector<bool> isFixed;

};

}; //namespace sudoku


#endif