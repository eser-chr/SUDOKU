#include "board.h"
#include <iostream>
#include <algorithm>
#include <stdexcept>

sudoku::Board::Board() : board(total_size, 0), isFixed(total_size, false) {}

void sudoku::Board::set_number(int row, int col, int num){
    board[row * Ncols + col] = num;
}

int sudoku::Board::get_number(int row, int col){
    return board[row * Ncols + col];
}

int sudoku::Board::get_number(int sub, int row, int col){
    int startRow = (sub / 3) * 3;
    int startCol = (sub % 3) * 3;
    return board[(startRow + row) * Ncols + (startCol + col)];
}

bool sudoku::Board::get_isFixed(int row, int col){
    return isFixed[row * Ncols + col];
}

bool sudoku::Board::isRowComplete(int row){
    std::vector<bool> temp(Ncols + 1, false); // We add plus 1 bcs

    for (int i = 0; i < Ncols; i++)
    {
        temp[get_number(row, i)] = true; // get_number can return 0
    }
    // we dont incl here
    return std::all_of(temp.begin() + 1, temp.end(), [](bool b)
        { return b; });
}

bool sudoku::Board::isColComplete(int col){

    std::vector<bool> temp(Nrows + 1, false);

    for (int i = 0; i < Nrows; i++)
    {
        temp[get_number(i, col)] = true;
    }

    return std::all_of(temp.begin() + 1, temp.end(), [](bool b)
        { return b; });
}

bool sudoku::Board::isValid(int row, int col, int num){
    int subSquare = (row / 3) * 3 + col / 3;
    for (int i = 0; i < 9; i++)
    {
        if (get_number(i, col) == num ||
            get_number(row, i) == num ||
            get_number(subSquare, row % 3, col % 3) == num)
        {
            return false;
        }
    }
    return true;
}

bool sudoku::Board::isSubSquareComplete(int subsquare){
    std::vector<bool> temp(NSubSquare, false);

    for (int i = 0; i < NSubSquare; i++)
    {
        temp[get_number(subsquare, i / 3, i % 3)] = true;
    }
    return std::all_of(temp.begin(), temp.end(), [](bool b)
        { return b; });
}

std::vector<int> sudoku::Board::get_shuffled_numbers(){
    std::vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::random_shuffle(numbers.begin(), numbers.end());
    return numbers;
}

bool sudoku::Board::solve(){
    for (int row = 0; row < Ncols; row++)
    {
        for (int col = 0; col < Nrows; col++)
        {
            if (get_number(row, col) == 0)
            {
                std::vector<int> numbers = get_shuffled_numbers();
                for (int num : numbers)
                {
                    if (isValid(row, col, num))
                    {
                        set_number(row, col, num);
                        if (solve())
                        {
                            return true;
                        }
                        set_number(row, col, 0);
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void sudoku::Board::remove_numbers(int nums_to_remove){
    int removed = 0;
    while (removed < nums_to_remove)
    {
        int row = rand() % 9;
        int col = rand() % 9;
        if (get_number(row, col) != 0)
        {
            set_number(row, col, 0); // Remove the number
            removed++;
        }
    }
}
void sudoku::Board::initialize(int level){
    if (level < 0 || level > 3)
    {
        throw std::out_of_range("Level can be an integer between 0-2 (incl.)");
    }
    int nums_to_remove = 30 + level * 10;

    if (solve())
    {
        remove_numbers(nums_to_remove);
    }

    for(int i=0; i<81; i++){
        isFixed[i] = board[i]!=0;
    }
    std::cout << "OK" << std::endl;
}