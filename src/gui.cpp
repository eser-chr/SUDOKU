#include "gui.h"
#include <iostream>
#include <string>
#include <unordered_map>


namespace ANSI{

    const std::unordered_map<std::string, std::string> colors = {
        {"reset", "\033[0m"},
        {"bold", "\033[1m"},
        {"black", "\033[30m"},
        {"red", "\033[31m"},
        {"green", "\033[32m"},
        {"yellow", "\033[33m"},
        {"blue", "\033[34m"},
        {"magenta", "\033[35m"},
        {"cyan", "\033[36m"},
        {"white", "\033[37m"},
        {"bg_black", "\033[40m"},
        {"bg_red", "\033[41m"},
        {"bg_green", "\033[42m"},
        {"bg_yellow", "\033[43m"},
        {"bg_blue", "\033[44m"},
        {"bg_magenta", "\033[45m"},
        {"bg_cyan", "\033[46m"},
        {"bg_white", "\033[47m"}
    };

    std::string get_code(const std::string& color) {
        auto it = colors.find(color);
        if (it != colors.end()) {
            return it->second;
        }
        return ""; // Return an empty string if the color is not found
    }

    void print(const std::string& color, const std::string & text){
        std::cout<< get_code(color);
        std::cout<< text;
        std::cout<< get_code("reset");
    }
    
    void print(const std::string& color, const int & num){
        std::cout<< get_code(color);
        std::cout<< num;
        std::cout<< get_code("reset");
    }

}



void sudoku::CLI::display(Board& board) {
    for (size_t row = 0; row < 9; row++) {
        for (size_t col = 0; col < 9; col++) {
            std::cout<<' ';
            if (board.get_isFixed(row, col)){
                ANSI::print("red", board.get_number(row, col) );
            }else{
                std::cout<<board.get_number(row, col);
            }



            if (col%3==2 && col<8){
                std::cout<<" |";
            }
        }
        std::cout<<"\n";
        if (row%3==2 && row<8){
            for(int i=0; i<22; i++)
                std::cout<<"-";
            std::cout<<"\n";
        }
    }
    std::cout<<std::endl;
}

void sudoku::CLI::translate_command(){
    std::cout<<"foo "<<std::endl;
}