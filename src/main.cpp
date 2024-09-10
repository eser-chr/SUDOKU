#include "sudoku.h"
#include "board.h"
#include "gui.h"

int main(int argc, char* argv) {
    // sudoku::Game game{};
    // game.main();
    sudoku::CLI cli;
    sudoku::Board board;
    board.initialize(1);

    cli.display(board);
}