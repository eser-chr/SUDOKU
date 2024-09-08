#ifndef SUDOKU_H
#define SUDOKU_H


#include <chrono>
#include "gui.h"
#include "board.h"

namespace sudoku{
class Game{

    public:
        void set_gui_manager();
        void main();

    private:
        std::chrono::time_point<std::chrono::steady_clock> start;
        std::chrono::time_point<std::chrono::steady_clock> end;
        std::chrono::duration<double> calc_total_time();
        GUIManager* gui_manager;
        Board board;
};

};


#endif