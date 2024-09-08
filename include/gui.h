#ifndef SUDOKU_GUI_H
#define SUDOKU_GUI_H
#include "board.h"
namespace sudoku {

    class GUIManager {
    public:
        virtual ~GUIManager() = default; // Virtual destructor for base class

        virtual void display(Board &board) = 0;            // Pure virtual method
        virtual void translate_command() = 0;  // Pure virtual method
    };

    class CLI : public GUIManager { // Correct syntax for public inheritance
    public:
        void display(Board &board) override;            // Override base class method
        void translate_command() override;  // Override base class method
    };

} // namespace sudoku

#endif // SUDOKU_GUI_H